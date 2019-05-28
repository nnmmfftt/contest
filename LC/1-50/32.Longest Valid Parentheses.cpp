
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> vec(s.size());
        int ret = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ')' && s[i-vec[i-1]-1] == '('){
                int index = i-vec[i-1]-2;
                vec[i] = vec[i-1]+2 + (index > 0?vec[index]:0);
                ret = max(ret,vec[i]);
            }
            else{
                vec[i] = 0;
            }
        }
        return ret;
    }
};
