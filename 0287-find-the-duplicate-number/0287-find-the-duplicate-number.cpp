class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n+1,0);
        int i;
        for( i=0;i<n;i++){
            a[nums[i]]++;
            if(a[nums[i]]>1){
                break;
            }
        }
        return nums[i];
        
    }
};