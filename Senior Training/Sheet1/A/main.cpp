#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    while(~scanf("%d",&n)){
        priority_queue<int> pq;
        queue<int> q;
        stack<int> st;
        bool c1=1, c2=1, c3=1;
        while(n--){
            int a, b;
            scanf("%d%d",&a,&b);
            if(a==1){
                if(c1)q.push(b);
                if(c2)st.push(b);
                if(c3)pq.push(b);
            } else {
                int no;
                if(c1){
                    if(q.size()){
                        no=q.front();q.pop();
                        if(no != b) c1=0;
                    } else c1=0;
                }
                if(c2){
                    if(st.size()){
                        no=st.top();st.pop();
                        if(no != b) c2=0;
                    } else c2=0;
                }
                if(c3){
                    if(pq.size()){
                    no=pq.top();pq.pop();
                    if(no != b) c3=0;
                    } else c3=0;
                }


            }
        }
        int tot=(c1+c2+c3);
        if(tot == 0){
            printf("impossible\n");
        } else if(tot > 1){
            printf("not sure\n");
        } else {
            if(c1) printf("queue\n");
            else if(c2) printf("stack\n");
            else printf("priority queue\n");
        }

    }


    return 0;
}
