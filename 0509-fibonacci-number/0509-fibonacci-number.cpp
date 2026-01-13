class Solution {
public:
vector<int>v;

    int fib(int n) {
        v.assign(n+1,-1);
        return solve(n);
    }
    int solve(int n){
        if(n<=1){
            v[n]=n;
            return n;
        }
        else{
            if(v[n-2]==-1){
                v[n-2]=solve(n-2);
            }
            if(v[n-1]==-1){
                v[n-1]=solve(n-1);
            }
            v[n]=v[n-2]+v[n-1];
            

        }
        return v[n];
        
    }
};