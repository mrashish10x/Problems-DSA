class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> arr(n); // l, r, w, idx
        for (int i = 0; i < n; i++) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(arr.begin(), arr.end(), [](const array<long long,4>& a, const array<long long,4>& b){
            return a[1] < b[1]; // sort by r ascending
        });
        
        vector<long long> sortedR(n);
        for (int i = 0; i < n; i++) sortedR[i] = arr[i][1];
        
        struct State {
            long long weight;
            vector<int> idxs;
        };
        
        auto better = [](const State& x, const State& y) -> bool {
            if (x.weight != y.weight) return x.weight > y.weight;
            return x.idxs < y.idxs;
        };
        
        vector<vector<State>> dp(n+1, vector<State>(5, State{0, {}}));
        
        for (int i = 1; i <= n; i++) {
            long long l = arr[i-1][0];
            long long w = arr[i-1][2];
            int origIdx = (int)arr[i-1][3];
            
            int p = (int)(lower_bound(sortedR.begin(), sortedR.end(), l) - sortedR.begin());
            
            for (int t = 0; t <= 4; t++) {
                State best = dp[i-1][t];
                
                if (t >= 1) {
                    State candidate = dp[p][t-1];
                    candidate.weight += w;
                    auto pos = upper_bound(candidate.idxs.begin(), candidate.idxs.end(), origIdx);
                    candidate.idxs.insert(pos, origIdx);
                    
                    if (better(candidate, best)) {
                        best = candidate;
                    }
                }
                
                dp[i][t] = best;
            }
        }
        
        return dp[n][4].idxs;
    }
};