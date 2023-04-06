#include <utility>
#include "constants.h"

#pragma once
using namespace std;

vector<pair<int,int>> get_POIs(int** A, int M, int N){
    vector<pair<int,int>> POIs;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if(A[i][j]>=CODE_POI){
                POIs.emplace_back(i,j);
            }
        }
    }
    return POIs;
}

pair<pair<int **,vector<pair<int,int>>>,pair<std::pair<int, int>, pair<pair<int, int>,pair<int, int>>>> initialize_graph(int option){
    int M=0;
    int N=0;

    pair <int,int> start_point;
    pair <int,int> destination_point;

    if (option==0){
        M=20;
        N=30;
    }
    else if(option==1){
        M=30;
        N=50;
    }
    else if(option==2){
        M=35;
        N=59;
    }
    int** A=new int*[M];

    for (int i = 0; i < M; ++i) {
        A[i]=new int[N];
        for (int j = 0; j < N; ++j) {
            A[i][j]=CODE_EMPTY;
        }
    }

    if(option==0){
        start_point={8,6};
        destination_point={ 10,16};

        A[7][7]=CODE_BARRIER;
        A[6][7]=CODE_BARRIER;
        A[6][6]=CODE_BARRIER;
        A[6][5]=CODE_BARRIER;

        A[7][8]=CODE_BARRIER;
        A[8][8]=CODE_BARRIER;
        A[9][8]=CODE_BARRIER;
        A[10][8]=CODE_BARRIER;
        A[11][8]=CODE_BARRIER;


        A[11][7]=CODE_BARRIER;
        A[11][6]=CODE_BARRIER;
        A[10][6]=CODE_BARRIER;
        A[10][5]=CODE_BARRIER;
        A[10][4]=CODE_BARRIER;
        A[9][4]=CODE_BARRIER;


        A[7][7]=CODE_BARRIER;
        A[6][7]=CODE_BARRIER;
        A[6][6]=CODE_BARRIER;
        A[6][5]=CODE_BARRIER;


        A[3][14]=CODE_BARRIER;
        A[4][14]=CODE_BARRIER;
        A[5][14]=CODE_BARRIER;
        A[6][14]=CODE_BARRIER;
        A[7][14]=CODE_BARRIER;
        A[8][14]=CODE_BARRIER;
        A[8][15]=CODE_BARRIER;
        A[9][15]=CODE_BARRIER;
        A[10][15]=CODE_BARRIER;
        A[11][15]=CODE_BARRIER;
        A[12][15]=CODE_BARRIER;
        A[12][16]=CODE_BARRIER;

        A[6][9]=CODE_POI;
        A[14][18]=CODE_POI+4;
        A[15][12]=CODE_POI+8;
        A[13][9]=CODE_POI+2;
    }
    else if(option==1){

        start_point={25,3};
        destination_point={ 3,47};

        A[12][27]=CODE_BARRIER;
        A[11][27]=CODE_BARRIER;
        A[11][26]=CODE_BARRIER;
        A[11][25]=CODE_BARRIER;
        A[12][28]=CODE_BARRIER;
        A[13][28]=CODE_BARRIER;
        A[14][28]=CODE_BARRIER;
        A[15][28]=CODE_BARRIER;
        A[16][28]=CODE_BARRIER;
        A[16][27]=CODE_BARRIER;
        A[16][26]=CODE_BARRIER;
        A[15][26]=CODE_BARRIER;
        A[15][25]=CODE_BARRIER;
        A[15][24]=CODE_BARRIER;
        A[14][24]=CODE_BARRIER;
        A[12][27]=CODE_BARRIER;
        A[11][27]=CODE_BARRIER;
        A[11][26]=CODE_BARRIER;
        A[11][25]=CODE_BARRIER;

        A[6][40]=CODE_BARRIER;
        A[7][40]=CODE_BARRIER;
        A[8][40]=CODE_BARRIER;
        A[8][39]=CODE_BARRIER;
        A[9][39]=CODE_BARRIER;
        A[10][39]=CODE_BARRIER;
        A[11][39]=CODE_BARRIER;
        A[12][39]=CODE_BARRIER;
        A[13][39]=CODE_BARRIER;
        A[13][40]=CODE_BARRIER;
        A[14][40]=CODE_BARRIER;
        A[15][40]=CODE_BARRIER;
        A[16][40]=CODE_BARRIER;
        A[17][40]=CODE_BARRIER;
        A[18][40]=CODE_BARRIER;
        A[18][41]=CODE_BARRIER;


        A[7][34]=CODE_BARRIER;
        A[8][34]=CODE_BARRIER;
        A[9][34]=CODE_BARRIER;
        A[10][34]=CODE_BARRIER;
        A[11][34]=CODE_BARRIER;
        A[12][34]=CODE_BARRIER;

        A[16][37]=CODE_BARRIER;
        A[17][36]=CODE_BARRIER;
        A[17][37]=CODE_BARRIER;
        A[18][37]=CODE_BARRIER;
        A[19][37]=CODE_BARRIER;
        A[20][37]=CODE_BARRIER;
        A[21][37]=CODE_BARRIER;



        A[7][37]=CODE_POI +8;
        A[14][18]=CODE_POI+4;
        A[15][12]=CODE_POI+8;
        A[13][9]=CODE_POI+2;
        A[11][30]=CODE_POI+2;
        A[25][40]=CODE_POI+8;
//        A[9][28]=CODE_POI;
        A[21][33]=CODE_POI+4;
//        A[26][25]=CODE_POI;
    }
    else if(option==2){
        start_point={33,57};
        destination_point={ 2,3};

        A[7][7]=CODE_BARRIER;

        A[1][5]=CODE_BARRIER;
        A[2][5]=CODE_BARRIER;
        A[3][5]=CODE_BARRIER;
        A[4][5]=CODE_BARRIER;
        A[5][5]=CODE_BARRIER;
        A[6][5]=CODE_BARRIER;
        A[6][6]=CODE_BARRIER;
        A[7][6]=CODE_BARRIER;
        A[8][6]=CODE_BARRIER;
        A[9][6]=CODE_BARRIER;
        A[10][6]=CODE_BARRIER;
        A[10][5]=CODE_BARRIER;
        A[10][4]=CODE_BARRIER;
        A[10][3]=CODE_BARRIER;
        A[10][2]=CODE_BARRIER;
        A[11][2]=CODE_BARRIER;

        A[6][10]=CODE_BARRIER;
        A[6][11]=CODE_BARRIER;
        A[5][11]=CODE_BARRIER;
        A[7][11]=CODE_BARRIER;

        A[12][6]=CODE_BARRIER;
        A[12][7]=CODE_BARRIER;
        A[12][8]=CODE_BARRIER;
        A[12][9]=CODE_BARRIER;
        A[13][9]=CODE_BARRIER;
        A[11][9]=CODE_BARRIER;
        A[11][10]=CODE_BARRIER;
        A[11][11]=CODE_BARRIER;
        A[11][12]=CODE_BARRIER;
        A[11][13]=CODE_BARRIER;
        A[11][14]=CODE_BARRIER;
        A[11][15]=CODE_BARRIER;
        A[11][16]=CODE_BARRIER;
        A[11][17]=CODE_BARRIER;
        A[11][18]=CODE_BARRIER;
        A[9][17]=CODE_BARRIER;
        A[10][17]=CODE_BARRIER;


        A[14][15]=CODE_BARRIER;
        A[14][16]=CODE_BARRIER;
        A[15][16]=CODE_BARRIER;
        A[15][17]=CODE_BARRIER;
        A[15][18]=CODE_BARRIER;
        A[15][19]=CODE_BARRIER;
        A[15][20]=CODE_BARRIER;
        A[15][21]=CODE_BARRIER;

        A[13][28]=CODE_BARRIER;
        A[14][28]=CODE_BARRIER;
        A[15][28]=CODE_BARRIER;
        A[15][27]=CODE_BARRIER;
        A[15][26]=CODE_BARRIER;
        A[15][25]=CODE_BARRIER;
        A[15][24]=CODE_BARRIER;
        A[16][24]=CODE_BARRIER;

        A[20][25]=CODE_BARRIER;
        A[20][26]=CODE_BARRIER;
        A[20][27]=CODE_BARRIER;
        A[19][27]=CODE_BARRIER;
        A[18][27]=CODE_BARRIER;
        A[17][27]=CODE_BARRIER;
        A[18][28]=CODE_BARRIER;
        A[18][29]=CODE_BARRIER;
        A[18][30]=CODE_BARRIER;

        A[18][22]=CODE_BARRIER;
        A[19][22]=CODE_BARRIER;
        A[20][22]=CODE_BARRIER;
        A[21][22]=CODE_BARRIER;
        A[22][22]=CODE_BARRIER;
        A[23][22]=CODE_BARRIER;
        A[23][21]=CODE_BARRIER;
        A[23][20]=CODE_BARRIER;
        A[24][20]=CODE_BARRIER;
        A[25][20]=CODE_BARRIER;
        A[26][20]=CODE_BARRIER;
        A[27][20]=CODE_BARRIER;
        A[26][19]=CODE_BARRIER;
        A[26][18]=CODE_BARRIER;
        A[26][17]=CODE_BARRIER;
        A[26][16]=CODE_BARRIER;

        A[26][38]=CODE_BARRIER;

        A[25][23]=CODE_BARRIER;
        A[26][23]=CODE_BARRIER;
        A[27][23]=CODE_BARRIER;

        A[26][27]=CODE_BARRIER;
        A[27][27]=CODE_BARRIER;
        A[28][27]=CODE_BARRIER;
        A[29][27]=CODE_BARRIER;
        A[30][27]=CODE_BARRIER;

        A[29][58]=CODE_BARRIER;
        A[29][57]=CODE_BARRIER;
        A[29][56]=CODE_BARRIER;
        A[29][55]=CODE_BARRIER;
        A[29][54]=CODE_BARRIER;
        A[30][54]=CODE_BARRIER;

        A[27][57]=CODE_BARRIER;
        A[27][56]=CODE_BARRIER;
        A[27][55]=CODE_BARRIER;
        A[27][54]=CODE_BARRIER;
        A[27][53]=CODE_BARRIER;
        A[27][52]=CODE_BARRIER;


        A[2][10]=CODE_POI+4;
        A[10][9]=CODE_POI;
        A[12][22]=CODE_POI+8;
        A[18][13]=CODE_POI+4;
        A[23][22]=CODE_POI+2;
        A[27][30]=CODE_POI+5;
        A[31][27]=CODE_POI+1;
        A[32][36]=CODE_POI+7;
        A[33][29]=CODE_POI+8;
        A[32][24]=CODE_POI+4;
    }

    vector<pair<int,int>> POIs=get_POIs(A,M,N);
    A[start_point.first][start_point.second]=CODE_START;
    A[destination_point.first][destination_point.second]=CODE_DESTINATION;
    return pair(pair(A,POIs),pair(pair<int,int>(M,N),pair(start_point,destination_point)));
}