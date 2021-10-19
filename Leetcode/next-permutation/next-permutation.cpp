#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int &no: nums){
            sum += no;
        }
        if(sum % k){
            return false;
        }
        int each = sum/k;
        
        bool ans = 1;
        for(int i=0;i<k;i++){
            ans &= can(nums, each);
        }
        
        return ans;
        
    }
    
private:
    bool can(vector<int> &nums, int sum){
        if(!sum) return 1;
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            erase(nums.begin() + i);
            if(cur <= sum && can(nums, sum - cur)){
                return 1;
            } else nums.push_back(cur);
        }
        return 0;
    }
};
int main(){

	Solution s;
	vector<vector<char>> a = {{'a', 'a'}};
	cout << s.exist(a, "aaa") << endl;

	return 0;
}
