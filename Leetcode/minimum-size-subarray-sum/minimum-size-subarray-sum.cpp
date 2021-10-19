class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int st=0, en=0;
        int sum = 0;
        int ans = nums.size() + 1;
        while(en < nums.size()){        
            while(sum < target && en < nums.size()){
                sum += nums[en++];
                if(sum >= target) ans = min(ans, en-st);
            }
                        
            while(sum >= target && st < nums.size()){
                sum -= nums[st++];
                if(sum >= target) ans = min(ans, en-st);
            }
            
        }
        
        if(ans == nums.size() + 1) ans = 0;
        return ans;
        
    }
};