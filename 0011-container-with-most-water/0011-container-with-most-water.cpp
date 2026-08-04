class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0;
        int  end = height.size()-1;

        int ans = 0;
        int maxi = INT_MIN;

        while(st <= end){
            ans = min(height[st] , height[end]) * (end -st);
            if(height[st] > height[end]){
                end--;
            }else{
                st++;
            }

            maxi = max(ans , maxi);
        }

        return maxi;
        
    }
};