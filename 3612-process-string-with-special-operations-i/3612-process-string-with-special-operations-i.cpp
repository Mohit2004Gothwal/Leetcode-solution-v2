class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto it : s){
            if(it == '*'){
                if(res.size()){
                    res.pop_back();
                }
            }else if(it == '#'){
                res += res;
            }else if(it == '%'){
                res = string(res.rbegin(), res.rend());
            }else{
                res += it;
            }
        }
        return res;
    }
};