/*--------------------1st--------------------*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        sort(nums.begin(), nums.end());
        // because of boundaries, sort is harder than swap
        // actually limited by ability(my)
        bool flag = false;
        int i = 0;
        for(i ; i <nums.size(); i++){
            if(nums[i] < 0){
                continue;
            }
            if(nums[i] ==  1){
                flag = true;
            }
            
            if(i+1 < nums.size() && nums[i] == nums[i+1]){
                continue;
            }
            if(i+1 == nums.size() || nums[i] +1 != nums[i+1])
                break;
        }return flag == false ? 1:nums[i]+1;
    }
};

/*--------------------2nd--------------------*/