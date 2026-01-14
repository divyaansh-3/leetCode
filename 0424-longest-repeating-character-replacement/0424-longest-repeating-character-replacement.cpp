class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int low=0;
        int high=0;
        int len=0;
        int res =INT_MIN;
        int diff=0;
        int max_int= 0;
        vector<int>v(26,0);
        for(;high<n;high++){
            v[s[high]-'A']++;
             len=high-low+1;
             max_int = max(max_int,v[s[high]-'A']);
            diff = len-max_int;
            while(diff > k){
                v[s[low]-'A']--;
                low++;
                len=high-low+1;
                max_int= max(max_int,v[s[high]-'A']);
                diff=len-max_int;
            
            }
            res=max(res,len);
        }
        return res;
    }

};