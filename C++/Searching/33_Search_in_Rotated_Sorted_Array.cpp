class Solution {
public:
    int search(vector<int>& nums, int target) {
//find minimum element index(idx) and find target in two sorted arrays(0, idx -1) & (idx + 1 , n-1)
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = low + (high - low) / 2;
        int idx = -1;
        while (low <= high){
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                idx = mid;
                break;
            }
            else if (nums[mid] >= nums[high]){
                low = mid + 1;
            }
            else if (nums[mid] <= nums[low]){
                high = mid - 1;
            }
            if (nums[low] <= nums[high]){
                idx = low;
                break;
            }
            mid = low + (high - low) / 2;
        }
        if (target == nums[idx]){
            return idx;
        }
        low = 0;
        high = idx - 1;
        mid = low + (high - low) / 2;
        while (low <= high){
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        low = idx + 1;
        high = n - 1;
        mid = low + (high - low) / 2;
        while (low <= high){
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }
};