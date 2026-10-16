class Solution {
public:
    vector<long long> sm, sq, lz;
    
    void applyNode(int node, int len, long long v) {
        sq[node] += 2 * v * sm[node] + (long long)len * v * v;
        sm[node] += (long long)len * v;
        lz[node] += v;
    }
    
    void push(int node, int l, int r) {
        if (lz[node] != 0) {
            int mid = (l + r) / 2;
            applyNode(2*node, mid - l + 1, lz[node]);
            applyNode(2*node+1, r - mid, lz[node]);
            lz[node] = 0;
        }
    }
    
    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applyNode(node, r - l + 1, v);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr, v);
        update(2*node+1, mid+1, r, ql, qr, v);
        sm[node] = sm[2*node] + sm[2*node+1];
        sq[node] = sq[2*node] + sq[2*node+1];
    }
    
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        sm.assign(4*n, 0);
        sq.assign(4*n, 0);
        lz.assign(4*n, 0);
        
        vector<int> last(100001, -1);
        long long total = 0;
        
        for (int j = 0; j < n; j++) {
            int p = last[nums[j]];
            update(1, 0, n-1, p + 1, j, 1);
            last[nums[j]] = j;
            total = (total + sq[1]) % MOD; // entries beyond j are still 0
        }
        
        return (int)total;
    }
};