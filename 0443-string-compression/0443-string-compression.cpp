class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int count = 1;
        int st = 0;
        string ans = "";

        for (int end = 1; end < n; end++) {

            if (chars[st] == chars[end]) {
                count++;
            } else {
                if (count == 1) {
                    ans += chars[st];
                } else {
                    ans += chars[st];
                    ans += to_string(count);
                }
                st = end;
                count = 1;
            }
        }
        if(count != 1){

        ans += chars[st];
        ans += to_string(count);
        }else{
            ans += chars[st];
        }

        chars = {};

        for(int i = 0 ; i < ans.size() ; i++){
            chars.push_back(ans[i]);
        }
        return ans.size();
    }
};