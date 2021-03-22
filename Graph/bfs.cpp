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
  list<long>::iterator it;
  while(!queue.empty()){
    long currVertices = queue.front();
    cout<<currVertices<< " ";
    queue.pop_front();

    for(it = adjacency_list[currVertices].begin(); it != adjacency_list[currVertices].end(); it++){
      if(!(visited[*it])){
        visited[*it] = true;
        queue.push_back(*it);
      }
    }
  }
}

int main(){
  Graph gr(4);
  gr.add_vertices(0,1);
  gr.add_vertices(0, 2);
  gr.add_vertices(1, 2);
  gr.add_vertices(2, 0);
  gr.add_vertices(2, 3);
  gr.add_vertices(3,3);

  cout<<"BFS: ";
  gr.bfs(2);
  return 0;
}
