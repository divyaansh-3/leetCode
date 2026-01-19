class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int n= arr.size();
        int nodelete = arr[0];
        int onedelete =0;
        int res= arr[0];
        for(int i=1;i<n;i++){
            int prevnodelete =nodelete;
            int prevonedelete =onedelete;
            nodelete = max(nodelete+arr[i],arr[i]);
            onedelete =max(prevonedelete+arr[i],prevnodelete);
            res= max(res, max(nodelete,onedelete));
        }
        return res;
    }
};