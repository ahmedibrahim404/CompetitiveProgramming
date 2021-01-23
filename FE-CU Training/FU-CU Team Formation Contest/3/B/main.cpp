#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=100000+3;
int n;
ll p1[MAX], p2[MAX], p3[MAX], p4[MAX];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p1[i]);
        p2[i] =  p1[i]*p1[i];
        p3[i] = p2[i]*p1[i];
        p4[i] = p3[i]*p1[i];

        p1[i] = p1[i-1];
        p2[i] += p2[i-1];
        p3[i] += p3[i-1];
        p4[i] += p2[i-1];
    }

    scanf("%d",&q);
    int t,l,r;
    while(q--){
        scanf("%d%d%d",&t,&l,&r);
//        l--, r--;
        if(t==1){



        } else if(t==2){
            p4[l]+=(p4[r]-p4[l-1])+4*(p3[r]-p3[l-1])+6*(p2[r]-p2[l-1])+4*(p1[r]-p1[l-1])+(r-l+1);
            p4[r+1]-=(p4[r]-p4[l-1])+4*(p3[r]-p3[l-1])+6*(p2[r]-p2[l-1])+4*(p1[r]-p1[l-1])+(r-l+1);

            p3[l]+=(p3[r]-p3[l-1])+3*(p2[r]-p2[l-1])+3*(p1[r]-p1[l-1])+(r-l+1);
            p3[r+1]-=(p3[r]-p3[l-1])+3*(p2[r]-p2[l-1])+3*(p1[r]-p1[l-1])+(r-l+1);

            p2[l]+=(p2[r]-p2[l-1])+2*(p1[r]-p1[l-1])+(r-l+1);
            p2[r+1]-=(p2[r]-p2[l-1])+2*(p1[r]-p1[l-1])+(r-l+1);


            p1[l]+=(r-l+1);
            p1[r+1]-=(r-l+1);

        } else {

            // write your code
        }

    }

    return 0;
}
