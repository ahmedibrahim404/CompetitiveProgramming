struct DSU {
    
    int par[100000 + 3], sz[100000 + 3], ans=1;
    void init(int n){
        for(int i=0;i<n;i++) par[i]=i, sz[i]=1;
    }
    
    int get(int x){
        return par[x] = x==par[x]?x:get(par[x]);
    }
    
    void merge(int a, int b){
        a=get(a);b=get(b);
        if(a == b) return;
        par[b]=a;
        sz[a] += sz[b];
        sz[b]=0;
        ans=max(ans, sz[a]);
    }
    
    int getAns(int n){
        int ans=1;
        for(int i=0;i<n;i++){
            if(sz[i] > ans) ans=sz[i];
        }
        return ans;
    }
    
} d;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[ nums[i] ]=i;
        }
        
        d.init(nums.size());
        
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            if(mp.count(cur+1)){
                d.merge(mp[cur], mp[cur+1]);
            }
            
            if(mp.count(cur-1)){
                d.merge(mp[cur], mp[cur-1]);
            }
        }
        
        return d.getAns(nums.size());
        
    }
};