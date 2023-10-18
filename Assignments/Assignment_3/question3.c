#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
   // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


void printArray(int arr[], int size)
{   
    int i; 
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapInsert(int arr[], int n, int elm)
{
     int i, parent; 

     arr[n] = elm;
     i = n;

     if (i == 0) return;
   
     while (i != 0){
         parent = (i-1)/2;
         if (arr[parent] < arr[i]) swap(&arr[i], &arr[parent]);
         else break;
         i = parent;
    }
}

int heapDelete(int arr[], int n)
{
     int i, left, right, largest, val, flag = 1; 

     if (n == 0) return -9999;
     val = arr[0];
     arr[0] = arr[n-1];
     i = 0;

     while (flag == 1){
	flag = 0; largest = i;
        left = 2*i+1; right = 2*i+2;
        if (left <= n-1 && arr[left] > arr[largest]){
		largest = left; flag = 1;
	}
        if (right <= n-1 && arr[right] > arr[largest]){
		largest = right; flag = 1;
	}
	if (flag == 1){
		 swap(&arr[i], &arr[largest]); i = largest;
	}
     }
     return val;
}
 
void heapSort(int arr[], int n)
{
    int i, elm;

    for(i = 0; i < n; i++)  
        heapInsert(arr, i, arr[i]);

    for(i = n; i > 0; i--){  
    	elm = heapDelete(arr, i);
	arr[i-1] = elm;
    }
}

int main() {
    int n = 10000; // initializing the size of the array
    int arr1[n], arr2[n], arr3[n];
    
    // Initialize a random seed
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val;
        arr3[i] = val;
    }

    clock_t start, end;
    double timetaken;

    // Merge Sort
    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort took %f seconds to execute\n", timetaken);

    // Reset the array for Quick Sort
    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[i];
    }

    // Quick Sort
    start = clock();
    quickSort(arr1, 0, n - 1);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to execute\n", timetaken);

    // Reset the array for Heap Sort
    for (int i = 0; i < n; i++) {
        arr1[i] = arr3[i];
    }

    // Heap Sort
    start = clock();
    heapSort(arr1, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort took %f seconds to execute\n", timetaken);

    return 0;
}

//took some help from Jaee for the experimental data part of the code (main method)
