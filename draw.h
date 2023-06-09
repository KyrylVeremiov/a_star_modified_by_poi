#include "constants.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <map>

using namespace std;

#pragma once
void print_description(){
    cout<< "Designations for cells: \n";
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, COLOR_EMPTY);
    cout<<PRINTING_CHAR<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -empty; ";

    SetConsoleTextAttribute(hConsole, COLOR_POI);
    cout<<CODE_POI<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -point of interest; ";

    SetConsoleTextAttribute(hConsole, COLOR_BARRIER);
    cout<<PRINTING_CHAR<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -barrier; ";

    SetConsoleTextAttribute(hConsole, COLOR_START);
    cout<<"S"<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -start; ";

    cout<<endl;

    SetConsoleTextAttribute(hConsole, COLOR_DESTINATION);
    cout<<"D"<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -destination; ";

    SetConsoleTextAttribute(hConsole, COLOR_PATH);
    cout<<PRINTING_CHAR<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -interesting path; ";

    SetConsoleTextAttribute(hConsole, COLOR_SECOND_PATH);
    cout<<PRINTING_CHAR<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -fast path; ";

    SetConsoleTextAttribute(hConsole, COLOR_VIEWED);
    cout<<PRINTING_CHAR<<PRINTING_CHAR;
    SetConsoleTextAttribute(hConsole, COLOR_STANDARD);
    cout<<" -viewed cell; ";

    cout<<endl;
}
void drawMatrix(int** A,int M, int N, const map<pair<int,int>,double>& value,bool print_value){
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
                    cout<<A[i][j]<< PRINTING_CHAR;
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
                        cout<<(int)(pr);
                        if(std::to_string(pr).length()<=1){
                            cout<<PRINTING_CHAR;
                        }
                    }
                    else{
                        if(A[i][j]>=CODE_POI){
                            cout<<A[i][j];
                            if(std::to_string(A[i][j]).length()<=1){
                                cout<<PRINTING_CHAR;
                            }
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
