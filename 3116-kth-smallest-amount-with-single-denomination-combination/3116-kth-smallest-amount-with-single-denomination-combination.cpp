class Solution {
public:
    long long gcd(long long a , long long b){
        if(b ==0)return a;
        return gcd(b,a%b);
    }
    long long lcm(long long a, long long b){
        return (a/gcd(a,b))*b;
    }
    long long countMultiples(long long mid , vector<int>& coins){
        long long count =0;
        int n = coins.size();

        int total =1<<n;
        for(int mask =1;mask<total ;mask++){
            long long currentLCM = 1;
            int eleInSubset = 0;
            bool overflow = false;
            for(int i=0;i<n;i++){
                if((mask >>i) & 1){
                    eleInSubset++;
                    currentLCM = lcm(currentLCM , coins[i]);
                    if(currentLCM > mid){
                        overflow = true;
                        break;
                    }
                }
            }
           if(overflow)continue;
           if(eleInSubset %2 ==1){
            count += mid/currentLCM;
           }else{
            count -= mid/currentLCM;
           }
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low =1;
        long long mincoin = *min_element(coins.begin(),coins.end());
        long long high = mincoin*k;
        long long ans = high;

        while(low <= high){
            long long mid = low + (high - low)/2;
            if(countMultiples(mid , coins)>= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
         return ans;
    }
};