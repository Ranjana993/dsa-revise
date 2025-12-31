#include <iostream>
#include <stack>
using namespace std;

void getMid(stack<int> &s, int &totalSize)
{
  if (s.size() == -1)
  {
    cout << "Stack is empty . " << endl;
  }
  if (s.size() == totalSize / 2 + 1)
  {
    cout << s.top();
    return;
  }
  int temp = s.top();
  s.pop();
  getMid(s, totalSize);
  s.push(temp);
}

void solve(stack<int> &s, int &target)
{
  if (s.empty())
  {
    s.push(target);
    return;
  }
  int temp = s.top();
  s.pop();
  solve(s, target);
  s.push(temp);
}

void insertAtBottom(stack<int> &s)
{
  if (s.empty())
  {
    cout << "Stack is empty " << endl;
    return;
  }
  int target = s.top();
  s.pop();
  solve(s, target);
}

void reverseStack(stack<int> &s)
{
  if (s.empty())
  {
    return;
  }
  int target = s.top();
  s.pop();
  reverseStack(s);
  solve(s, target);
}

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  int totalSize = s.size();

  // GETTING MIDDLE ELEMENT......
  // getMid(s ,totalSize );

  // cout <<endl;
  // while(!s.empty()){
  //   cout<<s.top() <<"  ";
  //   s.pop();
  // }
  // cout <<endl;

  // INSERT AT MIDDLE.......
  // insertAtBottom(s);
  // while(!s.empty()){
  //   cout<<s.top() <<"  ";
  //   s.pop();
  // }

  // REVERSE A STACK ......

  reverseStack(s);
  while (!s.empty())
  {
    cout << s.top() << "  ";
    s.pop();
  }

  return 0;
}