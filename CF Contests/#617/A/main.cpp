#include <iostream>

using namespace std;
int t, n;
bool odd=0, even=0;
int main(){
    scanf("%d",&t);
    while(t--){

        odd=0, even=0;
        scanf("%d",&n);
        int sum=0, no;
        for(int i=0;i<n;i++){
            scanf("%d",&no);
            sum += no;
            if((no&1)) odd=1;
            if(!(no&1)) even=1;
        }

        if(sum%2) printf("YES\n");
        else {
            if(odd&&even) printf("YES\n");
            else printf("NO\n");
        }

    }
    return 0;
}
