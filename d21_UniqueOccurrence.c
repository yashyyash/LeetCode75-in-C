#include <stdio.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int count[2001] = {0};  // Array to store occurrences of each number
    int occurrenceCount[1001] = {0};  // Array to store count of occurrences
    
    // Count the occurrences of each number in the array
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + 1000]++;
    }
    
    // Check if any count occurs more than once
    for (int i = 0; i < 2001; i++) {
        if (count[i] > 0) {
            if (occurrenceCount[count[i]] > 0) {
                return false;
            }
            occurrenceCount[count[i]]++;
        }
    }
    
    return true;
}

// int main() {
//     int arr1[] = {1, 2, 2, 1, 1, 3};
//     int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
//     printf("%s\n", uniqueOccurrences(arr1, arrSize1) ? "true" : "false");  // Output: true
    
//     int arr2[] = {1, 2};
//     int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
//     printf("%s\n", uniqueOccurrences(arr2, arrSize2) ? "true" : "false");  // Output: false
    
//     int arr3[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
//     int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
//     printf("%s\n", uniqueOccurrences(arr3, arrSize3) ? "true" : "false");  // Output: true
    
//     return 0;
// }
