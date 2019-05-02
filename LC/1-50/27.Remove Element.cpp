class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = left;
        while(right<nums.size()){
            if(nums[right]!=val){
                nums[left++] = nums[right++];
            }
            else right++;
        }
        return left;
    }
};