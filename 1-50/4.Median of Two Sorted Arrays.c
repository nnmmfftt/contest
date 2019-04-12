double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size())
    	return findMedianSortedArrays(nums2,nums1);  
}