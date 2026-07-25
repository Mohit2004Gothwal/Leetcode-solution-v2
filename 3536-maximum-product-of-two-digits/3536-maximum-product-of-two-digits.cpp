class Solution {
public:
    int maxProduct(int n) {
     string str = to_string(n);
     sort(str.begin(),str.end());
     return (str[str.size()-1]-'0') *((str[str.size()-2]-'0'));
    }
};