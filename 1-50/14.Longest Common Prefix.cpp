/*
 * There are many solutions about this case, 
 * Let's check two representative solutions.
 *
/*--------------------1st--------------------*/
string longestCommonPrefix(vector<string>& strs) {
	/*
	 * First, handle boundary cases.
	 * And then, check every character. If not matching, go to out.
	 * 
	 * Tips:
	 * In a function, goto is hardly makes mistakes.
	 * In a project need use goto in its own function body.
	 */
    if (strs.size() == 0) return "";
    if (strs.size() == 1)
        return strs[0];
    string ret = "";
    for (int i = 0; ; ++i) {
        char tmp = strs[0][i];
        for (int j = 1; j< strs.size(); ++j) {
            if (strs[j].size() > i) {
                if (tmp != strs[j][i])
                    goto out;
            }
            else
                goto out;
        }
        ret += tmp;
    }
end:
    return ret;
}
/*--------------------2nd--------------------*/
struct Trie
{
	Trie *next[26];
	int count;
}trie;
void insert(string s){
	Trie *p= root, *tmp;
	for(int i = 0; i < s.size(); ++i){
		int t = s[i]-'a';
		if(p->next[t] == NULL){
			tmp = new Trie;
			tmp->count = 1;
			for(int j = 0; j < 26; ++j){
				tmp->next[j] = NULL;
			}
			p->next = tmp;
		}
		else {
			p->next[t]->count++;
		}
	}
}
int search(string s,string ret){
	Trie *p = root;
	bool find_val = 0;
	for(int i = 0; i < s.size(); ++i){
		int t = s[i] -'a';
		if(p->next[t] == NULL) 
			return 0;
		if(p->next[t] -> count == n){
			ret = s.substr(0,i+1);
			find_val = 1;
		}
		p = p->next[t];
	}
	return find_val;
}

void init(){
    root = new Trie;
    root->count = 0;
    for(int i = 0;i < 26;++ i){
        root->next[i] = NULL;
    }
}

string longestCommonPrefix(vector<string>& strs) {
	string ret = "";
	n = strs.size();
	if (!n) 
		return ret;
	init();
	for (int i = 0;i < n;++ i){
		insert(strs[i]);
	}
	if (!search(strs[0],ret)) return ans = "";
  return ans;
}