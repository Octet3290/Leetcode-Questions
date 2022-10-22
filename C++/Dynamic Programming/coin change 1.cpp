// description of problem -> this is a infinite supplie subsequence problem of dp,below is the tabulation solution of the problem 
int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int j=1;j<coins.size();j++){
            for(int k=0;k<=amount;k++){
                int nopick=0+dp[j-1][k];
                int pick=1e9;
                if(coins[j]<=k){
                    pick=1+dp[j][k-coins[j]];
                }
                dp[j][k]=min(pick,nopick);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e9)return -1;
        else return ans;
    }
};