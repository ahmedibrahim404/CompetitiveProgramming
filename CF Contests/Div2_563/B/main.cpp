#include<bits/stdc++.h>
using namespace std;

int n;
int ns[100000+9], o=0, e=0;
int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &ns[i]);
        if(ns[i]%2) o++; else e++;
    }

    if(o == 0 || e == 0){
        for(int i=0;i<n;i++) printf("%d ", ns[i]);
        return 0;
    }

    if(o == 1){
        int idx=-1;
        for(int i=0;i<n;i++) if(ns[i]%2){
            idx=i;
            break;
        }

        if(idx != -1){

            for(int i=0;i<n;i++){
                if(i == idx) continue;

                if(i > idx){
                    if(ns[i] < ns[idx]){
                        swap(ns[i], ns[idx]);
                        break;
                    }
                } else {
                    if(ns[i] > ns[idx]){
                        swap(ns[i], ns[idx]);
                        break;
                    }
                }

            }
            for(int i=0;i<n;i++) printf("%d ", ns[i]);
            return 0;

        }

    } else if(e == 1){

            int idx=-1;
            for(int i=0;i<n;i++) if(ns[i]%2==0){
                idx=i;
                break;
            }


            for(int i=0;i<n;i++){
                if(i == idx) continue;

                if(i > idx){
                    if(ns[i] < ns[idx]){
                        swap(ns[i], ns[idx]);
                        break;
                    }
                } else {
                    if(ns[i] > ns[idx]){
                        swap(ns[i], ns[idx]);
                        break;
                    }
                }

            }

            for(int i=0;i<n;i++) printf("%d ", ns[i]);
            return 0;
    } else {

        sort(ns, ns+n);
        for(int i=0;i<n;i++) printf("%d ", ns[i]);
        return 0;

    }

    return 0;
}
