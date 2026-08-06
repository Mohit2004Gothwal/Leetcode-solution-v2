class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>exclusive(n,0);
        stack<int>st;
        int prev = 0;

        for(auto log : logs){
            stringstream ss(log);
            string id_str,status,time_str;
            getline(ss,id_str , ':' );
            getline(ss,status, ':' );
            getline(ss,time_str , ':' );

            int id = stoi(id_str);
            int time = stoi(time_str);

            if(status == "start"){
                // if a function was already running, credit its active time
                if(!st.empty()){
                    exclusive[st.top()] += (time - prev);
                }
                st.push(id);
                prev = time;
            }else{
                // function ends, credit its time up to the end of this timestamp
                exclusive[st.top()] += (time - prev +1);
                st.pop();
                prev = time+1;
            }
        }
        return exclusive;
    }
};