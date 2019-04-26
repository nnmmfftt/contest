class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        dfs_parenthesis(n, n, "", vec);
        return vec;
    }

    void dfs_parenthesis(int left, int right, string str, vector<string> &vec){
        if(left == right == 0){
            vec.push_back(str);
        }
        if(left < right){
             if(left > 0)
                dfs_parenthesis(left-1, right, str+'(', vec);
                dfs_parenthesis(left, right-1, str+')', vec);
        }
    }
};