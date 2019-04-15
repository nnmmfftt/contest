class Solution {
public:
    string convert(string s, int numRows) {
        /**
         *
         * First of all, we need to know the time to change directions.
         * When we turn round and walk sideways until we go back to the
         * first row: 
         * 
         * The first column is numRows, the second we walk 
         * sideways is numRows-2, Hurray we got 2*numRows-2 is every round.
         * 2*numsRows-2.
         * Now we have a chear code:
         */
        if (numRows <2) return s;
        vector<string> str_vec(numRows);
        int pos = 2*numRows-2;
        int tmp;
        int ch_pos = 0;
        while(ch_pos < s.size()){
        /*
         * check every character
         */
            tmp = ch_pos %pos;
            if(tmp >= numRows){
                /*
                 * check walk in columns or sideways and write in the correct rows.
                 */
                tmp = pos-tmp;
                str_vec[tmp] += s[ch_pos];
            }
            else{
                str_vec[tmp] += s[ch_pos];
            }
            ch_pos++;
        }
        s="";
        for(auto i :str_vec) s+=i;
        return s;
    }
};
