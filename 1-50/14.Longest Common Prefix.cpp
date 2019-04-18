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
