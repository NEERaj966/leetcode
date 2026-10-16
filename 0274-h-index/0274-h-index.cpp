class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int maxcit = 0;

        for(int i = 0 ; i < citations.size(); i++){
            int idx = citations.size()-i;

            if(idx <= citations[i]){
                return idx;
            }
        }

        return 0;
    }
};