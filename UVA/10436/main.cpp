#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double rround(double x) { return floor(x * 100 + 0.5) / 100; }


int N, n, idx=0, cost;
char str[105], str2[105];
map<string, int> mp;
map<int, string> mp2;
int ns[105][105], costSt[105];;
int previ[105][105];
double tot=0;

void printPath(int i, int j){
    if(i != j) printPath(i, previ[i][j]);
    tot += costSt[ j ];
    if(mp2[j] == string(str2)) cout << mp2[j];
    else cout << mp2[j] << " ";
}

int main(){

    scanf("%d", &N);
    int mpi=1, que=1;
    while(N--){
        que=1;

        mp.clear();
        mp2.clear();

        for(int i=0;i<105;i++) for(int j=0;j<105;j++) ns[i][j]=1e8, previ[i][j]=i;

        scanf("%d", &n);
        printf("Map #%d\n", mpi++);

        while(n--){
            scanf("%s %d", str, &costSt[idx]);
            mp[ string(str) ]=idx;
            mp2[ idx ]=string(str);
            idx++;
        }

        scanf("%d", &n);

        while(n--){
            scanf("%s %s %d", str, str2, &cost);
            ns[ mp[string(str)] ][ mp[string(str2)] ]=min(cost, ns[ mp[string(str)] ][ mp[string(str2)] ]);
            ns[ mp[string(str2)] ][ mp[string(str)] ]=min(cost, ns[ mp[string(str2)] ][ mp[string(str)] ]);
        }

        for(int k=0;k<idx;k++) for(int i=0;i<idx;i++) for(int j=0;j<idx;j++){
            if(ns[i][k] < 1e8 && ns[k][j] < 1e8 && ns[i][k]+ns[k][j] < ns[i][j]){
                ns[i][j]=ns[i][k]+ns[k][j];
                previ[i][j] = previ[k][j];
            }
        }

        scanf("%d", &n);
        while(n--){
            scanf("%s %s %d", str, str2, &cost);
            printf("Query #%d\n", que++);

            if(mp[ string(str) ] == mp[ string(str2) ]) tot=0;
            else tot=(2*ns[mp[ string(str) ]][mp[ string(str2) ]]);


            printPath( mp[ string(str) ], mp[ string(str2) ] );
            cout << endl;

            tot *= 1.1;

            printf("Each passenger has to pay : %.2lf taka\n", rround(tot/cost));


        }

       if(N) printf("\n");

    }

    return 0;
}
