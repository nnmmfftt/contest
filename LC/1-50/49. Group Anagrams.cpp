class Solution {
public:
	
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<int>> mp;
        for(int i = 0; i < strs.size(); ++i){
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(i);

            
        }
        auto it = mp.begin();
        while(it!=mp.end()){
            vector<string> tmp;
            for(auto i : it->second){
                tmp.push_back(strs[i]);
            }
            ret.push_back(tmp);
            it++;
        }
        return ret;
        
    }
};