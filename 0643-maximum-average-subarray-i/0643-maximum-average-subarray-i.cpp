class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n= nums.size();
        if(n==1)return nums[n-1];
        int i=0;
        int j=k-1;
        double average=0;
        int sum=0;
        double res=-1e18;
        for(;i<k;i++){
            sum+=nums[i];
        }
        average=(double)sum/k;
        res=max(average,res);
        i=0;
        j++;
        while(j<n){
            sum=sum-nums[i++]+nums[j];
            average=(double)sum/k;
            res=max(res,average);
            j++;
        }
        return res;

       

        
    }
};