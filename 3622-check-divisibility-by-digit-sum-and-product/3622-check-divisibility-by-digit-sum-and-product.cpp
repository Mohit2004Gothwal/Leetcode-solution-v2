class Solution {
public:
    bool checkDivisibility(int n) {
        if(n<=0)return false;
        // int val = n;
        int val2 = n;
        int prod = 1;
        int sum1 =0;
        while(val2>0){
             int lastdigit = val2%10;
             sum1 += lastdigit;
             prod*=lastdigit;
             val2/=10;
        }
        sum1 += prod;
        if(sum1 ==0)return false;
        return (n%sum1==0);
    }
};