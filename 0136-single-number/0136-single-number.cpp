class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // in this case we need to check the frequency so we must use unordered_map 
       /* unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
            s[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(s[nums[i]]==1) return nums[i];
        }
        return -1;
        //but in this case if we use unordered map the space complexity is 0(n)
        //to reduce the time complexity to constant we need to use xor function
        // concept is the xor of same numbers is 0.
        //so the xor of all the numbers having duplicates will be finally 0 and then the xor of 0 and the single digit will be the digit itself
        */

        int res=0;
        for(int num:nums){
            res= res^num;
        }
        return res;

        
    }
};