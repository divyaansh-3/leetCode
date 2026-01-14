class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=0;
        int sum=0;
        int len=0;
        int result= INT_MAX;
        while(high<n){
            sum+=nums[high];
            while(sum>=target){
                len=high-low+1;
                sum-=nums[low];
                len= min(result,len);
                result=len;
                low++;
            }
            high++;
        }
        return len;
        
    }
};