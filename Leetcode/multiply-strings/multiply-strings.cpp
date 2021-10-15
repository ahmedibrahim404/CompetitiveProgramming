
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans = vector<int>(400+1);
        
        reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

        for(int i=0;i<num1.length();i++){
            for(int j=0;j<num2.length();j++){
                ans[i+j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
     
        string res = "";
        for(int i=0;i<num1.length()+num2.length();i++){
            if(ans[i] >= 10){
                ans[i+1] += ans[i]/10;
            }
            ans[i] %= 10;
            res = res + to_string(ans[i]);
        }
        
        while(res.back() == '0' && res.size() > 1){
            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};
