class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // first approach two pointer O(n)

        int n = numbers.size();

           int i = 0  , j = n-1;

           while(i <= j ){
            int ans = numbers[i]+numbers[j];

            if(target == ans) return {i+1 , j+1};

            else if(target > ans) i++;
            else j--;
           }

           return {i , j};

      
        
    }
};