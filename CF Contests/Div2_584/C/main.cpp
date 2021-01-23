#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 2000000")
using namespace std;

const int N = 1000000 +5;

int n ,t ;
string s;

int main() {

    cin>>t;
    while(t-- && cin>>n>>s)
    {
        bool ok = 0;
        for(int i = 0;i<n;i++)
            s[i]-='0';

        for(int i = 0;i<10;i++)
        {
            bool k = 1;
            string s1 , s2;
            vector<int> pp(n+1 , 0);
            for(int j = 0;j<n;j++)
            {
                if( s[j]==i && (s2.size()==0||s2[s2.size()-1]==char(i+'0') ) )
                {
                    s2+=char(s[j]+'0');
                    pp[j] = 2;
                    continue;
                }
                if(s[j]<=i)
                {
                    pp[j] = 1;
                    s1+=char(s[j]+'0');
                }
                else
                {
                    pp[j] =2;
                    s2+=char(s[j]+'0');
                }
            }
            for(int i = 1;i<s1.size();i++)
            {
                if(s1[i]<s1[i-1])
                    k = 0;
            }
            for(int i = 1;i<s2.size();i++)
            {
                if(s2[i]<s2[i-1])
                    k = 0;
            }
            if(k)
            {
                for(int j = 0;j<n;j++)
                    cout<<pp[j];
                ok = 1;
                break;
            }
        }

        if(!ok)
            cout<<"-\n";
        cout<<"\n";
    }
    return 0;
}
