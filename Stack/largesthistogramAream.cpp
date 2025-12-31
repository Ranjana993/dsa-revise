#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(arr.size());

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    int ch = arr[i];
    while (st.top() != -1 && arr[st.top()] >= ch)
    {
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }
  return ans;
}

vector<int> prevSmallerElement(vector<int> arr)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(arr.size());

  for (int i = 0; i < arr.size(); i++)
  {
    int ch = arr[i];
    while (st.top() != -1 && arr[st.top()] >= ch)
    {
      st.pop();
    }
    ans[i] = st.top();
    st.push(i);
  }
  return ans;
}

int getRectArea(vector<int> &arr)
{
  // prev smaller
  vector<int> prevSmaller = prevSmallerElement(arr);
  // next smaller
  vector<int> nextSmaller = nextSmallerElement(arr);
  int maxArea = INT_MIN;
  int s = arr.size();
  for (int i = 0; i < s; i++)
  {
    int len = arr[i];
    int nextIndex = nextSmaller[i];
    int prevIndex = prevSmaller[i];

    // If next smaller is -1, it means no smaller element to the right
    if (nextIndex == -1)
    {
      nextIndex = s; // Set to array size (right boundary)
    }

    int width = nextIndex - prevIndex - 1;
    int area = len * width;

    maxArea = max(maxArea, area);
  }
  return maxArea;
}

int main()
{
  vector<int> arr = {2, 1, 5, 6, 2, 3};
  // vector<int>ans = nextSmallerElement(arr);
  // for(auto s : ans){
  //   cout <<s <<" ";
  // }
  // cout<<endl;
  // vector<int>ans2 = prevSmallerElement(arr);
  //   for(auto s : ans2){
  //   cout <<s <<" ";
  // }

  int ans = getRectArea(arr);
  cout << "ans is : " << ans;
  return 0;
}