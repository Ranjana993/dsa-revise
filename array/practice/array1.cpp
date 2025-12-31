#include <iostream>
#include<vector>
#include<climits>
using namespace std;


// ...........................ARRAYSS.......

// 01.linear search...
int linearSearch(vector<int>&arr , int target){
  for(int i = 0 ; i < arr.size() ; i++){
    if(arr[i] == target){
      return i;
    }
  }
  return -1;
}
// 02. count 0s and 1s...
void countNumber(vector<int>&arr){
  int count0 = 0 , count1 = 0;
  for(int i = 0 ; i< arr.size();i++){
    if(arr[i] == 0) count0++;
    else if(arr[i]==1)count1++;
  }
  cout<<"The number of 0s is : "<<count0 <<" and the number os 1s is : "<<count1 <<endl;
}
// 03. Min/Max element in an array...
int findMin(vector<int>&arr){
  int mini = INT_MAX;
  for(int i = 0 ; i < arr.size() ;i++){
    if(arr[i] < mini ){
      mini = arr[i];
    }
  }
  return mini;
}
int findMax(vector<int>&arr){
  int maxi = INT_MIN;
  for(int i = 0 ; i < arr.size() ; i++){
    if(arr[i] > maxi){
      maxi = arr[i];
    }
  }
  return maxi;
}
// 04.Extreme print...

void extremePrint(vector<int>&arr){
  int start = 0 , end = arr.size()-1;
  while(start <= end){
    if(arr[start] == arr[end]){
      cout << arr[end]<<"  ";
    }
    else{
      cout <<arr[start] <<" "<<arr[end] <<" ";
    }
      start++;
      end--;
  }
}

// 05. reverse array...
void reverseArr(vector<int>&arr){
  int start = 0 , end = arr.size()-1;
  while(start < end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
// 06. Find unique elements...
int findUnique(vector<int>&arr){
  int res = 0;
  for(int i = 0 ; i < arr.size() ; i++){
    res = res^arr[i];
  }

  return res;
}

// 07. union of two arrays...
void unionArr(vector<int>&arr1 , vector<int>&arr2 , vector<int>&res){
  for(auto a1:arr1) {
    res.push_back(a1);
  }
  for(auto a1:arr2) {
    res.push_back(a1);
  }
}

// 08. pair sum...
bool pairSum(vector<int>&arr , int target){
  for(int i = 0 ; i <= arr.size() ; i++){
    for(int j = i+1 ; j < arr.size() ; j++){
      if(arr[i]+arr[j] == target){
        return true;
      }
    }
  }
  return false;
}
// 09. sort 0s and 1s...
void sort01(vector<int>&arr){
  int start = 0 , end = arr.size()-1;
  while(start <= end){
    if(arr[start] == 0){
      start++;
    }
    else if(arr[end] == 1){
      end--;
    }
    else {
      swap(arr[start] , arr[end]);
      start++;
      end--;
    }
  }
}


int main() {
  // vector<int>arr{2,4,3,6,8,9,1};
  // int res = linearSearch(arr , 9);
  // cout <<"The element is : "<<res <<endl;
  // cout <<"...................................................." <<endl;
  // 
  // countNumber(arr);
  // vector<int>arr{2,4,3,6,8,9,1};
  // int res1 = findMin(arr);
  // cout <<"The min element is : "<<res1<<endl;
  // int res2 = findMax(arr);
  // cout <<"The max element is : "<<res2 <<endl;



  // vector<int>arr{10,20,30,40,50,60,70};
  // extremePrint(arr);
  // reverseArr(arr);
  // cout <<endl;
  // for(auto num:arr) {
  //   cout <<num<<" " ;
  // }



  // vector<int>arr{10,30,30,10,50,60,50};
  // int res = findUnique(arr);
  // cout <<"The result is : "<<res;


  // vector<int>arr{2,4,6,8};
  // vector<int>arr1{3,5,7};
  // vector<int>res;

  // unionArr(arr , arr1 , res);
  // for(auto n:res)
  //   cout << n<<" ";

  // vector<int>arr{10,40,50,20,90,50,90};
  // int target = 30;
  // if(pairSum(arr , target)){
  //   cout <<"The res is found"<<endl;
  // }
  // else{
  //   cout <<"The res is Not found"<<endl;
  // }


  vector<int>arr{0,0,1,1,0,1,1};
  sort01(arr);
  for(auto it:arr){
    cout << it<<" ";
  }
  return 0;
}