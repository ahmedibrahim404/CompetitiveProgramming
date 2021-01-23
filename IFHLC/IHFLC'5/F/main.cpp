#include <iostream>

using namespace std;

int dis[100000+9], N, Q, a, b, c;
int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> dis[i];
    for(int i=0;i<Q;i++){
        cin >> a >> b >> c;
        if(a==1) dis[b]=c;
        else cout << abs(dis[b]-dis[c]) << "\n";
    }
    return 0;
}
