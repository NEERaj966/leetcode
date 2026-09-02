class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> freq;

        for(auto x : s){
            freq[x]++;
        }

        string ans = "";

       priority_queue<pair<int , char>> pq;

        for(auto  x : freq){
            pq.push({x.second , x.first});
        }

        while(!pq.empty()){
            pair<int , char> p = pq.top();
            pq.pop();

            int fr = p.first;
            int child = p.second;

            if(!ans.empty() && ans.back() == child){

                if(pq.empty()) return "";

                auto[fr2 , child2] = pq.top();
                pq.pop();

                ans += child2;
                fr2--;

                if(fr2>0) pq.push({fr2 , child2});

                pq.push({fr , child});
            }else{
                ans += child;
                fr--;

                if(fr > 0) pq.push({fr , child});
            }
        }

        return ans;
    }
};