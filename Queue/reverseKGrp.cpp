// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void reverseKgrpElement(queue<int> &q, int k)
{
  if (q.empty())
    return;
  int n = q.size();
  int counter = 0;
  stack<int> st;

  while (!q.empty())
  {
    int temp = q.front();
    q.pop();
    counter++;
    st.push(temp);
    if (counter == k)
      break;
  }
  while (!st.empty())
  {
    int temp = st.top();
    st.pop();
    q.push(temp);
  }
  for (int i = 0; i < n - k; i++)
  {
    q.push(q.front());
    q.pop();
  }
}

void interleave(queue<int> &q)
{
  if (q.empty())
    return;
  queue<int> q2;
  int n = q.size();

  for (int i = 0; i < n / 2; i++)
  {
    int temp = q.front();
    q.pop();
    q2.push(temp);
  }

  while (!q2.empty())
  {
    int temp = q2.front();
    q2.pop();
    q.push(temp);
    if (!q.empty())
    {
      int temp2 = q.front();
      q.pop();
      q.push(temp2);
    }
  }
}

void slideWindow(vector<int> &arr, int k)
{
  int n = arr.size();
  if (k > n)
    return;

  deque<int> q;
  for (int i = 0; i < k; i++)
  {
    if (arr[i] < 0)
    {
      q.push_back(i);
    }
  }
  for (int i = k; i < n; i++)
  {
    if (q.empty())
    {
      cout << 0 << " ";
    }
    else
    {
      cout << arr[q.front()] << " ";
    }
    while (!q.empty() && i - q.front() >= k)
    {
      q.pop_front();
    }
    if (arr[i] < 0)
    {
      q.push_back(i);
    }
  }
  if (q.empty())
  {
    cout << 0 << " ";
  }
  else
  {
    cout << arr[q.front()] << " ";
  }
}

int main()
{
  // reverse forst k grp of element of queue..
  queue<int> q;
  q.push(3);
  q.push(6);
  q.push(9);
  q.push(12);
  q.push(13);
  q.push(15);
  reverseKgrpElement(q, 3);
  // while(!q.empty()){
  //      cout <<q.front()<<"  ";
  //      q.pop();
  // }

  interleave(q);
  while (!q.empty())
  {
    cout << q.front() << "  ";
    q.pop();
  }
  cout << endl;

  vector<int> arr{12, -1, -7, 8, -15, 30, 16, 28};
  slideWindow(arr, 3);

  return 0;
}