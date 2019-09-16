/*--------------------1st--------------------*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	// everything is hash
        unordered_map<int,int> m;
        for(auto i : nums){
            if(m.find(i) == m.end())
                m[i] = 1;
            else
                m.erase(i);
        }
        auto iter = m.begin();
        return (*iter).first;
    }
};


/*--------------------2nd--------------------*/
static auto _ = []()
// if only beats 20%，after add the magic code will beat 99%.
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}
();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	// x ^ x = 0
    	// x ^ 0 = x
    	// commutative law of xor
    	// (simply prove it by venn diagram)
    	// analog binary solutotion
        int rec = 0; 
        for(int i= 0; i < nums.size(); ++i){
            rec ^=nums[i];
        }return rec;
    }
};
/*--------------------3rd--------------------*/
// accumulate solution
// 2*(a + b + ... + x ) - (a + a + b + b + .... + x) = x
// The 137th： single number II  