class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, int> m1, m2;
        
        if(s.length() != t.length()) return 0;
        
        bool can=1;
        for(int i=0;i<s.length();i++){
            int fir = s[i] - 'a';
            int sec = t[i] - 'a';
            
            if(m1.count(fir) && m1[fir] != sec) can=0;
            if(m2.count(sec) && m2[sec] != fir) can=0;
            
            m1[fir]=sec;
            m2[sec]=fir;
            
        }
        
        return can;
        
        
    }
};