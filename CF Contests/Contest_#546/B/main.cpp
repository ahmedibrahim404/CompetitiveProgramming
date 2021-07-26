#include <iostream>

using namespace std;

int n, k;
int ns[5000+9];


int main(){
    scanf("%d %d", &n, &k);

    for(int i=1;i<=n;i++) ns[i]=1;

    int att=k, cost=0;
    if(k > (n/2)){

        for(int i=k;i<=n;i++){
            ns[i-1] += ns[i];
            cost += ns[i]+1;
            ns[i]=0;
            att=i;
            if(i != n) cost++;
        }

        cost += (n-k)+1;
        att = k-1;

        for(int i=att;i>=1;i--){
            ns[i+1] += ns[i];
            cost += ns[i]+1;
            ns[i]=0;
            att=i;
            if(i != 1) cost++;

        }



    } else {

        for(int i=k;i>=1;i--){
            ns[i+1] += ns[i];
            cost += ns[i]+1;
            ns[i]=0;
            att=i;
            if(i != 1) cost++;
        }

        cost += k;
        att = k+1;

        for(int i=att;i<=n;i++){
            ns[i-1] += ns[i];
            cost += ns[i]+1;
            ns[i]=0;
            att=i;
            if(i != n) cost++;
        }

    }

    cout << cost << endl;

    return 0;
}
