/*--------------------1st--------------------*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	/*
	 * the O(log(m+n)) solution based on a num, the half capcity of
	 * nums1+nums2. We set to pointer at nums1[0] and nums2[0], compare
	 * the value and count the sum the pointer go through, until the sum to half.
	 */
	if(nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2,nums1);
	if(nums1.size()==0){
		if(nums2.size()==0){
			return 0;
		}
		else if(nums2.size()%2==0) return (nums2[(nums2.size()-1)/2]+nums2[nums2.size()/2])/2.0;
		else return nums2[nums2.size()/2];
	}
    if (nums1.size() == 1 && nums2.size() == 1) return double(nums1[0] + nums2[0]) / 2;
	int pos_val1 = 0x7fffffff;
	int pos_val2 = 0x7fffffff;
	int count =0;
	int val = (nums1.size()+nums2.size())/2+1;
	int left = 0;
	int right = 0;
	/**
	 * also we can store value until buffer's size equals to vectors /2
	 */
	while(count < val){
		if(left < nums1.size()&&right <nums2.size()){
		if(nums1[left] < nums2[right]){
			pos_val1 = pos_val2; 
			pos_val2 = nums1[left++];
			count ++;
		}
	
		else {
			pos_val1 = pos_val2;
			pos_val2 = nums2[right++];
			count ++;
		}
		}
		else if(left+1>=nums1.size()){
			pos_val1 = pos_val2;
			pos_val2 = nums2[right++];
            count++;
		}
		else if(right+1>=nums2.size()){
			pos_val1 = pos_val2;
			pos_val2 = nums1[left++];
            count++;
		}

	}	
	if((nums1.size()+nums2.size())%2==1) return pos_val2/1.0;
	else {
		return (pos_val2+pos_val1)/2.0;
	}
}


/*--------------------2nt--------------------*/
void merge(int* a, int c, int* b, int d , double * answer ){
     int i = 0 ,k = 0 ,n = 0 ;
      while ( i < c && k < d ){
          if ( a[i] < b[k] ){
               answer [n++]= a[i++];         
          }
          else {
              answer [n++] = b[k++];
          }
}
       while ( i < c ){
            answer [n++] = a[i++];      
       }
       while ( k < d ){
            answer [n++] = b[k++];    
       }
       return answer;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	/*
     * Now we know the to vector alreday sorted itself, wo could use 
     * the mergesort's last step. The thought in context we 
     * mentioned. actually twice as fast as 1st. Some times is wasted
     * in the C++ STL functions.  
     */
    double answer [nums1Size + nums2Size] ;
    merge(nums1, nums1Size, nums2, nums2Size, &answer);
    if ((nums1Size + nums2Size)%2== 1) {
        return answer[(nums1Size + nums2Size)/2] ;
    }
    else return (answer[(nums1Size + nums2Size)/2-1] + answer[(nums1Size + nums2Size)/2])/2;
}

/*--------------------3rd--------------------*/
class Solution3 {
private:
	double findkth(vector<int> &nums1, vector<int> &nums2, int k, int start_nums1, int start_nums2){
		if(nums1.size()<nums2.size())
			return findkth(nums2, nums1, k, start_nums2, start_nums1);
		if(nums1.size() - start_nums1 == 0)
			return nums2[start_nums2+k-1];
		if(nums2.size() - start_nums2 == 0)
			return nums1[start_nums1+k-1];
		if(k == 1){
			return min(nums1[start_nums1], nums2[start_nums2]);
		}
		int s = nums1.size() - start_nums1;
		int pos1 = min(k/2, s);// pos1 = min(k/2, start_nums1)
		int pos2 = K - pos1;// pos2 = min(k/2,start_nums2);
		if(nums1[start_nums1+pos1-1]<nums2[start_nums2+pos2-1])
			return findkth(nums1, nums2, k-p1, start_nums1+pos1, start_nums2);
		else
			return findkth(nums2, nums1, k-p2, start_nums1, start_nums2+pos2);
	}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        	/*
	 * Now we have a log(min(m,n)) use binary search, we 
	 * need find the median recursive function.
	 * 
	 * the correct position we cut is :
	 *
	 *              L1 | L2
	 *  1, 4, 5, 7,  8 | 12, 14, 15, 17
	 *
	 *              R1 | R2
	 *     3, 6, 9, 11 | 13, 16, 19, 20 ,22
	 *
	 *		 L1 < R2  and  L2 > R1
	 *
	 */
	int s1 = nums1.size(), s2 = nums2.size();
	int mid = (s1+s2)/2;
	if((s1 + s2)%2 == 0){
		return (findkth(nums1, nums2, mid, 0, 0) + findkth(nums1, nums2, mid+1, 0, 0))/2.0;
	}
	else
		return findkth(nums1, nums2, mid+1, 0, 0);
    }
};