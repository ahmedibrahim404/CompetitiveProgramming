class Solution {
public:
    vector<string> ans;
    int len;string ss;
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 16) return ans;
        len=s.length();
        ss=s;
        vector<int> c;
        solve(0, c);
        return ans;
        
    }
    
    void solve(int idx, vector<int> cur){
                
        if(idx == len) {
            if(cur.size() == 4){
                string totAns ="";
                for(auto num:cur){
                    totAns += to_string(num);
                    totAns += ".";
                }
                
                totAns.pop_back();
                ans.push_back(totAns);
            }
            return;
        }
        
        int sum=0;
        for(int j=idx;j<len;j++){
            sum *= 10;
            sum += ss[j]-'0';
            if(sum > 255) break;
            vector<int> cCur = cur;
            cCur.push_back(sum);
            solve(j+1, cCur);
            if(sum == 0){   
                break;
            }
        }
        
    }
    
};