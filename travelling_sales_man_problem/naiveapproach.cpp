#include <bits/stdc++.h>

using namespace std;

void findMinimumWeight(int graph[][],int source,int edges){
    vector<int> vertex;
    for(int i=0;i<edges;i++){
        if(i!=source){
            vertex.push_back(i);
        }
    }
    int min_weight = INT_MAX;
    do{
        int curr_weight=0;
        int current_combination = source;
        for(int i=0; i<vertex.size();i++){
            curr_weight = 
        }
    }
}

int main(){
    int edges,source;
    cout<<"Enter the no of edges in the graph"<<endl;
    cin>>edges;
    cout<<"Enter the source value on the range 0 to"<<edges-1<<endl;
    cin>>source;
    cout<<"Enter the values for the vertices"<<endl;
    int graph[edges][edges];
    for(int i=0;i<edges;i++){
        for(int j=0;j<edges;j++){
            cin>>graph[i][j];
        }
    }
    findMinimumWeight(graph,source,edges);
}