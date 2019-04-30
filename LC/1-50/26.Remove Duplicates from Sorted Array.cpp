#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v = {1,1,2};
	set<int> s;
	for(auto i : v){
		s.insert(i);
	}
	vector<int> ret;
	for(auto i: s){
		ret.push_back(i);

/*--------------------1st--------------------*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	/*
    	 * Using RBTree to insert the each number in given nums array.
    	 * C++ stl set template is a RBTree implememtation.
    	 * First, build a RBTree, and insert each number.
    	 * Then, fetch every item in RBTree, reassign to nums array.
    	 * Build the Tree O(nlogn) and need O(n) space.
    	 */
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int count = 0;
        for(auto i = s.begin(); i != s.end(); ++i ){
            nums[count++] = *i;
        }return count;
    }
};

/*--------------------2nd--------------------*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	/*
    	 * using two pointers to make a sliding window.
    	 * check each digit in given nums array, if the
    	 * two values are same, the condition means right
    	 * value unnecessary. If not, assign right pointer's
    	 * value to the position next to the value, until the
    	 * right to nums's end.
    	 */
        if(nums.size() < 2) return nums.size();
        int left = 0, right = 1;
        while(right <= nums.size()-1){
            if(nums[left] == nums[right]){
                ++right;
            }
            else nums[++left] = nums[right++];
        }return left+1;
    }
};
/*--------------------2nd--------------------*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	/*
    	 * Merge the right pointer with loop, and check the digit from
    	 * begin to end.
    	 */
    	int i = nums.size() >0?1:0;
    	for(auto k : nums){
    		if(k > nums[i-1])
    			nums[i++] = k;
    	}
    	return i;
    }
};