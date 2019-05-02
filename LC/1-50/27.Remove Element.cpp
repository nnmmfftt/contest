/*--------------------1st--------------------*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
         * The C++ stl can erase the target value, but erase only can
         * erase iterator, and the nums array's size will be modified after
         * erase also need attention.
         */
        auto k = nums.begin();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                nums.erase(k + i);
                --i;
            }
        }
        return nums.size();
    }
};
/*--------------------2nd--------------------*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
         * Use double pointers to update nums array, same as the 26 but 
         * the different check policy.
         */
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
/*--------------------2nd--------------------*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* Because of the right pointer is from left to right.
         * Merge the right pointer to loop and make the code more concise.
         */
        int i = 0;
        for(auto k: nums){
            if(k != val){
                nums[i++] = k;
            }
        }return i;
    }
};