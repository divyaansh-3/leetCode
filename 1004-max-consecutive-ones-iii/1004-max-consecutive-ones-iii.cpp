class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int n= nums.size();
        int res=0;
        int count=0;
        for(;high<n;high++){
            if(nums[high]==0)count++;
            while(count>k){
            if(nums[low]==0){
                count--;
            

            }
            low++;
            }
            res=max(res,high-low+1);
        }
        return res;
        
    }
};