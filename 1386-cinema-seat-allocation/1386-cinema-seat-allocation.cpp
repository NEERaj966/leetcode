class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
          unordered_map<int, int> rows;

        // Store reserved seats 2-9 as bits
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << (col - 2));
            }
        }

        // Rows with no reservation can fit 2 families
        int ans = (n - rows.size()) * 2;

        // Masks for:
        // 2-5 -> 00001111
        // 4-7 -> 00111100
        // 6-9 -> 11110000
        int left   = 0b00001111;
        int middle = 0b00111100;
        int right  = 0b11110000;

        for (auto &[row, mask] : rows) {

            bool canLeft = (mask & left) == 0;
            bool canMid  = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                ans += 2;
            }
            else if (canLeft || canMid || canRight) {
                ans += 1;
            }
        }

        return ans;

        
    }
};