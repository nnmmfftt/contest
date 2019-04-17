/*--------------------1st--------------------*/
static const auto __=[](){
	std::io::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
int maxArea(vector<int>& height) {
	/*
	 * Use double pointers left and right, they will point to container's each endpoint.
	 *
	 * The max area is affected by right-left and min(height[left],height[right]).
	 *
	 * How does it work?
	 * Because of finding higher boundary, The length we got will decrease, but when we decrease
	 * length we need to move the smaller side, it will minimized the amount of movement decreases.
	 *
	 * tips: 
	 * This solution definetly O(n), it will be a fastest solution, but only beats 80%?
	 * If you use C++, you need to unbind stdio with printf in a lambda function.
	 *
	 */ 
	if(height.size() <2) return 0;
	int left = 0;
	int right = height.size()-1;
	int maxsize = 0;
	while(left < right){
		int tmp = height[left] > height[right]?
						height[right]*(right-left) : height[left]*(right-left);
		maxsize = tmp > maxsize ?
					tmp : maxsize;
		if(height[left] > height[right])
			--right;
		else 
			++left;

	}return maxsize; 
}
