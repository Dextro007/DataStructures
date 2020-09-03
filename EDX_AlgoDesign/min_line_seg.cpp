/*
Prblm :  You are responsible for collecting signatures from all tenants of a certain build-ing.
        For each tenant, you know a period of time when he or she is at home.You would like to collect all signatures by visiting
        the building as few times aspossible.
Mathematical model: given a setof segments on a line and your goal is to mark as few points on a line as possibleso that each segment
        contains at least one marked point

DS/algo used : array/vector
SOln: 1. sort the points acc based on 1st coordinate
      2. crawl form 1 segment to other by changing x2 coordinate
      3. IF new x1 co-ord > existing x2 coordinate THEN new segments
      4. ELSE update the x2 coordinate to biggest x2
*/

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int main() {
  vector< pair <long,long>> points;
  long arr_x1[100], arr_x2[100];
  int n= 100;
  for(int i = 0;i<n; i++){
    cin>>arr_x1[i]>>arr_x2[i];
  }
  for(int i=0; i<n; i++){
    points.push_back(make_pair(arr_x1[i], arr_x2[i]));
  }
  make_heap(points.begin(), points.end());
  sort_heap(points.begin(), points.end());
  
  return 0;
}
