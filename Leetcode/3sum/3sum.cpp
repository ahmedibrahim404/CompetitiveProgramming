
class Solution {
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        if(nums.size()<3)
            return  ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int low = i+1;
            int high = nums.size()-1;
            int target = -nums[i];
            while(low<high)
            {
                
                if(low!=i+1 && nums[low]==nums[low-1])
                {
                    low++;
                    continue;
                }
                else if(high!=nums.size()-1 && nums[high]==nums[high+1])
                {
                    high--;
                    continue;
                }
                else if(nums[low]+nums[high]==target)
                {
                    vector<int> temp(3);
                    temp[0]=nums[i];
                    temp[1]=nums[low];
                    temp[2]=nums[high];
                    ans.push_back(temp);
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return ans;
    }
};
