/*--------------------1st--------------------*/
int reverse(int x) {
	/*
	 * We use C++ stl to reverse string and handle the
	 * '-' and 0. It can beats 91% 
	 */
    string s = to_string(x);
    std::reverse(s.begin(),s.end());
    int rc = s[s.size()-1]=='-'?1:0;
    while(*s.rbegin() =='-'||*s.rbegin()=='0'){
        s = s.substr(0,s.size()-1);
    }
    s = rc ==1?"-"+s:s;
    int ma = 0x7fffffff;
    int mi = 0x80000000;
    long ret = atol(s.c_str());
    if( ret <= ma&&ret >=mi){
        return ret;
    }
    else return 0;
}
/*--------------------2nd--------------------*/
int reverse(int x) {
	/*
	 * Or build a number from b
	 */
    if(x == 0)return x;
    int flag = x <0? 1:0;
    long long x_l =x;
    x_l = x_l >0?x_l:-x_l;
    long ret = 0;
    while(x_l>0){
        ret = ret*10+x_l%10;
        x_l/=10;
    }
    if(flag == 0){
        if(ret >=0x7fffffff)return 0;
        else return (int)ret;
    }
    else{
        if(ret > 0x7fffffff)return 0;
        else return -(int)ret;
    }
    return 927;//shouldn't be here.
}