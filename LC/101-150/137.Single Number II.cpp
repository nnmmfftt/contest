/*--------------------1st--------------------*/
class Solution {
public:
    // hash map
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums){
            if(mp.find(i)==mp.end()) mp[i] = 1;
            else if(mp[i] == 2){
                mp.erase(i);
                // every element only 1 or 3 times
            }
            else if(mp[i] == 1) mp[i]++;
        }
        auto i = mp.begin();
        return (*i).first;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // bit operation
        int one = 0, two = 0, three;
        // use three value store all number's bits conditions
        // one   means this bit appear one times and more
        // two   means this bit appear two times and more
        // three means this bit appear three times and flag need to be cleared
        for(auto i : nums){
            two |= (one & i);
            // 
            one ^= i;
            three = (two & one);
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};
/*--------------------3rd--------------------*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int appear_once = 0, appear_twice = 0;

        for (auto i : nums){
            appear_once = (appear_once ^ i) & ~appear_twice;
            // not appear in appear_once and appear_twice
            // -> the element first come there

            appear_twice = (appear_twice ^ i) & ~appear_once;
            // not appear in appear_twice (more than once)
            // when the number appear 3rd times, the flag need to be cleared
        }
        return appear_once;
    }
};


