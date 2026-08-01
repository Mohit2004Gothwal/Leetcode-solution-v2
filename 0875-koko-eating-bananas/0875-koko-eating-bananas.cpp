class Solution {
public:
    bool canFinish(const vector<int>& piles , int h  , int k){
        long long hrs = 0;
        for(int pile : piles){
            hrs += pile/k;
            if(pile %k != 0) hrs++;
            if(hrs>h)return false;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(),piles.end());
        int left =1;
        int ans = right;
        while(left <= right){
            int mid =left +  (right - left)/2;
            if(canFinish(piles, h , mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        return ans;
    }
};