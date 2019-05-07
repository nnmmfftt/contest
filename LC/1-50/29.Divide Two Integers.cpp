class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        int flag = dividend ^ divisor;
        uint32_t ndividend = abs((long)dividend);
        uint32_t ndivisor = abs((long)divisor);
        if(ndivisor == 1) {
            if(flag < 0){
                return -ndividend < 0x80000000? 
                    0x80000000:-ndividend;
            }
            else{
                return ndividend > 0x7fffffff? 0x7fffffff:ndividend;
            }
        }
        while(ndividend >= ndivisor){
            ndividend -=  ndivisor;
            count ++;
        }
        return flag < 0 ? -count:count;
    }
};