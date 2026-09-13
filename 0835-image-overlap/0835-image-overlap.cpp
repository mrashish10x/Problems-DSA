class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> onesA, onesB;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) onesA.push_back({i, j});
                if (img2[i][j] == 1) onesB.push_back({i, j});
            }
        }
        
        unordered_map<int, int> count; // encode (dx, dy) as a single int
        int maxOverlap = 0;
        
        for (auto& a : onesA) {
            for (auto& b : onesB) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                int key = (dx + n) * (2 * n + 1) + (dy + n); // unique encoding
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }
        
        return maxOverlap;
    }
};