class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[n-1];
        int i=0;
        
        int ans= nums[0];
        int bestending=nums[0];
        for(i=1;i<n;i++){
            int v1= bestending +nums[i];
            int v2= nums[i];
            bestending= max(v1,v2);
            ans= max(ans,bestending);
        }
        return ans;
        
        
    }
};