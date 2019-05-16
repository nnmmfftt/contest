
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
class Solution {
public:
    int longestValidParentheses(string s) {
        if(0 == s.size()) return 0;
        stack<char> match;
        vector<char> tmp;
        for(auto i : s){
            if(match.size()!=0 && i ==')'){
                tmp.push_back(match.top());
                match.pop();
                tmp.push_back(i);
            }
            if(i == '('){
                match.push(i);
            }
            
        }
        sort(tmp.begin(),tmp.end());
        int pos = 0;
        int ret = 0;
        int len = tmp.size();
        while(pos < len){
            int j = pos;
            while(j < len -1 && tmp[j+1] == tmp[j] +1){
                j+=1;
            }
            ret = ret > (j-pos+1)? ret:(j-pos+1);
            pos = j+1;
        }
        return ret;
    }
};