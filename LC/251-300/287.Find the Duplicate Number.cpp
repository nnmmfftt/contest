
static auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slow = nums[0];
        int fast = slow;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        int entry = nums[0];
        while(entry != slow){
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry;
    }
};
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
  if (nums.size() == 0)
    return 0;
  
  int right = nums.size() - 1;
  int left = 1;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    int count = 0;
    for (int val : nums) {
      if (val < mid) 
        count++;
    }
    if (count >= mid)
      right = mid - 1;
    else 
      left = mid;
  }
  return left;
 }
};
