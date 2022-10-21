// https://leetcode.com/problems/cherry-pickup/

class Solution {
    private int helper(int r1, int c1, int r2, int[][] grid, Integer[][][] dp, int n) {
		//write your code here
        int c2 = r1 + c1 - r2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return Integer.MIN_VALUE;

        if(r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if(dp[r1][c1][r2] != null)
            return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        int f1 = helper(r1 + 1, c1, r2 + 1, grid, dp, n);
        int f2 = helper(r1, c1 + 1, r2, grid, dp, n);
        int f3 = helper(r1 + 1, c1, r2, grid, dp, n);
        int f4 = helper(r1, c1 + 1, r2 + 1, grid, dp, n);

        cherries += Math.max(Math.max(f1, f2), Math.max(f3, f4));

        dp[r1][c1][r2] = cherries;
		return cherries;
	}
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        return Math.max(0, helper(0, 0, 0, grid, new Integer[n][n][n], n));
    }
}
