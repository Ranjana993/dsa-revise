#include <iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> nextSmallerElement(vector<int>arr){
  stack<int>st;
  st.push(-1);
  vector<int>ans(arr.size());

  for(int i = arr.size()-1 ; i >= 0 ; i--){
    int ch = arr[i];
    while( st.top() >= ch ){
      st.pop();
    }
    ans[i] = st.top();
    st.push(ch);
  }
  return ans ;
}

vector<int> prevSmallerElement(vector<int>arr){
  stack<int>st;
  st.push(-1);
  vector<int>ans(arr.size());

  for(int i = 0; i < arr.size() ; i++){
    int ch = arr[i];
    while( st.top() >= ch ){
      st.pop();
    }
    ans[i] = st.top();
    st.push(ch);
  }
  return ans ;
}

int main() {
  vector<int>arr ={2,1,4,3};
  vector<int>ans = nextSmallerElement(arr);
  for(auto s : ans){
    cout <<s <<" "; 
  }
  cout<<endl;
  vector<int>ans2 = prevSmallerElement(arr);
    for(auto s : ans2){
    cout <<s <<" "; 
  }
  return 0;
}