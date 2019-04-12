int* twoSum(int* nums, int numsSize, int target) {
    /*
     * use the brute force took O(n^2)
     *
     */
    if(numsSize < 2) return -1;
    int *retbuf = (int*)malloc(sizeof(int)*2);
    for(int i = 0; i < numsSize-1; ++i){
        for(int j = i+1; j < numsSize; ++j){
            if(nums[i]+nums[j] == target){
                *retbuf = i;
                *(retbuf+1) = j;
                return retbuf;
            }
        }
    }return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    /*
     * or use the hash to O(n) which is C++ stl powerful tool
     * either we can make a hash data structure in C 
     * which may include 1.node 2.bucket 3.hash function etc;
     */
    unordered_map<int,int> map;
    vector<int> ret;
    for(int i = 0; i < nums.size();++i){
        if(map.find(target - nums[i])!=map.end() ){
            ret.push_back(map[target-nums[i]]);
            ret.push_back(i);
            return ret;
        }
        else map[nums[i]] = i;
    }return ret;
}