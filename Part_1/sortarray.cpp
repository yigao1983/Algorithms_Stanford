#include <iostream>
#include <cstdlib>
#include "mergesort.hpp"

using namespace std;

int main()
{
  const int N = 5;
  int *arr = new int[N];
  
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % N;
    cout << arr[i] << " ";
  }
  cout << endl;
  
  MergeSort<int>::merge_sort(N, arr);
  
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  delete [] arr;
  
  return 0;
}
