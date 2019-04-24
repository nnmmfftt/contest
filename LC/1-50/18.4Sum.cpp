vector<vector<int>> fourSum(vector<int>& nums, int target) {
	/*
	 * Use the same method to 15,16.
	 * The major step is skip the repeated digit.
	 */
    int len = nums.size();
    if (len < 4) return vector<vector<int>>();
    int left, right;
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 3; ++i) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < len - 2; ++j) {
            if(nums[j] == nums[j-1]&& i < j-1) continue;
            left = j + 1;
            right = len - 1;
            while (left < right) {
                int sum4 = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum4 == target) {
                    ret.push_back({ nums[i],nums[j],nums[left],nums[right] });
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
                else if (sum4 > target) right--;
                else left++;
            }
        }
    }return ret;
}