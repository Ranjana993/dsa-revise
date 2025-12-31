#include <iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int>&q){
  stack<int>st;
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    st.push(temp);
  }

  while(!st.empty()){
    int temp = st.top();
    st.pop();
    q.push(temp);
  }
}


void reverseQueueRecursion(queue<int>&q){
  if(q.empty()){
    return;
  }
  int temp = q.front();
  q.pop();
  reverseQueueRecursion(q);
  q.push(temp);
}

int main() {
  queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  reverseQueueRecursion(q);

  while(!q.empty()){
    cout <<q.front() <<" ";
    q.pop();
  }

  return 0;
}