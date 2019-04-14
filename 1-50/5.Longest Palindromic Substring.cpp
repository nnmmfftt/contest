/*--------------------1st--------------------*/
string longestPalindrome(string s) {
	
	 /* dynamic programing:
	 * Let's start at the right:
	 * j from right to i,
	 * i from init j position j(s[s.size()-1]) to 0,
	 * if we find the s[i] == s[j], we set dp[i][j] equals 1,
	 * -> if i+1 < j means we have a string whicn length is 
	 *    3(min) to string's length(max) and now we check if
	 *    dp[i+1][j-1] is a palindrome. 
	 * -> if i+1 equals j, we can only check two chars.
	 * else, we move the j left until i's position.
	 *       Then move the i one left step and reset the j to string's
	 *			right.
	 */
	int s_len = s.size();
	int dp[s_len][s_len];
	memset(dp,0,s_len);
	/*
	 * use dp[][] = {0} to init will call memset
	 */
	for(int i = 0; i < s_len; i++){
		dp[i][i] = 1;
	}
	int len = -1;
	int pos = 0;
	for(int i = s_len-2; i >= 0; --i){
		for(int j = s_len-1; j > i; --j){
			if(i+1 == j){
				dp[i][j] = s[i] == s[j];
			}
			if(i+1 < j){
				dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
			}
			if((len < j-i+1) && dp[i][j]){
				len = j-i+1;
				pos = i;
			}

		}
	}return s.substr(pos, len);  
}

/*--------------------2nd--------------------*/
string longestPalindrome(string s) {
    if(s.size() <2) return s;
    /*
     * However, we can build dp array bottom-up.
     */
    int s_len = s.size();
    int dp[s.size()][s.size()];
    memset(dp,0,sizeof(dp));

    for (int i = 0; i < s_len; ++i) {
        dp[i][i] = 1;
    }
    int maxlen = 1;
    int pos = 0;
    for (int i = 1; i < s_len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j + 1 == i) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1;
                }
            }
            if (j + 1 < i) {
                dp[i][j] = (s[i] == s[j]) && dp[i - 1][j + 1];
            }
            if (maxlen < (i - j + 1)&&dp[i][j]) {
                pos = j;
                maxlen = i - j + 1;
            }
        }
    }return s.substr(pos, maxlen);
}   

/*--------------------3rd--------------------*/
string longestPalindrome(string s) {
	/*
	 * Now we have a surperb method to decrease complexity
	 * In dynamic programming, we need a array to store dp every
	 * substring, but we only need know longset palindrome.
	 *
	 * "Manacher" now will be a good method.
	 * 1st. Insert a tag that does not appear in a given string.
	 * ex:  for even : # a # b # a # b # 
	 *		for  odd : # a # b # a #
	 * Everyone konws odd and even make the string tricky.
	 * After insert we will get an odd length string 
	 * 
	 *
	 * Because of half array used, and complexity is O of n,
	 * costs 10ms and will beats 99%. we only need traverse
	 * given string one time.
	 * Manacher algorithm: https://en.wikipedia.org/wiki/Longest_palindromic_substring
	 */
	string t= "$#";
	/*
	 * The first is a tag that does not appear in the modified string.
	 */
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    int p[t.size()];
    memset(p,0,sizeof(p));
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);

}
 
