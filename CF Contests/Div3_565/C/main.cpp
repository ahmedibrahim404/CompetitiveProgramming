#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;cin>>n;int a=0,b=0,c=0,d=0,e=0,f=0;
    long long no;
    for(int i=0;i<n;i++){
        cin>>no;
        if(no==4)a++;
        if(no==8&&a>b)b++;
        if(no==15&&b>c)c++;
        if(no==16&&c>d)d++;
        if(no==23&&d>e)e++;
        if(no==42&&e>f)f++;
    }

    cout<<n-(f*6)<<endl;
}
