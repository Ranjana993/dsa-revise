#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispossibleSol(vector<long long int >& trees , long long int m ,long long int mid){
  long long int collectedWood = 0;
  for(int i = 0 ; i < trees.size() ; i++){
    if(trees[i] > mid){
      collectedWood += trees[i]-mid;
    }
  }
  return collectedWood >= m;
}

long long int maxSawBladeHieght(vector<long long int >& trees , long long m){
  long long int start = 0;
  long long int end =*max_element(trees.begin() , trees.end());

  long long int ans = -1;
  while(start <= end){
    int mid = start + (end - start)/2;

    if(ispossibleSol(trees , m , mid)){
      ans = mid;
      start = mid+1;
    }
    else{
      end = mid-1;
    }
  }
  return ans ;
}


int main() {
  long long int n , wood;
  cin >> n >> wood;

  vector<long long int> trees;
  while(n--){
    long long height;
    cin >> height;
    trees.push_back(height);
  }
  cout << maxSawBladeHieght(trees , wood)<<endl;

  return 0;
}