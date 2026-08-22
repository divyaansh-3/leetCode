class Solution {
public:
void rev(vector<int>&a, int start, int end){
    while(start<=end){
        int temp =a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n ==0 ){
            return;
        }
        k=k%n;
         rev(nums,0,n-1);
         rev(nums,0,k-1);
         rev(nums,k,n-1);

        
    }
};