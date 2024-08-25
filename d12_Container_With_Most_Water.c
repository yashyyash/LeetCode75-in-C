int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the area between the current left and right pointers
        int width = right - left;
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = width * min_height;

        // Update max_area if the current area is greater
        if (current_area > max_area) {
            max_area = current_area;
        }

        // Move the pointer of the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
