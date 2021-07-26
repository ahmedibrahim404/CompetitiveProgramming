#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t;
int ans[100000+9];
int main(){
    scanf("%d %d", &n, &m);
    priority_queue<int> q;
    ll total=0, re=0;

    for(int i=0;i<n;i++){
        scanf("%d", &t);
        total += t;
        re=0;
        priority_queue<int> qq=q;
        ll add=0;
        while(total > m){
            total -= qq.top();
            add += qq.top();
            qq.pop();
            re++;
        }

        total += add;
        q.push(t);
        ans[i]=re;
    }

    for(int i=0;i<n;i++) printf("%d ", ans[i]);


    return 0;
}
