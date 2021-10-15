class Solution {
public:
    string reverseWords(string s) {
        
        string ans ="";
        for(int i=s.length()-1;~i;){
            
            while(i >= 0 && s[i] == ' ') i--;
            string word;
            while(i >= 0 && s[i] != ' ') {
                word.push_back(s[i]);
                i--;
            }
            
            reverse(word.begin(), word.end());
            ans += word + ' ';
            
        }
        
        while(ans.back() == ' ') ans.pop_back();
        return ans;
        
    }
};