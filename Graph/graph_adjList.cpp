/*
AIM:              Implementing graphs in C++
Approach :        construction of graphs in C++ is quite simpleby using vector
                  As it is very simple to create dynamic list in C++ using vector
*/

#include<iostream>
#include<vector>
using namespace std;

void add_vertices(vector<long> vertex_list[], long source, long destination){
  vertex_list[source].push_back(destination);
  vertex_list[destination].push_back(source);
  return ;
}

void print_graph(vector<long> graph[]){
  long no_of_vertices = graph[1].size();
  for(int i=0; i < no_of_vertices; i++){
    cout<<"["<<i<<"]";
    for(int j = 0; j< graph[i].size(); j++){
      cout<<"--> ("<<graph[i][j]<<")";
    }
    cout<<"\n";
  }
  return;
}

int main(){
  int number_of_vertices = 6;
  vector<long> graph[number_of_vertices];
  add_vertices(graph, 0,1);
  add_vertices(graph, 0,4);
  add_vertices(graph, 1,4);
  add_vertices(graph, 1,2);
  add_vertices(graph, 1,3);
  add_vertices(graph, 2,3);
  add_vertices(graph, 3,4);
  print_graph(graph);
  return 0;
}
