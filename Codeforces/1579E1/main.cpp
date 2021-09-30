#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        deque<int> d;
        for(int i=0;i<n;i++){
            int no;scanf("%d",&no);
            if(d.size() == 0) d.push_back(no);
            else if(d.front() >= no) d.push_front(no);
            else d.push_back(no);
        }


        auto it=d.begin();
        while(it != d.end()){
            printf("%d ", *it);
            it++;
        }

        printf("\n");

    }

    return 0;
}
