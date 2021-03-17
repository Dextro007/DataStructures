#include<iostream>
#include<list>
using namespace std;

class Graph{
  unsigned long V;
  list<long> *adjacency_list;
public:
  Graph(unsigned long Vertices);
};
