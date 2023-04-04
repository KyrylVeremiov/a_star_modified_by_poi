#include <set>
#include <map>
#include <vector>
#include <algorithm>

#pragma once
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

int manhattan_metric(pair<int,int> x, pair<int,int> y){
    return abs(x.first-y.first)+abs(x.second-y.second);
}

pair<vector<pair<int,int>>,pair<map<pair<int,int>,int>,map<pair<int,int>,bool>>>  get_path(int** A,int M,int N,pair<int,int> start,pair<int,int> destination, int  option){
    int (*h) (pair<int,int> , pair<int,int> );
    h= &manhattan_metric;
    int (*dist) (pair<int,int> , pair<int,int> );
    dist= &manhattan_metric;

    map<pair<int,int>,bool> closed;
    multimap<int,pair<int,int>> opened;
    map <pair<int,int>,int> g;
    map <pair<int,int>,int> value; //==f(x)=g(x)+h(x), cost from start + heuristic // open set
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
                    int n_g=g[x]+dist(n,x);
                    if(g[n]==0){
                        if(option==0){//Dijkstra
                            opened.insert({n_g,n});
                            previous[n]=x;
                            g[n]=n_g;
                            value[n]=n_g+h(n,destination);
                        }
                        else if(option==1){//A*
                            previous[n]=x;
                            g[n]=n_g;
                            value[n]=n_g+h(n,destination);
                            opened.insert({value[n],n});
                        }
                        else if(option==2){// A* considering POI
                            previous[n]=x;
                            if(A[n.first][n.second]>=CODE_POI){
                                n_g-=POI_WEIGHT*A[n.first][n.second];
                            }
                            g[n]=n_g;
                            value[n]=n_g+h(n,destination);
                            opened.insert({value[n],n});
                        }
                    }
                    else{
                        if(g[n]<n_g){
                            previous[n]=x;
                            g[n]=n_g;
                            value[n]=n_g+h(n,destination);
                        }
                    }
                }
            }

        }
    }

    return  {vector<pair<int,int>>(),{value,closed}};
}