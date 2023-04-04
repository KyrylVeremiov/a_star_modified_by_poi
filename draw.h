#include "constants.h"
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

#pragma once
void drawMatrix(int** A,int M, int N){
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//    int k;
//    // you can loop k higher to see more color choices
//    for(k = 1; k < 500; k++)
//    {
//        // pick the colorattribute k you want
//        SetConsoleTextAttribute(hConsole, k);
//        cout << k << " I want to be nice today!" << endl;
//    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            bool def=true;
            if(A[i][j] == CODE_EMPTY){
                SetConsoleTextAttribute(hConsole, COLOR_EMPTY);
            }
            else if(A[i][j] >= CODE_POI){
                SetConsoleTextAttribute(hConsole, COLOR_POI);
                cout<<A[i][j];
                def=false;
            }
            else if(A[i][j] == CODE_BARRIER){
                SetConsoleTextAttribute(hConsole, COLOR_BARRIER);
            }
            else if(A[i][j]==CODE_START){
                SetConsoleTextAttribute(hConsole, COLOR_START);
                cout<<"S"<<PRINTING_CHAR;
                def=false;
            }
            else if(A[i][j]==CODE_DESTINATION){
                SetConsoleTextAttribute(hConsole, COLOR_DESTINATION);
                cout<<"D"<<PRINTING_CHAR;
                def=false;
            }
            else if(A[i][j]==CODE_PATH){
                SetConsoleTextAttribute(hConsole, COLOR_PATH);
            }
            else if(A[i][j]==CODE_VIEWED){
                SetConsoleTextAttribute(hConsole, COLOR_VIEWED);
            }
//            cout<< A[i][j]<<0;
            if(def)
                cout<< PRINTING_CHAR<<PRINTING_CHAR;
        }
        cout<<endl;
    }
//    cin.get(); // wait
}

void draw_path(int** A,int M,int N,const vector<pair<int,int>>&path,const map<pair<int, int>, bool> &closed, bool draw_viewed){
    for(pair<int,int> n: path){
        if(A[n.first][n.second]==CODE_EMPTY) {
            A[n.first][n.second] = CODE_PATH;
        }
    }
    if(draw_viewed){
        for(auto x:closed){
            if(A[x.first.first][x.first.second]==CODE_EMPTY){
                A[x.first.first][x.first.second]=CODE_VIEWED;
            }
        }
    }
}
