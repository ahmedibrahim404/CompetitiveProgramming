#include <iostream>

using namespace std;
int t, n, k;
int main(){
    scanf("%d",&t);
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k>=n)
            cout<<"1\n";
        else
        {
            int ans=n;
            for(int i=1;i*i<=(n);i++)
            {
                if(n%i==0)
                {
                    if(i<=k)
                        ans=min(ans,n/i);
                    if(n/i <=k)
                    ans=min(ans,i);
                }
            }
            cout<<ans<<endl;
        }


    }
    return 0;
}
