class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(heights[left], heights[right]);
            maxWater = max(maxWater, width * h);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};