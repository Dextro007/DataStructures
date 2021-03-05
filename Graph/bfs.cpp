#include<iostream>
#include<list>

using namespace std;
// construction of graph can change but aLGO
class Graph{
  long V;
  list<int> *adj;
public:
  Graph(long V);
  void add_vertices(long sources, long destination);
  void bfs(long start);
};

int main(){
  return 0;
}
