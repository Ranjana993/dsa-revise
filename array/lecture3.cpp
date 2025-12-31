#include <iostream>
#include <climits>
using namespace std;

// get max in 2D array
int getMax(int arr[][4], int row, int col)
{
  int maxi = INT_MIN;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (arr[i][j] > maxi)
      {
        maxi = arr[i][j];
      }
    }
  }
  return maxi;
}

// get min in 2D array
int getMin(int arr[][4], int row, int col)
{
  int mini = INT_MAX;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (arr[i][j] < mini)
      {
        mini = arr[i][j];
      }
    }
  }
  return mini;
}

// transpose of a matrix
void transposeArr(int arr[][4], int row, int col, int res[][4])
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      res[i][j] = arr[j][i];
    }
  }
}

int main()
{
  // !declaration...
  // int arr[3][3];

  // !initialization...
  // int brr[3][3]={{1,2,3}, {4,5,6},{7,8,9}};
  // int row = 3, col = 3;
  // for(int i = 0 ; i <= row-1 ; i++){
  //     for(int j = 0 ; j <= col-1 ; j++){
  //         cout <<brr[i][j]<<"  ";
  //     }
  //     cout <<endl;
  // }

  int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 5, 9, 7}, {5, 5, 8, 9}};
  int row = 4, col = 4, rSum = 0;

  for (int i = 0; i <= row - 1; i++)
  {
    for (int j = 0; j <= col - 1; j++)
    {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl ;

  for (int i = 0; i <= row - 1; i++)
  {
    for (int j = 0; j <= col - 1; j++)
    {
      rSum += arr[i][j];
    }
    cout << "the row sum is : " << rSum << endl;
    rSum = 0;
  }
  cout << endl;
  int cSum = 0;
  for (int i = 0; i <= row - 1; i++)
  {
    for (int j = 0; j <= col - 1; j++)
    {
      cSum += arr[j][i];
    }
    cout << "The col sum is: " << cSum << endl;
    cSum = 0;
  }
  cout << endl;
  cout << "The max element in the array is : " << getMax(arr, row, col);

  cout << endl;
  cout << "The min element in the array is : " << getMin(arr, row, col) << endl;

  int res[4][4];
  transposeArr(arr, row, col, res);
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << res[i][j] << "  ";
    }
    cout << endl;
  }

  return 0;
}