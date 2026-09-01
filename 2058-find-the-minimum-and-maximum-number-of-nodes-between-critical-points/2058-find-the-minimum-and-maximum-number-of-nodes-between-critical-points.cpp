/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        vector<int> list;

        while(head){
            list.push_back(head->val);
            head = head->next;
        }

        if(list.size() <= 2) return ans = {-1 , -1};

        vector<int> points;

        for(int i =1 ; i < list.size()-1; i++){
            int pre = list[i-1];
            int next = list[i+1];

            if(pre < list[i] && list[i] > next || pre > list[i] && list[i] < next) points.push_back(i+1);           
            
        }

        if(points.size() < 2 ) return {-1 , -1};

        for(int val : points){
            cout << val << " " ;
        }
        int mindist = INT_MAX , maxdist;
        sort(points.begin() , points.end());

        for(int i = 1 ; i < points.size(); i++){
            mindist = min(mindist , points[i]-points[i-1]);
        }

        maxdist = points[points.size()-1] - points[0];



        return ans = {mindist , maxdist} ;

    }
};