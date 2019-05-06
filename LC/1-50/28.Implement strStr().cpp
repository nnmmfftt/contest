/*--------------------1st--------------------*/
class Solution {
public:
    int strStr(string haystack, string needle) {
    	/*
    	 * C++ stl find function.
    	 */
        return haystack.find(needle) == haystack.npos? 
        					-1 :haystack.find(needle);
    }
};
/*--------------------2nd--------------------*/
class Solution {
public:
    int* check(const char *strin){
    	/*
    	 * An array to store the needle's auxiliary array
    	 * @compute the each substring;s palindrome of needle.
    	 */ 
    	int len = strlen(strin);
    	int i = 0;
    	int j = -1;
    	int *match = (int*)malloc(sizeof(int)*(len+1));
    	memset(match, 0, sizeof(match));
    	match[0] = -1;
    	while(i < len){
    		if(j == -1 || strin[i] == strin[j])
    			match[++i] = ++j;
    		else j = match[j];
    	}
    	return match;

    }
    int strStr(string haystack, string needle) {
    	/*
    	 * KMP
    	 */
        if(needle.size() == 0) return 0;
    	int *match = check(needle.c_str());
        int lenstr_orignal = haystack.size();
        int lenstr_in = needle.size();
        int i = 0;
        int j = 0;
        while(i < lenstr_orignal && j < lenstr_in){
        	if(j == -1 || haystack[i] == needle[j]){
        		++i;
        		++j;
        	}
        	else{
        		j = match[j];
        	}
        }
        if(j == lenstr_in){
        	return i-j;
        }
        else
        	return -1;
    }
};