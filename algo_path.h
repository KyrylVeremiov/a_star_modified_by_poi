#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include "kernel.h"

#pragma once

double** matrix_sum(double **A, double **B,int M,int N);
vector<pair<int,int>>  reconstruct_path(pair<int, int> start, pair<int, int> destination,map <pair<int,int>,pair<int,int>> previous){
    vector<pair<int,int>> path;
    pair<int,int> current=previous[destination];
    while (current != start){
        path.push_back(current);
        current=previous[current];
    }
    std::reverse(path.begin(),path.end());
    return path;
}

double** multiply_matrix(double** A, int M, int N, double a){
    double **C= new double*[M];

    for (int i = 0; i < M; ++i) {
        C[i]=new double[N];
        for (int j = 0; j < N; ++j) {
            C[i][j]=A[i][j]*a;
        }
    }
    return C;
}

double manhattan_metric(pair<int,int> x, pair<int,int> y){
    return abs(x.first-y.first)+abs(x.second-y.second);
}

double euclidean_metric(pair<int,int> x, pair<int,int> y){
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
double zero_f(pair<int,int> x, pair<int,int> y){
    return 0;
}

double** copy_matrix(int** G,int M, int N){
    double** A=new double*[M];

    for (int i = 0; i < M; ++i) {
        A[i]=new double[N];
        for (int j = 0; j < N; ++j) {
            A[i][j]=G[i][j];
        }
    }
    return A;
}

/**
                  option_algo==0 ->Dijkstra
                  option_algo==0 ->A*
                option_algo==0 ->A* considering POI

                option_kernel==0 -> no kernel
                option_kernel==1 -> using kernel

                option_int==0 -> use double type for value, open
                option_int==1 -> use int for value, open
**/
pair<vector<pair<int,int>>,pair<map<pair<int,int>,double>,map<pair<int,int>,bool>>>
        get_path(int** G,vector<pair<int,int>> POIs,int M,int N,pair<int,int> start,pair<int,int> destination,
                 int  option_algo,int option_kernel, int option_int){
    double (*h) (pair<int,int> , pair<int,int> );//where value- floor
    h= &euclidean_metric;
    //    h= &manhattan_metric;

    if(option_algo == 0){
        h=&zero_f;
    }

    double (*dist) (pair<int,int> , pair<int,int> );
//    dist= &manhattan_metric;
    dist= &euclidean_metric;

    double** A=copy_matrix(G,M,N);

    double** filter= new double* [M];
    if(option_kernel==1){
        for (int i = 0; i < M; ++i) {
            filter[i]=new double[N];
            for (int j = 0; j < N; ++j) {
                filter[i][j]=0;
            }
        }
        for(pair<int,int> p: POIs){
            double** kernel=get_gaussian_kernel(p,SIGMA,M,N);
            double** kernel_scaled=multiply_matrix(kernel,M,N,A[p.first][p.second]);
            filter= matrix_sum(filter,kernel_scaled,M,N);
        }

    //print filter
//    print_kernel(filter,M,N);
    }


    if(option_kernel==1&& option_algo==1){
        for(int i=0; i<M;i++){
            for (int j = 0; j < N; ++j) {
                if(A[i][j]==CODE_EMPTY||A[i][j]==CODE_POI){
                    A[i][j]-=filter[i][j]*FILTER_WEIGHT;
                }
            }
        }
    }

    map<pair<int,int>,bool> closed;
    multimap<double,pair<int,int>> opened;
    map <pair<int,int>,double> g;
    map <pair<int,int>,double> value; //==f(x)=g(x)+h(x), cost from start + heuristic // open set
    map <pair<int,int>,pair<int,int>> previous;


    g[start]=0;
    value[start]=g[start] + h(start,destination);
    opened.insert({value[start],start});

    while (!opened.empty()){
//        drawMatrix(A,N,M);
        auto x_pointer=opened.begin();
        pair <int,int> x=x_pointer->second;
        if (x==destination){
            return {reconstruct_path(start,destination,previous),{value,closed}};
        }
        else{
            opened.erase(x_pointer);
            closed[x]=true;

            int i=x.first, j=x.second;
            set <pair<int,int>> neighbors;

            if(i>0 && A[i-1][j]!=CODE_BARRIER){
                neighbors.insert({i-1,j});
//                if(j>0){
//                    neighbors.insert({i-1,j-1});
//                }
//                if(j<N-1){
//                    neighbors.insert({i-1,j+1});
//                }
            }
            if(i<M-1 && A[i+1][j]!=CODE_BARRIER){
                neighbors.insert({i+1,j});
//                if(j>0){
//                    neighbors.insert({i+1,j-1});
//                }
//                if(j<N-1){
//                    neighbors.insert({i+1,j+1});
//                }
            }
            if(j<N-1 && A[i][j+1]!=CODE_BARRIER){
                neighbors.insert({i,j+1});
            }
            if(j>0 && A[i][j-1]!=CODE_BARRIER){
                neighbors.insert({i,j-1});
            }

            for(pair<int,int> n : neighbors){
                if(!closed[n]){
                    //TODO add interesting. How much on this
                    double n_g=g[x]+DIST_WEIGHT*dist(n,x);

                    if(option_algo == 2){// A* considering POI
                        if(A[n.first][n.second] >= CODE_POI){
                            n_g-=POI_WEIGHT*A[n.first][n.second];
                        }
                        if(option_kernel==1){
                            n_g-=FILTER_WEIGHT*filter[n.first][n.second];
                        }
                    }
                    if(g.find(n)==g.end() ||n_g<g[n]){
                        ///CAN BE FOR RETURNING BACK AFTER VISITING A POI
//                        closed[n]= false;

                        previous[n]=x;
                        if(option_int==0){
                            g[n]=(int)n_g;
                            value[n]=floor(n_g+H_WEIGHT*h(n,destination));
                            opened.insert({value[n],n});
                        }
                        else if(option_int==1){
                            g[n]=n_g;
                            value[n]=n_g+H_WEIGHT*h(n,destination);
                            opened.insert({value[n],n});
                        }
                    }
                }
            }

        }
    }

    return  {vector<pair<int,int>>(),{value,closed}};
}

double ** matrix_sum(double **A, double **B,int M, int N) {
    double **C= new double*[M];
    for (int i = 0; i < M; ++i) {
        C[i]=new double[N];
        for (int j = 0; j < N; ++j) {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return C;
}
