class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        search_beg = 0
        search_end = len(nums) - 1
        while True:
            search_range = search_end - search_beg
            pivot = search_range // 2
            center = search_beg + pivot
            
            if nums[center] == target:
                return center
            elif nums[center] > target:
                if search_range == 0:
                    return center
                
                search_end = center
            else:
                if search_range == 0:
                    return center + 1
                
                search_beg = center + 1
            
