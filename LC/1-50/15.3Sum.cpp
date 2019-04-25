vector<vector<int>> threeSum(vector<int>& nums) {
	/*
	 * If we check every bits, we can't afford O(n^3). It must be TLE.
	 * So the program need some optimization.
	 * If program use sort:
	 * 1. O(nlogn) first
	 * 2. Then set left and rights' sum, and check if equals negative of the other number. 
	 * 3. skip some invalid situations.
	 *     1) many of the same number could skipped directly.
	 	   2) three numbers' sum larger than 0, right need move to the left once
	 */
    vector<vector<int>> ret;
    int len = nums.size();
    if (nums.size() < 3) return ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; ++i) {
        if (i == 0 || nums[i] > nums[i - 1]) {
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int sum3 = nums[i] + nums[left] + nums[right];
                if (sum3 == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;
                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                }
                else if (sum3 > 0)
                    --right;
                else ++left;
            }
        }
    }return ret;
}