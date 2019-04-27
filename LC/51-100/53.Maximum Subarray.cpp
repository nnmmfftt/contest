/*--------------------1st--------------------*/
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        /*
         *
         * Find each item and compare with max sum, reassign the max sum is the current max value,
         * But the current sum less than 0, 
         * The current sum will reset to 0: 
         *                          The previous paragraph from a number to current number can't be max value, 
         *                          and the max value before already on the record: max sum.
         *
         */
        /*------------------*/
        /*
         *
         * if all of number is lee than 0, need to find the maximum one.
         *
         */
        int count = 0;
        for(auto i : nums){
            if (i < 0) count++;
        }
        if(count == nums.size()) return *max_element(nums.begin(),nums.end());
        int tmp = 0;
        int val_max = 0;
        for(int i= 0; i < nums.size(); ++i){
            if(tmp + nums[i] > 0){
                tmp +=nums[i];
            }
            else 
                tmp = 0;
            val_max = val_max > tmp ? val_max:tmp;
        }
        return val_max;
    }
};

/*--------------------1st-re-----------------*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         *
         * Also, check each number less than 0 can be simplified:
         *
         */
        int val_sum = nums[0];
        int seg_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(seg_sum > 0){
                seg_sum += nums[i];
            }
            else {
                seg_sum = nums[i];
            }
            val_sum = val_sum > seg_sum? val_sum:seg_sum;
        }
    return val_sum; 
    }
};

/*--------------------2nd--------------------*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         * Another method comes from optimal substructure:
         *          each sum of distance is a substructure,and the max will be a optimal one.
         *
         * If have a array to store the max subarray:
         *      dp[i] : the max sum of nums[i-1];
         * Then the current condition will comes from 2 pre conditions:
         *      1. If the previous number's max value(dp[i-1]) > 0, the current number's max sum is:
         *                               max(dp[i-1]+nums[i-1],nums[i-1])
         *      2. if the previous number's max value < 0, the current number's max sum is nums[i],
         *          because previous is negative, ignor the previous will get a bigger value.
         */
        int dp[nums.size()+1];
        memset(dp, 0, sizeof(dp));
        int maxsum = nums[0];
        for(int i = 1; i < nums.size()+1; ++i){
            if(dp[i-1] > 0){
                dp[i] = dp[i-1] + nums[i-1];
                //dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
                /*
                 * 3 conditions:
                 *   1. nums[i-1] > 0,  
                 *          max sum is (dp[i-1] + nums[i-1])     -> dp[i-1] > 0
                 *   2. nums[i-1] < 0 but dp[i-1] + nums[i-1] > 0: 
                 *          max sum is (dp[i-1] + nums[i-1])
                 *   3. nums[i-1] < 0 and dp[i-1] + nums[i-1] < 0;
                 *          max sum is (dp[i-1] + nums[i-1])
                 *
                 *  So whatever the nums[i-1] is, the max sum is nums[i-1]+ dp[i-1] when dp[i-1] >0,
                 */
            }
            else 
                dp[i] = nums[i-1];
            if(dp[i] > maxsum)
                maxsum = dp[i];
        }return maxsum;
    }
};
/*--------------------3rd--------------------*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         * Check the dp code above, the dp array actually only use one time in a loop.
         * Then use a integer value instead of dp array.
         */
        int ret = 0x80000000;
        int val_sum = 0;
        for(auto i :nums){
            val_sum = val_sum +i > i? val_sum +i :i;
            ret  = ret > val_sum? ret: val_sum;
        }
        return ret;
    }
};

/*--------------------4nd--------------------*/
class Solution {
public:
    int merge_maxSubArray(vector<int> &nums, int left, int right);

    int maxSubArray(vector<int>& nums) {
        /*
         * The divide and conquer version is  O(nlogn), and looks like a mergesort,
         * divide every array and find the max value, then put the two subarray together
         * and find the max value of the connected subarray.
         *
         */
        return merge_maxSubArray(nums, 0, nums.size()-1);
    }


    int merge_maxSubArray(vector<int> &nums, int left, int right){
        if(left >=right){
            return nums[left];
        }
        int mid = left+(right-left)/2;
        int leftmax = merge_maxSubArray(nums, left, mid);
        int rightmax= merge_maxSubArray(nums, mid+1,right);
        int max_sum_left = 0x80000000;
        int tmp1 = 0;
        for(int i = mid; i >= left; --i){
            tmp1 += nums[i];
            max_sum_left = max_sum_left > tmp1? max_sum_left:tmp1;
        }
        int max_sum_right = 0x80000000;
        int tmp2 = 0;
        for(int i = mid+1; i <= right; ++i){
            tmp2 += nums[i];
            max_sum_right = max_sum_right>tmp2?max_sum_right:tmp2;
        }
        return max({max_sum_right+max_sum_left, leftmax, rightmax});
    }
};