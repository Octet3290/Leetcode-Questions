class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<num.size(); k++)
                    
                    if(num[i]+nums[j]+nums[k] ==0)
                        
                        vector<int>temp;
                
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                temp.push_back(ans);
                
                
            }
        }
        
    }
};
