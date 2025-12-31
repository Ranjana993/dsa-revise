#include <iostream>
#include<vector>
using namespace std;

void sortArr(vector<int>&arr){
  int start = 0 , end = arr.size()-1;
  while(start < end){
    if(arr[start] < 0){
      start++;
    }
    else if(arr[end] >= 0 ){
      end--;
    }
    else{
      swap(arr[start],arr[end]);
      start++;
      end--;
    }
  }
}

int main() {
  vector<int>arr{1,2,4,-5,6,-2 , -6 , 7};
  sortArr(arr);
  for(auto nums:arr){
    cout <<nums <<" ";
  }
  return 0;
}