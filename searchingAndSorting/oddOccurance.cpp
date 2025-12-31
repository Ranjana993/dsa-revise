#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int>&arr){
  int start = 0 , end = arr.size()-1;

  while(start <= end){
    int mid = start+(end-start)/2;
    if(start == end){
      return start;
    }
    if(mid%2 == 0){
      if(arr[mid] == arr[mid+1]){
        start = mid+1;
      }
      else{
        end = mid;
      }
    }
    else{
      if(arr[mid] == arr[mid-1]){
        start = mid+1;
      }
      else{
        end = mid-1;
      }
    }
  }
  return -1;
}

int main() {
  vector<int>arr{1,1,2,2,3,3,600,600,4,4,3};
  int res = solve(arr);
  cout <<"The res : "<< arr[res];
  return 0;
}