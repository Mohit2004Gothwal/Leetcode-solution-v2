class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi = 1;
        long long n = nums.size();
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                long long dem = gcd(nums[i],nums[j]);
                long long num = nums[i] / dem;
                long long den = nums[j]/dem;
              long long val = num*den;
            if(val >= maxi){
                maxi = val;
            }
            }
        }
        return maxi;
    }
};