// https://leetcode.com/problems/smallest-rotation-with-highest-score/

class Solution {
    public int bestRotation(int[] A) {
        int n = A.length;
        int[] a = new int[n];  // to record interval start/end
        for (int i = 0; i < A.length; i++) {
            a[(i + 1) % n]++;             // interval start
            a[(i + 1 - A[i] + n) % n]--;  // interval end
        }
        int count = 0;
        int maxCount = -1;
        int res = 0;
        for (int i = 0; i < n; i++) {  // find most overlap interval
            count += a[i];
            if (count > maxCount) {
                res = i;
                maxCount = count;
            }
        }
        return res;
    }
}
