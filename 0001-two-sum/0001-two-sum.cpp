class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int needed = target - nums[i];

            if(mp.find(needed) != mp.end() && mp[needed]!=i){ //this condition mean if needed exist in the map and the needed element is not same as the same indexed element
                return {i,mp[needed]};
            }
        }
        return {};
        
    }
};