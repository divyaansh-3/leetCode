class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // in this case we need to check the frequency so we must use unordered_map 
        unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
            s[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(s[nums[i]]==1) return nums[i];
        }
        return -1;
        
    }
};