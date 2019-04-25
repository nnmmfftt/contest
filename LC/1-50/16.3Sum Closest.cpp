int distance(int i, int j){
    if(i < 0){
        if(j < 0){
            if (i < j) return j-i;
            else return i - j;
        }
        else {
            return j-i;
        }
    }
    else if(i < j){
        return j-i;
    }
    else return i-j;
}
int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3) return 0;
    if (nums.size() == 3) return accumulate(nums.begin(),nums.end(),0);
	sort(nums.begin(), nums.end());
    int ret = nums[0]+nums[1]+nums[2];
    for(int i = 0;i < nums.size()-2; ++i){
        for(int j = i+1; j< nums.size()-1; ++j){
            for(int k = j+1; k <nums.size(); ++k){
                ret = distance(ret,target) <distance(nums[i]+nums[j]+nums[k],target)?ret:nums[i]+nums[j]+nums[k];
            }
        }
    }
	return ret;
}