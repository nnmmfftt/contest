int myAtoi(string str) {
	if(str.size()==0) return 0;
	int len = 0;
	int flag = 1;
	unsigned long k = 0;
	while(str[len]==' ')
			len++;
    if(str[len]=='+'||str[len]=='-'){
        if(str[len]=='-'){
            flag = 0;
        }
        len++;
    }
	if(!isdigit(str[len])) return 0;
	else{
		while(str[len] >='0'&& str[len] <='9'){
			k = k*10 + str[len] - '0';
            if(k >= 0x7fffffff){
                if(flag == 1){
                    return 0x7fffffff;
                }
                else if(flag == 0){
                    if(k > 0x7fffffff) return 0x80000000;
                    else return 0x80000001;
                }
            }
            len++;
		}
		if(flag == 0) return (int)0-k;
    	else return (int)k;
	}
    return 927;//It is a birthday, shouldn't be there
}