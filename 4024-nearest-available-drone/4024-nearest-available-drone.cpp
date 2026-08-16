// #include<bits/stdc++.h>
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ind = -1,mini =INT_MAX;
        for(int i=0;i<drones.size();i++){
            int xi = drones[i][0];
            int yi = drones[i][1];
            int r =  drones[i][2];
            int dis = abs(target[0] - xi) + abs(target[1]-yi);
            if(dis <= r){
               if(mini > dis){
                mini = dis;
                ind = i;
               }
            }
        }
        return ind;
    }
};