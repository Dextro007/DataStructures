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

int min_number_seg(int n,vector< pair<long, long>> points){
  long min_coord, max_coord;
  min_coord = points[0].first;
  max_coord = points[0].second;
  int segments = 1;
  for(int i=1; i<n; i++){
    if(points[i].first>max_coord){
      min_coord = points[i].first;
      max_coord = points[i].second;
      segments++;
    }
    else{
      max_coord = std::max(max_coord, points[i].second);
    }
  }
  return segments;
}

int main() {
  //creating vector of pairs
  vector< pair <long,long>> points;
  long arr_x1[4], arr_x2[4];
  int n= 4;
  cout<<"Enter the coordinates: ";
  for(int i = 0;i<n; i++){
    cin>>arr_x1[i]>>arr_x2[i];
  }
  for(int i=0; i<n; i++){
    points.push_back(make_pair(arr_x1[i], arr_x2[i]));
  }
  make_heap(points.begin(), points.end());
  sort_heap(points.begin(), points.end());
  //passing vactor-pairs to function
  cout<<min_number_seg(n, points);
  return 0;
}
