#include <iostream>
#include <vector>
using namespace std;

int searchInnearlySortedArray(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      return mid;
    }
    else if (mid + 1 <= arr.size() && arr[mid + 1] == target)
    {
      return mid + 1;
    }
    else if (mid - 1 >= 0 && arr[mid - 1] == target)
    {
      return mid - 1;
    }
    else if (target > arr[mid])
    {
      start = mid + 2;
    }
    else
    {
      end = mid - 2;
    }
  }
  return -1;
}

int main()
{
  vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
  int res = searchInnearlySortedArray(arr, 70);
  cout << "The result is : " << res << endl;
  return 0;
}