class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int st = start[0]+start[1];
        int end = target[0]+target[1];

        return (st%2 == 0 && end%2 == 0) || (st%2 != 0 && end%2 != 0);
    }
};