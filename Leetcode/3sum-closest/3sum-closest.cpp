class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int mn=1e9;int ans=-1;
        for(int i=0;i<nums.size();i++){
            int st=i+1, en=nums.size()-1;
            while(en > st){
                int sum = nums[i] + nums[st] + nums[en];
                if(abs(sum - target) < mn) mn = abs(sum - target), ans = sum;
                if(sum > target) en--;
                else st++;
            }
        }
        
        return ans;
        
        
    }
};
