#define mod 1000000007
class Solution {
public:
    int binarytodecimal(long long n){
        int decimalval = 0;
        int base = 1;
        while(n>0){
            int lastdigit = n%10;
            n = n/10;
            decimalval += lastdigit *base;
            base = base*2;
        }
        return decimalval%mod;

    }
    int concatenatedBinary(int n) {
    //     string str = "";
    //     for(int i=1;i<=n;i++){
    //         str += bitset<2>(i).to_string();
    //     }
    //     int sz = str.length();
    //    long long sum = binarytodecimal(stoll(str));
    //     return sum%mod;
    long long ans = 0; 
    int bitlength = 0;
    for(int i=1;i<=n;i++){
      // If i is a power of 2, the number of bits required increases by 1
        if((i & (i-1)) == 0){
            bitlength++;
        }

    ans = ((ans << bitlength) + i) % mod;
    }
    return ans;
    }
};