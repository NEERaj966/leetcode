class Solution {
public:

    void mergeSort(vector<pair<int,int>>& arr,
                   vector<int>& ans,
                   int left,
                   int right) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, ans, left, mid);
        mergeSort(arr, ans, mid + 1, right);

        vector<pair<int,int>> temp;

        int i = left;
        int j = mid + 1;

        int rightSmaller = 0;

        while (i <= mid && j <= right) {

            if (arr[j].first < arr[i].first) {
                temp.push_back(arr[j]);
                rightSmaller++;
                j++;
            }
            else {
                ans[arr[i].second] += rightSmaller;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += rightSmaller;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        // {value, original index}
        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, ans, 0, n - 1);

        return ans;
    }
};