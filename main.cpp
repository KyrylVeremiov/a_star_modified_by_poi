#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "initialize_graph.h"
#include "draw.h"
#include "constants.h"
#include "algo_path.h"

int main(){
    print_description();
    pair<int**,pair<pair<int,int>,pair<pair<int,int>,pair<int,int>>>> initialize_result=initialize_graph(1);
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

    auto second_result= get_path(Graph,M,N,start_point,destination_point, 1);
    vector<pair<int,int>> second_path=second_result.first;
    map<pair<int, int>, int> second_value = second_result.second.first;
    map<pair<int, int>, bool> second_closed = second_result.second.second;

    if(!path.empty()){
        draw_path(Graph,M,N,second_path,second_closed,false,true);
    }

//    drawMatrix(Graph,M,N,second_value, false);
    drawMatrix(Graph,M,N,value, false);
    return 0;
}












//https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text
//https://ru.wikibooks.org/wiki/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0_A*
