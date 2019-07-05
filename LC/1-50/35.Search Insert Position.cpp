class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	/*
    	 * convert the question to find the position bigger or equals to target
    	 * A C++ STL method
    	 * lower_bound is a function which defined in algorithm and find the 
    	 * *(position) >= target and return the iterator.
    	 * If we need the position rather than iter, minus the vector's begin iterator.
    	 */
        if(nums.size() == 0) return 0;
        return lower_bound(nums.begin(),nums.end(), target)-nums.begin();
    }
};
class Solution {
	int binarysearch_next(vector<int> nums,int left,  int right, int target){
		int mid = left + (right -left)/2;
		if(vector[mid] = target) return  target;
		if(vector[min] > target)
			binarysearch_next(nums, left, mid, target);
		if(vector[min] > target)
			binarysearch_next(nums, mid, right, target);


	}
	int searchInsert(vector<int>& nums, int target){
		int len = nums.size();
		if(len == 0) return 0;
	}
}