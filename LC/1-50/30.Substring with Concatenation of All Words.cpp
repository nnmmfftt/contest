class Solution {
public:
	vector findSubstring(string s, vector& words) {
		/* 
		 * Compute all the possibilities is much complexity.
		 * Then use a hash map to store the words and check every
		 * words in s.
		 * The more important is @words, words, that are all of the
		 * same length.
		 *
		 * If the words' length is n, words array have k words
		 * then the string length is n*k.
		 * The string's position will in :
		 *  [0, s.size() - n*k +1]
		 *  ->
		 *	[0, s.size() - words.size()*len +1] 
		 * 
		 * Then the "foobarfoobar" can be traverse:
		 * [foobar, oobarf, obarfo, barfoo, arfoob, rfooba, foobar]
		 * And check every element is made from words.
		 *
		 */
		unordered_map<string, int> counts;
		for (string word : words)
			counts[word]++;
		int n = s.length(), num = words.size(), len = words[0].length();
		vector indexes;
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				string word = s.substr(i + j * len, len);
				if (counts.find(word) != counts.end()) {
					seen[word]++;
					if (seen[word] > counts[word])
						break;
				}
				else break;
			}
			if (j == num) indexes.push_back(i);
		}
		return indexes;
	}
};