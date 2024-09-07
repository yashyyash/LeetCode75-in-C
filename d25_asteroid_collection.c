#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1; // Stack is empty initially

    for (int i = 0; i < asteroidsSize; i++) {
        int asteroid = asteroids[i];
        int isDestroyed = 0;

        // Process collisions when current asteroid is moving left (-ve) and the stack has asteroids moving right (+ve)
        while (top >= 0 && asteroid < 0 && stack[top] > 0) {
            if (abs(stack[top]) < abs(asteroid)) {
                // Top asteroid in stack explodes, continue to check with the next one
                top--;
            } else if (abs(stack[top]) == abs(asteroid)) {
                // Both asteroids explode
                top--;
                isDestroyed = 1;
                break;
            } else {
                // Current asteroid explodes
                isDestroyed = 1;
                break;
            }
        }

        if (!isDestroyed) {
            // If asteroid is not destroyed, push it to stack
            stack[++top] = asteroid;
        }
    }

    *returnSize = top + 1;
    return stack;
}

// int main() {
//     int asteroids[] = {5, 10, -5}; // Example input
//     int asteroidsSize = sizeof(asteroids) / sizeof(asteroids[0]);
//     int returnSize;

//     int* result = asteroidCollision(asteroids, asteroidsSize, &returnSize);

//     // Print the resulting asteroids after collisions
//     printf("[");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d", result[i]);
//         if (i < returnSize - 1) {
//             printf(",");
//         }
//     }
//     printf("]\n");

//     free(result); // Free allocated memory
//     return 0;
// }
