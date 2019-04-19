int lengthOfLongestSubstring(string s) {
	/*
	 *  using hashmap recording the char which
	 *  between the pointer left & right.
	 *  when find a char has been recorded in
	 *  map, clean the map and update the max length.
	 *  Update the new substring index at the char first
	 *  disappeared position+1. 
	 */ 
    if(!s.size()) return NULL;
    unordered_map<char, int> m;
    int left = 0, right = 0;
    int len = -1;
    int tmp = 0;
    while (left < s.size()  && right < s.size() ) {
        if (m[s[right]]) {
            left = s.find(s[right], left) + 1;
            len = tmp>len?tmp:len;
            tmp = 1;
            right = left;
            m.clear();
            m[s[right++]] = 1;
            
        }
        else {
            m[s[right++]] = 1;
            tmp++;
        }
    }return len > tmp?len:tmp;
}

