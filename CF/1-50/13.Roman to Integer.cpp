/*--------------------1st--------------------*/
int romanToInt(string s) {
	/*
	 * Compare to 12, it will be much simpler, a hash table with O(1) lookup rate,
	 * and consider these two situatuations,
	 * The Roman bit we checking correspond a decimal value:
	 * 1. The value of previous Roman digit less than the current digit
	 * But only one Roman bit larger than current Roman bit.
	 * So add every Roman bit's decimal value from low to high, and minus when the previous bit's value less than current.
	 *
	 */
    unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ret = 0;
    for(int i = 0 ; i <s.size();++i){
        int tmp = m[s[i]];
        if(size()-1|| m[s[i+1]]<= tmp) ret+=tmp;
        else ret-=tmp;
    }return ret;
}