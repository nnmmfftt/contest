#include<bits/stdc++.h>
using namespace std;
struct trie{
	int val;
	trie *next[26];
	trie(){
		val = 0;
		memset(next, 0, sizeof(next));
	}
}Trie;

int trie_insert_str(Trie *root, string s){
	int len = s.size();
	if(len == 0)
		return ;
	for(int i = 0; i < len; ++i){
		if(root->next[s[i] -'a'] == NULL){
			root->next[s[i] - 'a'] = new struct trie;
		}
		if(!root->next[s[i] - 'a'])
			goto out;
		root = root->next[s[i] - 'a'];
		root->val++;
	}
	return 0;
out:
	return -1;
}

string max_match(Trie *root, string s){
	int len = s.size();
	string ret;
	if(len == 0)
		return 0;
	for(int i = 0; i < len; ++i){
		if(root->next[s[i] - 'a'] == NULL)
			return false;
		ret = s.substr(0, root->next[s[i] - 'a']->val);
		root = root->next[s[i] - 'a'];
	}
	return true;
}
int trie_max_prefix(Trie *root, string s){
	int len = s.size();
	if(len == 0)
		return 0;
	for(int i = 0; i < len; ++i){
		if(root->next[s[i]-'a'] ==NULL)
			return 0;
		root = root->next[s[i] -'a'];
	}
	return root->val;
}

int match(Trie *root, string s){
	int len = s.size();
	if(len == 0)
		return 0;
	for(int i = 0; i <len; ++i){
		if(root->next[s[i] - 'a'] == NULL)
			return false;
		else root = root->next[s[i] - 'a'];
	}
	return true;
}

int trie_delete_str(Trie *root, string s){
	int len = s.size();
	if(len == 0) return 0;
	for(int i = 0; i < len; ++i){
		if(root->next[s[i] - 'a'] == NULL){
			return;
		}
		root = root->next[s[i] -'a'];
		root->val--;
		if(root->val == 0){
			delete root;
			root = NULL;
		}
	}return 0;
}

int main(){
	trie *root = new Trie();
	vector<string> strs = {"banana","ban","bank","abort","abs"};
	for(int i = 0; i < strs.size(); ++i){
		int rc = trie_insert_str(root, strs[i]);
		if(rc != -1)
			continue;
		else break;
	}
	int m;
	cin >> m;
	while(m--){
		string stmp;
		cin >>stmp;
		cout <<trie_max_prefix(stmp)<<endl;
	}
	return 0;
}