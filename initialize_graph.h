#include <utility>
#include "constants.h"

#pragma once
std::pair<int **,std::pair<std::pair<int, int>, std::pair<std::pair<int, int>,std::pair<int, int>>>> initialize_graph(int option){
    int M=0;
    int N=0;

    std::pair <int,int> start_point;
    std::pair <int,int> destination_point;

    if (option==0){
        M=20;
        N=30;
    }
    else if(option==1){
        M=20;
        N=30;
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

        A[start_point.first][start_point.second]=CODE_START;
        A[destination_point.first][destination_point.second]=CODE_DESTINATION;

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
        A[15][12]=CODE_POI+9;
        A[13][9]=CODE_POI+2;
    }
    else if(option==1){

        start_point={8,6};
        destination_point={ 10,16};

        A[start_point.first][start_point.second]=CODE_START;
        A[destination_point.first][destination_point.second]=CODE_DESTINATION;

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

        A[1][15]=CODE_BARRIER;
        A[2][15]=CODE_BARRIER;
        A[3][15]=CODE_BARRIER;
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
        A[13][15]=CODE_BARRIER;
        A[13][16]=CODE_BARRIER;


        A[6][9]=CODE_POI;
        A[14][18]=CODE_POI+4;
        A[15][12]=CODE_POI+9;
        A[13][9]=CODE_POI+2;
    }
    std::pair(start_point,destination_point);
    return std::pair(A,std::pair(std::pair<int,int>(M,N),std::pair(start_point,destination_point)));
}