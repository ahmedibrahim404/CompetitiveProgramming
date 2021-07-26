#include<bits/stdc++.h>
using namespace std;


int main(){
    long long int i,j,k,l,m,n,a,b,c,con=0,x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>c;
        long long r1=a*x1+b*y1+c;
        long long r2=a*x2+b*y2+c;
        if( (r1 > 0 && r2 < 0) || (r1 < 0 && r2 > 0) ) ++con;
    }
    cout<<con<<endl;
}
