#include <iostream>
#include<vector>
using namespace std;

// searching array...
int searchArr(vector<int>&arr , int target){
  int start = 0 , end = arr.size()-1;
  while(start <= end){
    int mid = start + (end- start)/2;
    if(arr[mid] == target){
      return mid;
    }
    else if(target > arr[mid]){
      start = mid+1;
    }
    else{
      end = mid - 1;
    }
  }
  return -1;
}

// left most orrucarnce..
int leftOccurance(vector<int>&arr , int target){
  int start = 0 , end = arr.size()-1 , ans = -1;
  while(start <= end){
    int mid = start + (end- start)/2;
    if(arr[mid] == target){
      ans = mid;
      end = mid-1;
    }
    else if(target > arr[mid]){
      start = mid+1;
    }
    else{
      end = mid - 1;
    }
  }
  return ans;
}

// right most orrucarnce..
int rightOccurance(vector<int>&arr , int target){
  int start = 0 , end = arr.size()-1 , ans = -1;
  while(start <= end){
    int mid = start + (end- start)/2;
    if(arr[mid] == target){
      ans = mid;
      start = mid+1;
    }
    else if(target > arr[mid]){
      start = mid+1;
    }
    else{
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int>arr{1,2,3,4,5,6,6,6,7};
  int res = searchArr(arr,7);
  cout <<"The search res : "<< res <<endl;
  int left = leftOccurance(arr , 6);
  cout <<"The left most occurance res : "<< left <<endl;
  int right = rightOccurance(arr , 6);
  cout <<"The right occurance res : "<< right <<endl;

  cout <<"The total orrucance is : "<< (right-left)+1<<" ."<<endl;
  return 0;
}