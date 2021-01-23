#include<bits/stdc++.h>

using namespace std;
const int MAX=1000+3;
bool p[2000+3];
int arr[2*MAX];
int t, n;

void prim(){
    for(int i=2;i<=2000;i++) p[i]=1;
    p[1]=0;
    for(int i=2;i<=2000;i++){
        if(!p[i]) continue;
        for(int j=i*i;j<=2000;j++){
            p[j]=0;
        }
    }
}

int main(){
    cin >> t;
    prim();
    while(t--){
        bool done=0;
        cin >> n;
        for(int i=0;i<2*n;i++){
            cin >> arr[i];
        }

        for(int i=2;i<=2000;i++){


            if(!p[i]) continue;

            vector<int> ns[i];
            for(int j=0;j<2*n;j++){
                ns[ arr[j]%i ].push_back(j+1);
            }

            bool can=1;
            int rem=2;
            if(ns[0].size()%2) rem--;
            for(int j=1;j<=i/2;j++){
                if(i-j==j){
                    rem -= (ns[j].size()%2);
                    continue;
                }
                if(ns[j].size() != ns[i-j].size()){
                    int sz=ns[j].size() - ns[i-j].size();
                    rem -= abs(sz);
                    if(rem < 0) can=0;
                }
            }


            if(can){

                int need=n-1;

                int have=ns[0].size();
                have /= 2;
                int re=min(need, have);
                need -=re;

                while(re--){
                    int idx1=ns[0].back();
                        ns[0].pop_back();
                        int idx2=ns[0].back();
                        ns[0].pop_back();

                        cout << idx1 << " " << idx2 << "\n";
                }

                for(int j=1;j<=i/2;j++){
                    // i, i-j

                    int mi=min( ns[j].size(), ns[i-j].size() );
                    if(j==i-j) mi/=2;
                    mi=min(mi, need);
                    need -= mi;
                    while(mi--){
                        int idx1=ns[j].back();
                        ns[j].pop_back();
                        int idx2=ns[i-j].back();
                        ns[i-j].pop_back();

                        cout << idx1 << " " << idx2 << "\n";
                    }
                }

                done=1;
            }

            if(done) break;
        }



    }
    return 0;
}
