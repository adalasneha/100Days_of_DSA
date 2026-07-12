class Solution {
public:
    int binarySearch(MountainArray &mountainArr, int l, int r, int target, bool ascending) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (ascending) {
                if (val < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (val < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak index
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;

        // Search in increasing part
        int ans = binarySearch(mountainArr, 0, peak, target, true);
        if (ans != -1)
            return ans;

        // Search in decreasing part
        return binarySearch(mountainArr, peak + 1, n - 1, target, false);
    }
};