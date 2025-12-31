#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 01. Search in a sorted array.
int searchArr(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  while (start < end)
  {
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
      return mid;
    }
    else if (target > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}
// 02. Find the first occurance of an element.
int firstOcc(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  int ans = -1;
  while (start < end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      ans = mid;
      end = mid - 1;
    }
    else if (target > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}
// 03 Find the last ocurance of an element.
int lastOcc(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;
  int ans = -1;
  while (start < end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
      ans = mid;
      start = mid + 1;
    }
    else if (target > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}
// 04 Find the total occurance of an element.
int totalOcc(vector<int> &arr, int target)
{
  int first = firstOcc(arr, target);
  int last = lastOcc(arr, target);
  int total = last - first + 1;
  return total;
}
// 05. Find the peak element of an element.
int findPeak(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1;

  while (start < end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1])
    {
      end = mid;
    }
    start = mid + 1;
  }
  return end;
}
// 06 Find the Pivot in a Sorted Rotated Array
int findPivot(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1;

  if (arr[start] <= arr[end])
  {
    return start;
  }

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (arr[mid] < arr[mid - 1])
    {
      return mid + 1;
    }
    if (arr[mid] > arr[mid + 1])
    {
      return mid + 1;
    }
    if (arr[mid] >= arr[start])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}
// 07. Square root of a number .
int sqrt(int n, int precesion)
{
  int start = 1, end = n;
  double ans = 0.0;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (mid <= n / mid)
    {
      ans = mid;
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }

  double increment = 0.1;
  for (int i = 1; i < precesion; i++)
  {
    while (ans * ans <= n)
    {
      ans += increment;
    }
    ans -= increment;
    precesion /= 10;
  }
  return ans;
}

// 08. divide two number .

// 09. search in a sorted and rotated array.

// 10. BS in nearly sorted array .
int searchInNearlySortedArray(vector<int> &arr, int target)
{
  int start = 0, end = arr.size() - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;

    // Check mid
    if (arr[mid] == target)
    {
      return mid;
    }
    // Check mid+1 (ensure within bounds)
    if (mid + 1 <= end && arr[mid + 1] == target)
    {
      return mid + 1;
    }
    // Check mid-1 (ensure within bounds)
    if (mid - 1 >= start && arr[mid - 1] == target)
    {
      return mid - 1;
    }

    // Decide search direction
    if (target > arr[mid])
    {
      // Since array is nearly sorted, target could be at mid+2
      start = mid + 2;
    }
    else
    {
      // Target could be at mid-2
      end = mid - 2;
    }
  }

  return -1;
}
// 11. Search in 2D array ..
int search2dArray(int arr[][4], int row, int col, int target)
{
  int start = 0, end = row * col - 1;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    int rowIndex = mid / col;
    int colIndex = mid % col;

    if (arr[rowIndex][colIndex] == target)
    {
      return mid;
    }
    else if (target > arr[rowIndex][colIndex])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}

// 12 .  Find the odd occuing of an element.
int findOdd(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (start == end)
    {
      return start;
    }
    if (mid % 2 == 0)
    {
      if (arr[mid] == arr[mid + 1])
      {
        start = mid + 1;
      }
      else
      {
        end = mid;
      }
    }
    else
    {
      if (arr[mid] == arr[mid - 1])
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  // vector<int>arr {2,3,4,5,6,7,8,12 , 14};
  // int res = searchArr(arr , 12);
  // cout <<"The ans is : "<<res <<endl;
  // vector<int>arr{1, 2, 3, 1};
  // int res = findPeak(arr);
  // cout <<"res " <<res;

  // vector<int> arr {7, 0, 1, 2, 4, 5, 6};
  // int res  = findPivot(arr);
  // cout <<"res " << res ;

  // int n = 50;
  // int precision = 3;
  // double result = sqrt(n, precision);
  // cout << fixed << setprecision(precision);
  // cout << "Square root of " << n << " = " << result << endl;

  // vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
  // int res = searchInNearlySortedArray(arr, 40);
  // cout <<"the res : "<<res<<endl;
  // int arr[5][4] = {
  //     {1, 2, 3, 4},
  //     {5, 6, 7, 8},
  //     {9, 10, 11, 12},
  //     {13, 14, 15, 16},
  //     {17, 18, 19, 20}
  // };
  // int row = 5, col = 4;
  // int res = search2dArray(arr , row , col , 15);
  // cout <<"the res : "<<res <<endl;

  vector<int> arr{1, 1, 2, 2, 3, 3, 600, 600, 4, 4, 3};
  int res = findOdd(arr);
  cout << "The res : " << arr[res];
  return 0;
}