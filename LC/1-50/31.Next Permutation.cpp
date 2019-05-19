class Solution {
public:
    void swaptwo(int *v1, int *v2){
        *v1 = *v1 + *v2;
        *v2 = *v1 - *v2;
        *v1 = *v1 - *v2;
    }
    void nextPermutation(vector<int>& nums) {
        /*
         * 
         */
        if(nums.size() < 2)
            return ;
        int len = nums.size()-1;
        while(len > 0 && nums[len] <= nums[len-1])
            len-=1;
        int tmpa = len;
        int tmpb = nums.size()-1;
        while(tmpa < tmpb){
            swap(&nums[tmpa],&nums[tmpb]);
            tmpa++;
            tmpb--;
        }
        int j = len - 1;
        if(j < 0) return ;
        for(int i = len; i < nums.size(); ++i){
            if(nums[i] > nums[j]){
                swaptwo(&nums[i],&nums[j]);   
                break;
            }
        }
    }
};