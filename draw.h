#include "constants.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <map>

using namespace std;

#pragma once
void print_description(){
    cout<<"DFGDFGSDFGSDFGSDFGSDFGSDFGSDFG"<<endl;
}
void drawMatrix(int** A,int M, int N, const map<pair<int,int>,int>& value,bool print_value){
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
            bool def=true;//default
            if(A[i][j] == CODE_EMPTY){
                SetConsoleTextAttribute(hConsole, COLOR_EMPTY);
            }
            else if(A[i][j] >= CODE_POI){
                SetConsoleTextAttribute(hConsole, COLOR_POI);
                if(!print_value){
                    cout<<A[i][j];
                    def=false;
                }
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
            else if(A[i][j]==CODE_SECOND_PATH){
                SetConsoleTextAttribute(hConsole, COLOR_SECOND_PATH);
            }
            else if(A[i][j]==CODE_VIEWED){
                SetConsoleTextAttribute(hConsole, COLOR_VIEWED);
            }
            if(def){
                if(print_value){
                    auto it=value.find({i,j});
                    if(it!=value.end()){
                        int pr=it->second;
                        cout<< pr;
                        if(std::to_string(pr).length()<=1){
                            cout<<PRINTING_CHAR;
                        }
                    }
                    else{
                        if(A[i][j]>=CODE_POI){
                            cout<<A[i][j]<<((std::to_string(A[i][j]).length()>1)? "":std::to_string(PRINTING_CHAR));
                        }
                        else{
                            cout<<CODE_EMPTY<<PRINTING_CHAR;
                        }
                    }
                }
                else{
                    cout<< PRINTING_CHAR<<PRINTING_CHAR;
                }
            }
        }
        cout<<endl;
    }
//    cin.get(); // wait
}

void draw_path(int** A,int M,int N,const vector<pair<int,int>>&path,const map<pair<int, int>, bool> &closed, bool draw_viewed,bool second_path){
    for(pair<int,int> n: path){
        if( A[n.first][n.second]==CODE_EMPTY||A[n.first][n.second]==CODE_VIEWED) {
            A[n.first][n.second] = (second_path?CODE_SECOND_PATH:CODE_PATH);
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
