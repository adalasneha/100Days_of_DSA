class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;

        // Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (num == ele1) {
                cnt1++;
            } 
            else if (num == ele2) {
                cnt2++;
            } 
            else if (cnt1 == 0) {
                ele1 = num;
                cnt1 = 1;
            } 
            else if (cnt2 == 0) {
                ele2 = num;
                cnt2 = 1;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify candidates
        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();

        if (cnt1 > n / 3) ans.push_back(ele1);
        if (cnt2 > n / 3) ans.push_back(ele2);

        return ans;
    }
};