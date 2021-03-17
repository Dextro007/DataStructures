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
  
}
