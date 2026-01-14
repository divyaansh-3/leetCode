class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int n=s.length();
        if(n==0)return 0;
        int count=0;
        unordered_map<char,int>f;
        for(;high<n;high++){
            f[s[high]]++;
            while(f[s[high]]>1){
                f[s[low]]--;
                if(f[s[low]]==0)f.erase(s[low]);
                low++;
            }
            count=max(count,high-low+1);

        }
        return count;
        
    }
};