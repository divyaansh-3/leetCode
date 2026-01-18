class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        unordered_set<int>m;
        for(;i<n;i++){
            if(m.count(nums[i]))return true;
            m.insert(nums[i]);
            if(m.size()>k){
                m.erase(nums[i-k]);
            }
        }
        return false;
        
    }
};