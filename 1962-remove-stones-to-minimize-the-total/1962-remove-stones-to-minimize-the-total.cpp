class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;

        for(int i = 0 ; i < piles.size()  ; i++){
            pq.push(piles[i]);
        }


        for(int i = 0 ; i < k ; i++){
            int pile = pq.top();
            pq.pop();
            
            pile = pile-floor(pile/2);

            pq.push(pile);
        }

       

        for(int i = 0 ; i < piles.size(); i++){
            ans += pq.top();

            
            pq.pop();
        }

        return ans;
    }
};