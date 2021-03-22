/*
Problem  : breadth for search for directed graph
Note :     this program is specifically for directed graph
*/

#include<iostream>
#include<list>
using namespace std;

class Graph{
  unsigned long V;
  list<long> *adjacency_list;
public:
  Graph(unsigned long Vertices);
  void add_vertices(long source, long destination);
  void bfs(long source);
};

Graph :: Graph(unsigned long Vertices){
  this->V = Vertices;                  // test it without using this
  adjacency_list = new list<long>[V];
}
void Graph::add_vertices(long source, long destination){
  adjacency_list[source].push_back(destination);
  // Since the code is for directed graph
  // adjacency_list[destination].push_back(source);
}

void Graph::bfs(long source){
  bool *visited =  new bool[V];
  for(unsigned long i=0; i<V; i++){
    visited[i] = false;
  }
  list<long> queue;
  visited[source] = true;
  queue.push_back(source);

}

int main(){

}
