#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ns[n], p[n];
        for(int i=0;i<n;i++){
            int no;
            cin >> no;
            ns[no-1]=i;
        }
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(i);
            p[i]=1;
        }

        bool can=1;
        multiset<int> mx;
        for(int i=0;i<n;i++) mx.insert(1);
        for(int i=0;i<n;i++){
            auto aa=mx.end();
            aa--;
            if(p[ ns[i] ] == *aa){
                st.erase(ns[i]);
                auto next=st.lower_bound(ns[i]);
                if(next == st.end()){
                    mx.erase( mx.find( p[ ns[i] ] ));
                    continue;
                }
                int idxx=*next;
                auto itr=mx.find( p[idxx] );
                if(itr != mx.end()) mx.erase( itr );
                itr=mx.find( p[ ns[i] ] );
                if(itr != mx.end()) mx.erase( itr );

                p[ idxx ] += p[ ns[i] ];
                p[ ns[i] ] = 0;
                mx.insert( p[ idxx ] );
                mx.insert( p[ ns[i] ] );
            } else {
                can=0;
                break;
            }

        }

        if(can) cout << "Yes\n";
        else cout << "No\n";



    }
    return 0;
}
