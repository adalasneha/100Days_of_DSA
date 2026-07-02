class Solution {
public:
    int requiredDays(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w <= capacity) {
                load += w;
            } else {
                days++;
                load = w;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (requiredDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};