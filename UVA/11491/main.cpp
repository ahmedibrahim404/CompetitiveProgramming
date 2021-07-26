#include<bits/stdc++.h>
using namespace std;

char ns[100000+9];
//int cnt[10];
int n, d;
vector< vector<int>> vi;
int main(){

    while(scanf("%d %d", &n, &d) == 2){


        if(!n && !d) break;
        vi=vector<vector<int>>(10);

        scanf("%s", ns);
        int re=d+1, mx=0;
        for(int i=0;i<re;i++) if( ns[i] > ns[mx] ) mx=i;
        printf("%c", ns[mx]);

        int rem=n-d-1;
        int pre=mx+1;
        for(int i=mx+1;i<n && rem ;i++){

            vi[(ns[i]-'0')%48].push_back(i);
            if( n-i == rem ){

                for(int i=9;i>=0;i--){
                    if(vi[i].size() > 0){
                        printf("%d", i);
                        int cur= vi[ i ][ 0 ];
                        for(int j=pre;j<=cur;j++) if(vi[ ( ns[j]-'0' )%48 ].size() > 0) vi[ ( ns[j]-'0' )%48 ].erase(vi[ ( ns[j]-'0' )%48 ].begin(), vi[ ( ns[j]-'0' )%48 ].begin()+1);
                        pre=cur+1;
                        break;
                    }
                }

                rem--;
            }

        }

        printf("\n");


    }

    return 0;
}
