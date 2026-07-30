class Solution {
public:

    // First 8 letters push 1 time 
    // Next 8 letters push 2 time
    //  Next 8 letters push 3
    // Next 8 letters push 4 time

    // cost is simply (i/8)+1;
    int minimumPushes(string word) {
      int cost = 0;
      for(int i=0;i<word.size();i++){
        cost += (i/8)+1;
      }
      return cost;
        
    }
};