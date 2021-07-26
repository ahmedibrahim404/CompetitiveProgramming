#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    long long i,j,k;
    string s,t;
    map<char,long long> np;

    cin>>s>>t;

    for(i=0;i<t.length();i++)
        np[t[i]]++;

    long long c1=0,c2=0;

    //yay count
    for(i=0;i<s.length();i++)
    {
        if(np[s[i]]>0)
        {
            c1++;np[s[i]]--;s[i]='-';
        }
    }

    //whoops count
    for(i=0;i<s.length();i++)
    {
        if(s[i]!='-')
        {
            if(islower(s[i]) && np[toupper(s[i])]>0)
                np[toupper(s[i])]--,c2++;
            else if(isupper(s[i]) && np[tolower(s[i])]>0)
                np[tolower(s[i])]--,c2++;
        }
    }

    cout<<c1<<" "<<c2;

    return 0;
}
