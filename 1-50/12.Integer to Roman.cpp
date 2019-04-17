/*--------------------1st--------------------*/
/*
 * The fastest solution need we find every conditions when need use subtraction
 * such as IX CM etc. Other contions only need to use add operation:
 * For example : 
 * 		900 can be found in array, but 800 need to be decomposed into DCCC.
 *
 */
string intToRoman(int num) {
    string ret = "";
    array<int,13> arr1 ={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    array<string,13> arr2 ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    for(int i = 0; i < arr1.size(); ++i){
        while(num >= arr1[i]){
            num -= arr1[i];
            ret += arr2[i];
        }
    }return ret;  
}
/*--------------------2nd--------------------*/
string intToRoman(int num) {
	/*
	 * to be continued
	 */
    array<string,7> roman{"I","V","X","L","C","D","M"};
    vector<string> str(4);
    for(int i=0,j=0; i<roman.size(); i+=2,j++){
        int tmp = num%10;
        if(tmp%5==4){
            str[j] = roman[i]+roman[i+1+tmp/5];
        }else{
            string s;
            if(tmp/5==1){
                s.append(roman[i+1]);
            }
            for(int a=0; a<tmp%5; a++){
                s.append(roman[i]);
            }
            str[j] = s;
        }
        num /= 10;
    }
    string ret =  str[3]+str[2]+str[1]+str[0];
    return ret;
}