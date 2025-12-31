#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;


bool isPossibleSolution(int numberOfParata , vector<int>&cookRanks , int mid){
  int currP = 0 ;
  
  for(int i = 0 ; i < cookRanks.size() ; i++){
    int R = cookRanks[i];
    int j = 1;
    int timeTaken = 0;
    
    while(true){
      if(timeTaken + j*R <= mid){
        ++currP;
        timeTaken += j*R ;
        ++j;
      }
      else{
        break;
      }
    }
    if(currP >= numberOfParata){
      return true;
    }
  }
  return false;
}

int minTimeToCompleteOrder(int numberOfParata , vector<int>&cookRanks){
  int start = 0;
  int maxRank = *max_element(cookRanks.begin() , cookRanks.end());
  int end = maxRank*(numberOfParata * (numberOfParata + 1 )/2);
  int ans = -1;
  while(start <= end){
    int mid = start + (end - start)/2;
    
    if(isPossibleSolution(numberOfParata , cookRanks , mid)){
      ans = mid;
      end = mid-1;
    }
    else{
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  int Ts;
  cin >> Ts;
  while(Ts--){
    int nP, nC;
    vector<int>cookRanks;
    cin >> nP;
    cin>> nC;
    while(nC--){
      int R;
      cin>> R;
      cookRanks.push_back(R);
    }
    cout << minTimeToCompleteOrder(nP, cookRanks) <<endl; ;
  }
  return 0;
}