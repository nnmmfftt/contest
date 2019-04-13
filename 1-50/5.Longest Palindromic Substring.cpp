/*----------1st----------*/
string longestPalindrome(string s) {
	/*
	 * dynamic programing:
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
/*----------2nd----------*/
string longestPalindrome(string s) {
	/*
	 * 
	 */
}