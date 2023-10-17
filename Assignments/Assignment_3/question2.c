#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int main() {
    int n = 10000; // initialising the size of the array
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val; 
    }

    clock_t start, end; // using a timer 
    double timetaken;

    start = clock();
    insertionSort(arr1, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds to execute \n", timetaken);

    start = clock();
    bubble_sort(arr2, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to execute \n", timetaken);

    return 0;
}
