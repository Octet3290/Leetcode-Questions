class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = low + (high - low) / 2;
        if (nums[low] < nums[high]){
            return nums[low];
        }
        while (low <= high){
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
                return nums[mid];
            }
            if (nums[low] <= nums[mid]){
                low = mid + 1;
            }
            else if (nums[high] >= nums[mid]){
                high = mid - 1;
            }
            if (nums[low] < nums[high]){
                return nums[low];
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }
};