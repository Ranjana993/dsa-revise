#include <iostream>
#include<stack>
using namespace std;

void getMid(stack<int>&s ,int &totalSize ){
  if(s.size() == -1){
    cout <<"Stack is empty . "<<endl;
  }
  if(s.size() == totalSize/2+1 ){
    cout <<s.top();
    return;
  }
  int temp = s.top();
  s.pop();
  getMid(s , totalSize);
  s.push(temp);
}


int main() {
  stack<int>s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  int totalSize = s.size();
  getMid(s ,totalSize );
  return 0;
}