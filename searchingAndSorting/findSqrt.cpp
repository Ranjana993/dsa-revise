#include <iostream>
using namespace std;

int findSqrt(int target )
{
  int ans = 0;
  for(int i= 0 ; i <= target ; i++ ){
    if(i*i == target){
      ans = i;
      break;
    }
    if(i*i > target){
      ans = i-1;
      break;
    }
  }
  return ans;
}

int main() {
  int n ;
  cin>>n;
  int res = findSqrt(n);
  cout<<"The ans is : " <<res<<endl;

  int precision = 2;
  double result = res;
  double step= 0.1;

  for(int i = 0 ; i < precision ; i++){
    for(double j = result ; j*j <= n ; j = j+ step){
      result = j;
    }
    step = step/10;
  }

  cout <<"The final result is : "<<result;

  return 0;
}