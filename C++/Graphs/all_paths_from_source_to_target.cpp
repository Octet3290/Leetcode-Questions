class Solution {
public:
    
    void dfs(int src,int dest,vector<vector<int>>& ans,vector<int>& vec,vector<vector<int>>& graph){
        if(src==dest){
            ans.push_back(vec);
            return;
        }
        for(auto node:graph[src]){
            vec.push_back(node);
            dfs(node,dest,ans,vec,graph);
            vec.pop_back();
        }
                
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> vec;
        vec.push_back(0);
        int n=graph.size();
        dfs(0,n-1,ans,vec,graph);
        return ans;
    }