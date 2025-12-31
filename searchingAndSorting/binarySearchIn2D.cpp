#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int rows, int cols, int target)
{
  int start = 0, end = rows * cols - 1;

  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    int rowIndex = mid / cols;
    int colIndex = mid % cols;
    if (arr[rowIndex][colIndex] == target)
    {
      return true;
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
  return false;
}

int main()
{
  int arr[5][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
      {17, 18, 19, 20}};
  int row = 5, col = 4;
  int res = binarySearch(arr, row, col, 22);
  if (res)
  {
    cout << "Found ." << endl;
  }
  else
  {
    cout << "Not Found ." << endl;
  }

  return 0;
}