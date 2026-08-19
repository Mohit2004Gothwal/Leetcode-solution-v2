class Solution {
public:
    int count(int i,vector<vector<int>>& seat){
        int cnt =0;
        if(seat[i][1] == 0 && seat[i][2] == 0 && seat[i][3]==0 && seat[i][4]==0){
            seat[i][1] = 1;
            seat[i][2] = 1;
            seat[i][3] = 1;
            seat[i][4] = 1;
            cnt++;
        } 
        if(seat[i][3] == 0 && seat[i][4] == 0 && seat[i][5]==0 && seat[i][6]==0){
              seat[i][5] = 1;
              seat[i][6] = 1;
              cnt++;
        } 
        if(seat[i][5] == 0 && seat[i][6] == 0 && seat[i][7]==0 && seat[i][8]==0) cnt++;
        return cnt;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      unordered_map<int,int>reserved;
      for(auto seat : reservedSeats){
        int row = seat[0];
        int col = seat[1];
        reserved[row] |= (1<<col);
      }
      long long total = 2LL* (n- reserved.size());
      for(auto it : reserved){
        int row = it.first;
        int mask = it.second;

        bool left = !(mask & (1<<2)) && !(mask & (1<<3)) && !(mask & (1<<4)) && !(mask & (1<<5));
        bool mid  = !(mask & (1<<4)) && !(mask & (1<<5)) && !(mask & (1<<6)) && !(mask & (1<<7));
        bool right =!(mask & (1<<6)) && !(mask & (1<<7)) && !(mask & (1<<8)) && !(mask & (1<<9));
        
        if(left && right){
            total +=2;
        }else if(left|| right || mid){
            total +=1;
        }
      }
      return total;
    }
};