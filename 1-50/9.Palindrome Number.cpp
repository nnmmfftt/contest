/*--------------------1st--------------------*/
/*
 * Using string iterator and compare each bit, and takes 28ms./
 *
 */
bool isPalindrome(int x) {
    if(x<0)
        return false;
    if(x==0)
        return true;
    string tmp=to_string(x);
    int left=0,right=tmp.size()-1;
    while(left<right)
    {
        if(tmp[left]!=tmp[right])
            return false;
        ++left;
        --right;
    }
    return true;
}
/*--------------------2nd--------------------*/
bool isPalindrome(int x) {
    /*
     * Build from given number each bit, but takes a bit longer than 1st(68ms).
     */
    if(x < 0) return false;
    else {
        long num = 0;
        int tmp = x;
        while(tmp>0){
            num = num*10 + tmp%10;
            tmp /= 10;
        }return x == num?true:false;
    }
    return 927;//shouldn't be there
}