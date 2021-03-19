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
  this->V = Vertices;
  adjacency_list = new list<long>[V];
}
void Graph::add_vertices(long source, long destination){
  adjacency_list[source].push_back(destination);
  adjacency_list[destination].push_back(source);
}

void Graph::bfs(long source){
  
}

int main(){

}
