class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int high=0;
        int n=fruits.size();
        if(n==0)return 0;
        int count=0;
        unordered_map<int,int>f;
        for(;high<n;high++){
            f[fruits[high]]++;
            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]]==0)f.erase(fruits[low]);
                low++;
                
            }
            count = max(count,high-low+1);
            

        }
        return count;

        
    }
};