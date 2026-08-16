class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
    //    vector<int>time;
    int penalty = 0;
       int maxi = *max_element(lights.begin(),lights.end());
        for(int i=0;i<arrivalTime.size();i++){
            int ct = arrivalTime[i];
            int r = ct%period;
            if(r < maxi){
                penalty = max(penalty , 0);

            }else
            {
                penalty = max(penalty , period -r);
            }
        }
        return penalty;
    }
};