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
    int* check(const char *needle){
    	/*
    	 * An array to store the needle's auxiliary array
    	 * @compute the each substring;s palindrome of needle.
    	 */ 
    	int len = strlen(needle);
    	int i = 0;
    	int j = -1;
    	int *match = (int*)malloc(sizeof(int)*(len+1));
    	memset(match, 0, sizeof(match));
    	match[0] = -1;
    	while(i < len){
    		if(j == -1 || needle[i] == needle[j])
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
/*--------------------3rd--------------------*/
class Solution {
public:
	int *strstr_match_helper(char *needle, int *match){
		int i = 0;
		int j, pos;
		int len = strlen(needle);
		while(needle[i] == needle[i+1]&&i+1<len)
			++i;
		pos = 1;
		for(i = 0; i < len; ++i){
			if(match[i-pos]+i<match[pos]+pos)
				match[i] = match[i-pos];
			else{
				j = match[pos]+pos-i;
				if(j < 0) j = 0;
				while(i+j < len && needle[j] == needle[j+i])
					j++;
				match[i] = j;
				pos = j;
			}
		}return match;

	}
    int strStr(string haystack, string needle) {
    	int i = 0;
    	int j, pos;
    	int len_str_original = strlen(haystack);
    	int len_str_in = strlen(needle);
    	int *match = (int *)malloc(sizeof(int)*2*(len_str_in+1));
    	match = strstr_helper(needle, match);
    	while(haystack[i] == needle[i] && i < len_str_orignal 
    								&& i < len_str_in)
    		++i;
    	int  offset = len_str_in+1;
    	match[offset +0] = i;
    	pos = 0;
    	for(i = 1; i < len_str_original; ++i){
    		if(match[i-pos]+i < match[offset +pos]+pos)
    			match[offset +i] = match[i-pos];
    		else{
    			j = match[offset +pos] +pos-i;
    			if(j<0) j = 0;
    			while(i+j < len_str_original && j < lenstr_in 
    										&& haystack[j+i] == needle[j])
    				j++;
    			match[offset+i] = j;
    			pos =  i;
    		}
    	}return pos;

    }
};