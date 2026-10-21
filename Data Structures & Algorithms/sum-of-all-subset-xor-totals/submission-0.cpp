class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        vector<int> subset;

        function<void(int)> backtrack = [&](int i) {
            int xorr = 0;
            for (int num : subset) xorr ^= num;
            res += xorr;

            for (int j = i; j < nums.size(); ++j) {
                subset.push_back(nums[j]);
                backtrack(j + 1);
                subset.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};