#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vi;
int T, N, idx;
bool primes[1000000+9];
int ns[100000+9];


int main(){

    for(int i=1;i<1000000+9;i++) primes[i]=true;

    primes[1]=false;

    for (int p=2; p*p<=1000000; p++){
        if (primes[p] == true) {
            for (int i=p*p; i<=1000000; i += p)
                primes[i] = false;
        }
    }

    scanf("%d", &T);

    while(T--){

        scanf("%d", &N);
        idx=0;

        auto compare = [](int lhs, int rhs){
            return ns[lhs] > ns[rhs];
        };

        priority_queue<int, vector<int>, decltype(compare)> q(compare);
        for(int i=0;i<N;i++){
            scanf("%d", &ns[i]);

            if(primes[ ns[i] ]){

                while(!q.empty()){

                    int no=q.top();

                    if(ns[no] > ns[i]) break;
                    q.pop();
                    ns[ no ]=ns[i];
                }

            } else {
                q.push(i);
            }



        }


        for(int i=0;i<N;i++){
            printf("%d ", primes[ns[i]]?ns[i]:-1);
        }

        printf("\n");



    }

    return 0;
}
