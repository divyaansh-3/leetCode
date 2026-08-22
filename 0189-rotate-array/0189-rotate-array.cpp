class Solution {
public:
    void rev(vector<int>&a, int start, int end){
        while(start<=end){
        int temp = a[start];
        a[start] = a[end];
        a[end]= temp;
        start++;
        end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // 1 2 3 4 5 6 7
        // reverse the array 
        // 7 6 5 4 3 2 1
        // reverse the array as per k
        // 5 6 7 1 2 3 4
        if(k%nums.size()==0)return;
        // if size of array and no of rotations is same then resultnat array will be same.
        k= k% nums.size();
        // if k=11 and n=7 then after 7 rotations will get same array so resultant array depends on 4.

        rev(nums, 0 , nums.size()-1);
        rev(nums, 0 , k-1);
        rev(nums, k, nums.size()-1);
        
    }
};