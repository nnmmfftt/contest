# #include<bits/stdc++.h>

# using namespace std;

# vector<int> findsubstring(string s, vector<string> &words){
# 	if(words.size() == 0) return vector<int>{};
# 	unordered_map<string, int> count;
# 	for(string word : words)
# 		counts[word]++;
# 	int n = s.length();
# 	int num = words.size();
# 	int len = words[0].size();
# 	vector<int> index;
# 	for(int i = 0; i < n-num*len+1; ++i){
# 		unordered_map<string, int> seen;
# 		int j = 0;
# 		for(; j< num; ++j){
# 			string word = s.substring(i + j*len, len);
# 			if(counts.find(word) != counts.end()){
# 				seen[word] ++;
# 				if(seen[word] > counts[word])
# 					break;
# 			}
# 			else break;
# 		}
# 		if(j == num) index.push_back(i);
# 	}
# 	return index;
# }
def findsubstring(s, words):
	from collections import Counter
	if not s or not words: return[]
	one_word = len(words[0])
	all_len = len(words) * one_word
	n = len(s)
	words = Counter(words)
	res = []
	for i in range(0, n - all_len +1):
		tmp = s[i:i+all_len]
		c_tmp = []
		for j in range(0, all_len, one_word):
			c_tmp.append(tmp[j:j+one_word])
		if Counter(c_tmp) == words:
			res.append(i)
	return res