#include <iostream>
#include<vector>
using namespace std;

void wavePrint(vector<vector<int> > &arr){
  int n = arr.size();
  int m = arr[0].size();

  for(int i = 0 ; i< n ; i++){
    if((i & 1) == 0){
      for(int j = 0 ; j < m ; j++){
        cout << arr[j][i] << "  ";
      }
      cout <<endl;
    }
    else{
      for(int j = m-1; j >= 0 ; j--){
        cout << arr[j][i]<<"  ";
      }
      cout <<endl;
    }
  }

}

int main() {
  vector<vector<int> > arr{
    {1,2,3,4},
    {5,6,7,8},
    {9,8,7,6},
    {5,7,8,3}
  };
  wavePrint(arr);
  return 0;
}