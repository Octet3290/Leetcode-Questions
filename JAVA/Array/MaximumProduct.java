class Maximum_Product {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int large = 0, second_large = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > large) {
                second_large = large;
                large = nums[i];
            } 
            else if (nums[i] > second_large) {
                second_large = nums[i];
            }
        }
        return ((large - 1) * (second_large - 1));
    }

}