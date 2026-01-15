class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];   // slow moves once fast moves twice just liked ll cycle
            if(slow==fast){     //when they are equal then use the concept to find the starting point of cycle.
                slow=0;
                while(slow!=fast){
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return slow;

        }
        
    }
    return 0;
    }
};