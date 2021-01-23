#include <iostream>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int sum=0,  no, cnt=0, cnt2=0;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            sum += no;
            if(no==1) cnt++;
            else cnt2++;
            if(cnt == 4) cnt-=2, cnt2++;
        }

        if(sum %2){
            cout << "NO\n";
            continue;
        }

        if((cnt==2 && (cnt2+1)%2==0) || (cnt%2==0 && cnt2%2==0)) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
