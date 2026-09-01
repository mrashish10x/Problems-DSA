class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<char>> grid(m, vector<char>(n));
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));
        int sr = -1, sc = -1, L = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = classroom[i][j];
                if (grid[i][j] == 'S') { sr = i; sc = j; }
                if (grid[i][j] == 'L') litterIndex[i][j] = L++;
            }
        }
        
        int fullMask = (1 << L) - 1;
        int E = energy;
        
        auto encode = [&](int r, int c, int e, int mask) -> int {
            return (((r * n + c) * (E + 1) + e) * (1 << L)) + mask;
        };
        
        int totalStates = m * n * (E + 1) * (1 << L);
        vector<char> visited(totalStates, 0);
        
        queue<array<int,4>> q; // r, c, e, mask
        int startEnc = encode(sr, sc, energy, 0);
        visited[startEnc] = 1;
        q.push({sr, sc, energy, 0});
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int iter = 0; iter < sz; iter++) {
                auto cur = q.front(); q.pop();
                int r = cur[0], c = cur[1], e = cur[2], mask = cur[3];
                
                if (mask == fullMask) return steps;
                if (e == 0) continue; // stuck, can't move further
                
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 'X') continue;
                    
                    int ne = (grid[nr][nc] == 'R') ? energy : (e - 1);
                    int nmask = mask;
                    if (grid[nr][nc] == 'L') {
                        int idx = litterIndex[nr][nc];
                        nmask |= (1 << idx);
                    }
                    
                    int st = encode(nr, nc, ne, nmask);
                    if (!visited[st]) {
                        visited[st] = 1;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};