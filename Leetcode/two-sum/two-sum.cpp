class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            if(mp.count(target - cur)){
                return { i, mp[target-cur] };
            }
            mp[cur] = i;
        }
        
        return {-1, -1};
    
    }
};
