#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "initialize_graph.h"
#include "draw.h"
#include "constants.h"
#include "algo_path.h"


int main(){
    pair<int**,pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> initialize_result=initialize_graph(0);
    int ** Graph= initialize_result.first;
    int M=initialize_result.second.first.first;
    int N=initialize_result.second.first.second;
    pair<int,int> start_point=initialize_result.second.second.first;
    pair<int,int> destination_point= initialize_result.second.second.second;

    auto result= get_path(Graph,M,N,start_point,destination_point, 2);
    vector<pair<int,int>> path=result.first;
    map<pair<int, int>, int> value = result.second.first;
    map<pair<int, int>, bool> closed = result.second.second;
    if(!path.empty()){
        draw_path(Graph,M,N,path,closed,true,false);
    }

    result= get_path(Graph,M,N,start_point,destination_point, 1);
    path=result.first;
    value = result.second.first;
    closed = result.second.second;
    if(!path.empty()){
        draw_path(Graph,M,N,path,closed,true,true);
    }

    drawMatrix(Graph,M,N,value, false);
    return 0;
}












//https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text