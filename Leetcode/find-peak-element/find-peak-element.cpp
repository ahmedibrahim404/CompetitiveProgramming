class Solution {
public:
    int findPeakElement(vector<int>& nums) {
                
        int st=0, en=nums.size()-1;
        int ans=en;
        while(en > st){
            int mid = (st+en)/2;
            int mid2 = mid + 1;
            
            if(nums[mid] > nums[mid2]){
                en=mid; 
                ans = mid;
            } else {
                st=mid2;
                ans = mid2;
            }

        }
        
        return ans;
        
    }
};