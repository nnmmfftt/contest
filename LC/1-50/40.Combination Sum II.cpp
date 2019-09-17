class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
public:
    void helper(vector<int> &candidates, int pos, int target) {
        if (target == 0) {
            ret.push_back(tmp);
            // a valid solution
            return;
        }
        for (int i = pos; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            if (i > pos && candidates[i] == candidates[i - 1])
                continue;
            tmp.push_back(candidates[i]);

            helper(candidates, i + 1, target - candidates[i]);
            // search for all conditions
            tmp.pop_back();
            // if not, pop the last element and try anathor method.
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return ret;
    }
};