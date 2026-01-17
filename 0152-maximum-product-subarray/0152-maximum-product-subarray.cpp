class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[n-1];
        int maxending=nums[0];
        int minending = nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            int v1= nums[i];
            int v2= nums[i]*minending;
            int v3= nums[i]*maxending;
            maxending= max(v1, max(v2,v3));
            minending = min(v1,min(v2,v3));
            res= max(res,max(maxending,minending));
        }
        return res;
        
    }
};