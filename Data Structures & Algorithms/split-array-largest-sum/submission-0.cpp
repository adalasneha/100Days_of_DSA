class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int subarrays = 1;
        long long currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxSum) {
                currSum += num;
            } else {
                subarrays++;
                currSum = num;
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums)
            high += num;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};