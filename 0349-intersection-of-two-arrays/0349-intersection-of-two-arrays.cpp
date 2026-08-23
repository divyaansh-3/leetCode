class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //sort(nums1.begin(),nums1.end());
        //sort(nums2.begin(),nums2.end());
       
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
         auto i= s1.begin();
        auto j=s2.begin();
        vector<int>result;
        //unordered_set<int>s;
        while(i != s1.end() && j!= s2.end()){
            if(*i==*j){
                result.push_back(*i);
                i++;
                j++;
            }
            else if(*i < *j){
                i++;
            }
            else{
                j++;
            }
        }
        
        return result;

        
    }
};