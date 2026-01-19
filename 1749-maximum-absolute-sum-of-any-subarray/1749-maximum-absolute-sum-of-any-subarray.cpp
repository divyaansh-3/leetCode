class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxending = nums[0];
        int minending= nums[0];
        int res =abs(nums[0]);
        for(int i=1;i<n;i++){
            maxending= (max(nums[i],maxending+nums[i]));
            minending =(min(nums[i],minending+nums[i]));
            res= max(abs(res),max(abs(maxending),abs(minending)));
        }
        return res;
        
    }
};