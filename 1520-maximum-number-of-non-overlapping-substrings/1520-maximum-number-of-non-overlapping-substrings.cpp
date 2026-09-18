class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        // Compute the closure interval for each character:
        // the smallest interval starting at first[c], ending at last[c],
        // expanded until it's self-contained (contains all occurrences
        // of every character that appears inside it).
        vector<pair<int,int>> charInterval(26, {-1,-1});
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int lo = first[c], hi = last[c];
            bool changed = true;
            while (changed) {
                changed = false;
                for (int k = lo; k <= hi; k++) {
                    int cc = s[k] - 'a';
                    if (first[cc] < lo) { lo = first[cc]; changed = true; }
                    if (last[cc] > hi) { hi = last[cc]; changed = true; }
                }
            }
            charInterval[c] = {lo, hi};
        }
        
        // Collect distinct closure intervals
        set<pair<int,int>> distinctSet;
        for (int c = 0; c < 26; c++) {
            if (charInterval[c].first != -1) distinctSet.insert(charInterval[c]);
        }
        vector<pair<int,int>> intervals(distinctSet.begin(), distinctSet.end());
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        
        // Build a containment forest (these intervals form a laminar family:
        // any two either nest or are disjoint, never partially overlap).
        int m = intervals.size();
        vector<int> parent(m, -1);
        vector<vector<int>> children(m);
        vector<int> stkIdx;
        for (int i = 0; i < m; i++) {
            while (!stkIdx.empty() && intervals[stkIdx.back()].second < intervals[i].second) {
                stkIdx.pop_back();
            }
            if (!stkIdx.empty()) {
                parent[i] = stkIdx.back();
                children[stkIdx.back()].push_back(i);
            }
            stkIdx.push_back(i);
        }
        
        vector<int> roots;
        for (int i = 0; i < m; i++) if (parent[i] == -1) roots.push_back(i);
        
        // For each node: either take it whole (1 substring), or use its
        // children's best selections instead. Prefer more substrings;
        // on a tie in count, prefer smaller total length.
        function<tuple<int,int,vector<int>>(int)> solve = [&](int idx) -> tuple<int,int,vector<int>> {
            int childCount = 0, childLen = 0;
            vector<int> childList;
            for (int ch : children[idx]) {
                auto [cc, cl, clist] = solve(ch);
                childCount += cc;
                childLen += cl;
                for (int x : clist) childList.push_back(x);
            }
            int rootLen = intervals[idx].second - intervals[idx].first + 1;
            if (childCount > 1) return {childCount, childLen, childList};
            if (childCount == 1) {
                if (childLen < rootLen) return {childCount, childLen, childList};
                else return {1, rootLen, vector<int>{idx}};
            }
            return {1, rootLen, vector<int>{idx}};
        };
        
        vector<int> resultIdx;
        for (int r : roots) {
            auto [cc, cl, clist] = solve(r);
            for (int x : clist) resultIdx.push_back(x);
        }
        
        vector<string> result;
        for (int idx : resultIdx) {
            result.push_back(s.substr(intervals[idx].first, intervals[idx].second - intervals[idx].first + 1));
        }
        return result;
    }
};