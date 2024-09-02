#include <stdbool.h>

// Function to determine if n flowers can be planted in the flowerbed
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int flowersPlanted = 0;  // Counter to keep track of the number of flowers planted
    
    // Iterate over each plot in the flowerbed
    for (int i = 0; i < flowerbedSize; i++) {
        // Check if the current plot is empty (0)
        if (flowerbed[i] == 0) {
            // Check if the left plot is either the first plot or empty
            bool isLeftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            // Check if the right plot is either the last plot or empty
            bool isRightEmpty = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);
            
            // If both the left and right plots are empty, we can plant a flower here
            if (isLeftEmpty && isRightEmpty) {
                flowerbed[i] = 1;  // Plant the flower
                flowersPlanted++;  // Increment the flowers planted counter
                
                // If the number of flowers planted equals or exceeds n, return true
                if (flowersPlanted >= n) {
                    return true;
                }
                
                // Skip the next plot to avoid planting adjacent flowers
                i++;
            }
        }
    }
    
    // After iterating through the flowerbed, check if we've planted enough flowers
    return flowersPlanted >= n;
}