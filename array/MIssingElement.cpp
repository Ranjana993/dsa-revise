#include <iostream>
#include <vector>
using namespace std;

void findDup(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    int index = abs(arr[i]);
    if (arr[index - 1] > 0)
    {
      arr[index - 1] *= -1;
    }
  }
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > 0)
    {
      cout << i + 1 << " ";
    }
  }
}

int main()
{
  vector<int> arr{1, 2, 2, 4, 5};
  findDup(arr);
  // for(auto nums:arr){
  //   cout <<nums <<" ";
  // }
  return 0;
}