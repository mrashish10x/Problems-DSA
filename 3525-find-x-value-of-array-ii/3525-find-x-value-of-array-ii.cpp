const int MAXK = 5;

struct Node {
    int g[MAXK];
    long long cnt[MAXK][MAXK];
};

class Solution {
public:
    int K, n, sizeN;
    vector<Node> tree;
    
    void makeLeaf(Node &nd, int val) {
        int v = val % K;
        for (int r = 0; r < K; r++) {
            int c = (r * v) % K;
            nd.g[r] = c;
            for (int cc = 0; cc < K; cc++) nd.cnt[r][cc] = (cc == c) ? 1 : 0;
        }
    }
    
    void combine(const Node &L, const Node &R, Node &res) {
        for (int r = 0; r < K; r++) {
            int mid = L.g[r];
            res.g[r] = R.g[mid];
            for (int c = 0; c < K; c++) {
                res.cnt[r][c] = L.cnt[r][c] + R.cnt[mid][c];
            }
        }
    }
    
    void build(vector<int>& nums) {
        n = nums.size();
        sizeN = 1;
        while (sizeN < n) sizeN <<= 1;
        tree.assign(2 * sizeN, Node());
        for (int i = 0; i < n; i++) makeLeaf(tree[sizeN + i], nums[i]);
        // Pad remaining leaves with the identity element (contributes nothing)
        for (int i = n; i < sizeN; i++) {
            Node &nd = tree[sizeN + i];
            for (int r = 0; r < K; r++) {
                nd.g[r] = r;
                for (int c = 0; c < K; c++) nd.cnt[r][c] = 0;
            }
        }
        for (int i = sizeN - 1; i >= 1; i--) combine(tree[2*i], tree[2*i+1], tree[i]);
    }
    
    void update(int idx, int val) {
        int pos = sizeN + idx;
        makeLeaf(tree[pos], val);
        pos >>= 1;
        while (pos >= 1) {
            combine(tree[2*pos], tree[2*pos+1], tree[pos]);
            pos >>= 1;
        }
    }
    
    Node query(int l, int r) {
        vector<Node> leftParts, rightParts;
        l += sizeN; r += sizeN + 1; // [l, r)
        while (l < r) {
            if (l & 1) { leftParts.push_back(tree[l]); l++; }
            if (r & 1) { r--; rightParts.push_back(tree[r]); }
            l >>= 1; r >>= 1;
        }
        Node result;
        bool has = false;
        for (auto &nd : leftParts) {
            if (!has) { result = nd; has = true; }
            else { Node tmp; combine(result, nd, tmp); result = tmp; }
        }
        for (int i = (int)rightParts.size() - 1; i >= 0; i--) {
            if (!has) { result = rightParts[i]; has = true; }
            else { Node tmp; combine(result, rightParts[i], tmp); result = tmp; }
        }
        return result;
    }
    
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        build(nums);
        
        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(index, value);
            Node res = query(start, n - 1);
            result.push_back((int)res.cnt[1 % K][x]);
        }
        return result;
    }
};