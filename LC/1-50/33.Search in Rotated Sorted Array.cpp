class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() -1;
        int mid;
        while(left <= right){
        	mid = left + (right - left)/2;

        	if(nums[mid] == target)
        		return mid;
            if(nums[left] == nums[mid])
                left ++;
        	else{
        		if(nums[left] < nums[mid]){
        			if(nums[left] <= target && target <= nums[mid])
        				right = mid;
	        		else
	        			left +=1;
	        	}
	        	else{
                    if(nums[mid] <= target && target <= nums[right])
	        		    left = mid;
	        		else 
                        right = mid -1;
                }
	        }
        }
        return -1; 
    }
};