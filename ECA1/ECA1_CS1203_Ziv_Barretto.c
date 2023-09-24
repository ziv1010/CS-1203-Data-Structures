#include <stdio.h>

// Using Heaps algorithm to solve this problem
// Referred to:
// 1) https://en.wikipedia.org/wiki/Heap%27s_algorithm#:~:text=Heap's%20algorithm%20generates%20all%20possible,2%20elements%20are%20not%20disturbed.
// 2) https://www.baeldung.com/cs/array-generate-all-permutations 

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations of an array using Heap's Algorithm
void heapPermutation(int arr[], int size, int *permCount) {
    // Create an array to keep track of the position of each element
    int count[size];
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    
    // Print the initial state of the array and increment the permutation count
    for (int j = 0; j < size; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
    (*permCount)++;

    // Heap's Algorithm for generating permutations
    for (int i = 0; i < size; ) {
        if (count[i] < i) {
            // Swap elements based on the current count and i
            if (i % 2 == 0) {
                swap(&arr[0], &arr[i]);
            } else {
                swap(&arr[count[i]], &arr[i]);
            }

            // Print the new state of the array 
            for (int j = 0; j < size; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");

            // Update the count and reset i to 0
            count[i]++;
            i = 0;
            
            (*permCount)++; // Increment the permutation count
        } else {
            // Reset the count and move to the next element
            count[i] = 0;
            i++;
        }
    }
}

int main() {
    int permCount = 0; // Initialize the permutation count to 0
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    int elements[N];
    for (int i = 0; i < N; i++) {
        elements[i] = i + 1;
    }

    // Generate permutations and count them
    heapPermutation(elements, N, &permCount);
    
    // Print the total number of permutations
    printf("Total permutations: %d\n", permCount);

    return 0;
}
