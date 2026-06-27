class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,ll> mp;
        for(auto i:nums){
            mp[i]++;
        }
        ll maxi=1;
        if(mp.count(1)){
            ll ans=mp[1];
            if(ans%2==0) ans--;
            maxi=max(ans,maxi);
        }
        for(auto [val,freq]:mp){
            if(val==1) continue;
            ll curr=val;
            ll len=0;
            while(mp.count(curr) && mp[curr]>1){
                len+=2;
                if(curr<=1e5) curr*=curr;
                else{
                    curr=0;
                    break;
                }
            }
            if(mp.count(curr) && mp[curr]>=1){
                len++;
            } else {
                len--;
            }
            maxi=max(maxi,len);

        }
        return maxi;
    }
};