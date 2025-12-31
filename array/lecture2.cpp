// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <vector>

int findUnique(vector<int>&arr){
  int ans = 0;
  for(int i = 0 ; i < arr.size(); i++){
    ans = ans^arr[i];
  }
  return ans;
}
vector<int> pairSum(vector<int>&arr , int sum){
  for(int i = 0 ; i< arr.size();i++){
    for(int j = i+1; j < arr.size() ; j++){
      if(arr[i] + arr[j] == sum){
        return {arr[i] , arr[j]};
      }
    }
  }
  return {};
}

int main() {
    // vector<int>arr = {1 , 1 , 2 ,2 ,3 ,5 ,3 , 5 , 4} ;
    // cout<<"The unique element is : " <<findUnique(arr);

//  Union of two array ...
    // int arr1[] = {2,4,5,6,1};
    // int s1= 5;
    // int arr2[] ={8,7,5,4};
    // int s2 = 4;
    // vector<int>ans;
    // for(int i = 0 ; i< s1 ; i++){
    //   ans.push_back(arr1[i]);
    // }
    // for(int i = 0 ; i< s2 ; i++){
    //   ans.push_back(arr2[i]);
    // }
    // for(int i = 0 ; i < ans.size() ; i++){
    //   cout << ans[i]<< "  ";
    // }


  // pair sum..
  vector<int>arr{2,4,5,6,4,9,5};
  int sum = 9;
  vector<int> result = pairSum(arr, sum);
    
    if(!result.empty()) {
        cout << "The pair is: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No pair found with sum " << sum << endl;
    }



    return 0;
}