#include <stdio.h>
#include <stdlib.h>

// Define the RecentCounter struct
typedef struct {
    int* requests;
    int size;
    int capacity;
} RecentCounter;

// Initialize the RecentCounter
RecentCounter* recentCounterCreate() {
    RecentCounter* counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->capacity = 10000;  // Set a large enough capacity
    counter->requests = (int*)malloc(sizeof(int) * counter->capacity);
    counter->size = 0;
    return counter;
}

// Add a new ping request and return the number of recent pings
int recentCounterPing(RecentCounter* obj, int t) {
    obj->requests[obj->size] = t;
    obj->size++;

    // Remove requests older than t - 3000
    int start = 0;
    while (obj->requests[start] < t - 3000) {
        start++;
    }

    // Shift the remaining requests to the front of the array
    obj->size -= start;
    for (int i = 0; i < obj->size; i++) {
        obj->requests[i] = obj->requests[start + i];
    }

    return obj->size;
}

// Free the allocated memory
void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */
