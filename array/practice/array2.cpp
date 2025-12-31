#include <iostream>
#include<vector>
#include<climits>
using namespace std;


// ...............2D ARRAYYYY.............

// 01. traversing....
void print(vector<vector<int> >&arr){
  int row = arr.size();
  int col = arr[0].size();

  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      cout <<arr[i][j]<<" ";
    }
    cout <<endl;
  }
}
// 02. row sum ...
void rowSum(vector<vector<int> > &arr){
  int row = arr.size();
  int col = arr[0].size();

  int sum = 0 ;
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j< col ; j++){
      sum += arr[i][j];
    }
    cout <<"the row sum is : " << sum << " . "<<endl;
    sum = 0 ;
  }
}
// 03. col sum ...
void colSum(vector<vector<int> > &arr){
  int row = arr.size() ;
  if (row == 0) return;
  int col = arr[0].size();
  int sum = 0;

  for(int i = 0 ; i < col ; i++){
    for(int j = 0 ; j < row ; j++){
      sum += arr[j][i]; 
    }
    cout <<"The col sum is : "<< sum<<" ." <<endl;
    sum = 0 ;
  }
}
// 04. find element...
bool findElement(vector<vector<int> > &arr , int target){
  int row = arr.size() ;
  int col = arr[0].size();

  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      if(arr[i][j] == target){
        return true;
      } 
    }
  }
  return false;
}

// 05. max element in array...
int findMax(vector<vector<int> > &arr){
  int row = arr.size() ;
  int col = arr[0].size();
  int maxi = INT_MIN;

  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      if(arr[i][j] > maxi){
        maxi = arr[i][j];
      } 
    }
  }
  return maxi;
}
// 06. min element in array... 
int findMin(vector<vector<int> > &arr){
  int row = arr.size();
  int col = arr[0].size();
  int mini = INT_MAX;

  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      if(arr[i][j] < mini){
        mini = arr[i][j];
      }
    }
  }
  return mini;
}
// 07. matrix transpose ...

void transposeMatrix(vector<vector<int> >&arr,vector<vector<int> >&res ){
  int row = arr.size();
  int col = arr[0].size();
  res.resize(col, vector<int>(row));

  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      res[j][i] = arr[i][j];
    }
  }
}



int main() {
  vector<vector<int> > arr{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
  };
  print(arr);
  // rowSum(arr);
  // colSum(arr)
  // findElement(arr , 9);
  // int res = findMax(arr);
  // if(res){
  //   cout <<"The max element is "<<res<<endl;
  // }
  // else{
  //   cout <<"The max element is not found ."<<endl;
  // }

    // int res = findMin(arr);
    // if(res){
    //   cout <<"The min element is "<<res<<endl;
    // }
    // else{
    //   cout <<"The min element is not found ."<<endl;
    // }
    vector<vector<int> >res;
    transposeMatrix(arr , res);
    cout <<endl;
    print(res);
  return 0;
}