#include<bits/stdc++.h>
using namespace std;

int t, p, n;
int pos[500000], neg[500000];
int main(){
    scanf("%d",  &t);
    while(t--){

        scanf("%d", &p);
        int i1=0, i2=0;
        for(int i=0;i<p;i++){
            scanf("%d", &n);
            if(n > 0) pos[i1++]=n;
            else neg[i2++]=-1*n;
        }

        sort(pos, pos+i1, greater<int>());
        sort(neg, neg+i2, greater<int>());

        int cur=0;
        int ci=0, cj=0, sz=0, prev=1e9;
        while( ci < i1 || cj < i2 ){

            if( (sz&1) ){

                if(ci >= i1) break;

                if( pos[ci] < prev ) cur++, prev=pos[ci];
                else sz--;
                ci++;
            } else  {

                if(cj >= i2) break;

                if( neg[cj] < prev ) cur++, prev=neg[cj];
                else sz--;
                cj++;
            }

            sz++;

        }


        int cur2=0;
        ci=0, cj=0, sz=0, prev=1e9;
        while( ci < i1 || cj < i2 ){


            if( (sz&1)==0 ){
                if(ci >= i1) break;

                if( pos[ci] < prev)cur2++, prev=pos[ci];
                else sz--;

                ci++;

            } else  {
                if(cj >= i2) break;

                if( neg[cj] < prev ) cur2++, prev=neg[cj];
                else sz--;

                cj++;
            }

            sz++;

        }

        printf("%d\n", max(cur, cur2));

    }
    return 0;
}
