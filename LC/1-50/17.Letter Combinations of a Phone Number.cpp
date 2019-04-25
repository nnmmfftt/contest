/*--------------------1st--------------------*/
vector<string> letterCombinations(string digits) {
	/*
	 * Use brute force to check every digits, and output all possibilities.
	 */
	unordered_map<int, string> m = {
		{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
	};
	string s = "";
	vector<string> ret;
	vector<int> tmpvec;
	if (!digits.size()) return ret;
	int len = 0;

	if (digits[0] > '0') {
		string tmp;
		tmp = m[digits[0]];
		for (int i = 0; i < tmp.size(); ++i) {
			string tempstr;
			tempstr = tmp[i];
			ret.push_back(tempstr);
		}
	}
	len++;
	string stradd;
	while (len < digits.size()) {
		string tmp = m[digits[len]];
        int vval = ret.size();
		for (int i = 0; i < vval; ++i) {
			for (int j = 0; j < tmp.size();++j) {
				string tempstr;
				tempstr = tmp[j];
				if (j == 0) {
					stradd = ret[i];
					ret[i] += tempstr;
				}
				else {
					string addstr;
					addstr = stradd + tempstr;
					ret.push_back(addstr);
				}
			}
		}
		len++;
	} sort(ret.begin(),ret.end());
      return ret;
}
/*--------------------1st--------------------*/
vector<string> letterCombinations(string digits) {
	/*
	 * Now, the code may make us confused, try to make the code concise.
	 * Turn the hashmap into string vector, etc.
	 */
	vector<string> ret{""};
	if(digits.size() == 0)
		return ret;
	vector<string> letter_map{"","","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	for( auto i : digits){
		vector<string> tmp;
		for(auot j : ret){
			for((auto k : letter_map[i - '0']))
				tmp .push_back(j+k);
			ret = tmp;
		}
	}return ret;

}
/*--------------------2nd--------------------*/
void bfs(vector<string> &ret, string str, string &digits, unordered_map<char, string> &m, int k);
vector<string> letterCombinations(string digits) {
	/*
	 * Brute force is alsways useful but looks like a noob(actually not)
	 * Now some search algorithm: breadth first search. 
	 **/
    unordered_map<char, string> letter_map{
    	{'0', " "}, {'1',"*"}, {'2', "abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
    	{'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"},
    	{'9',"wxyz"}
    };  
    vector<string> ret;
    if(digits == "") return ret;
    bfs(ret, "", digits, letter_map, 0);
    return ret;
}
void bfs(vector<string> &ret, string str, string &digits, unordered_map<char, string> &m, int k){
    if(str.size() == digits.size()){
        ret.push_back(str);
        return;
    }
    string tmp = m[digits[k]];
    for(auto w : tmp){
        str += w;
        bfs(ret, str, digits, m, k+1);
        str.pop_back();
    }
    return ;
}
/*--------------------2nd--------------------*/
vector<string> letterCombinations(string digits) {
    vector<string> letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    if(digits.length()==0)return result;
    string temp;
    dfs(result,letters,digits,0,temp);
    return result;
}

void dfs(vector<string>& result, vector<string>& letters, string digits, int t, string& temp){
    int size = digits.length();
    if(t<size){
        int l = letters[digits[t]-'0'-2].length(),i = 0;
        for(i = 0;i<l;++i){
            temp.push_back(letters[digits[t]-'0'-2][i]);
            dfs(result,letters,digits,t+1,temp);
            temp.pop_back();
        }
    }
    else{
        result.push_back(temp);
    }
}