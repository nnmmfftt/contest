class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
         * DFS solution:
         * Traverse all possible parenthesis:
         *   Skip the impossible:
         *      left > right :
         *          the right bracket appear before the left.
         *      right > left :
         *          the normal conditions, and recurse.
         *   Terminal: 
         *      left = 0 and right = 0.
         *          means run out of n parenthesis.
         *          Meanwhile, it must be a valid condition.
         *          Add to vector prepare to return.
         *
         *
         */
        vector<string> vec;
        dfs_parenthesis(n, n, "", vec);
        return vec;
    }

    void dfs_parenthesis(int left, int right, string str, vector<string> &vec){
        if(left == right == 0){
            vec.push_back(str);
        }
        if(left < right){
            if(left  > 0)
                dfs_parenthesis(left-1, right, str+'(', vec);
            if(right > 0)
                dfs_parenthesis(left, right-1, str+')', vec);
        }
    }
};