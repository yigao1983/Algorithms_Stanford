#ifndef MERGESORT_HPP
#define MERGESORT_HPP

template <class T>
class MergeSort {
  
public:
  
  static void merge_sort(int n, T a[])
  {
    T *aux = new T[n];
    
    sort(a, aux, 0, n-1);
    
    delete [] aux;
  }
  
private:
  
  static void merge(T a[], T aux[], int lo, int mid, int hi)
  {
    for (int k = lo; k <= hi; k++) {
      aux[k] = a[k];
    }
    
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
      if (i > mid) {
        a[k] = aux[j++];
      } else if (j > hi) {
        a[k] = aux[i++];
      } else {
        a[k] = (aux[j] < aux[i]) ? aux[j++] : aux[i++];
      }
    }
  }
  
  static void sort(T a[], T aux[], int lo, int hi)
  {
    if (lo >= hi) {
      return;
    }
    
    int mid = (lo + hi) / 2;
    
    sort(a, aux, lo, mid);
    sort(a, aux, mid+1, hi);
    
    merge(a, aux, lo, mid, hi);
  }
};

#endif
