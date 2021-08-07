#include<bits/stdc++.h>

using namespace std;

int t, a, b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        vector<int> va, vb;
        int cur=1;
        while(a){
            va.push_back((a%10) * cur);
            cur *= 10;
            a/=10;
        }
        cur=1;
        while(b){
            vb.push_back((b%10) * cur);
            cur *= 10;
            b/=10;
        }


        for(int i=0;i<va.size();i++){
            for(int j=0;j<vb.size();j++){
                if(!va[i] || !vb[j]) continue;
                printf("%d x %d", va[i], vb[j]);
                if(i == va.size()-1 && j == vb.size() - 1) continue;
                printf(" + ");
            }
        }

        printf("\n");






    }
    return 0;
}
