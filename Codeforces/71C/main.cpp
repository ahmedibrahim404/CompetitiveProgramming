#include <iostream>

using namespace std;

int n;

int pos[100000+9], ns[100000+9];
int main(){

    scanf("%d", &n);
    int idx=0;
    for(int i=0;i<n;i++){
        scanf("%d", &ns[i]);
        if(ns[i] == 1)pos[idx++] = i;
    }

    for(int st=1;st<=(n/3);st++){

        if(n%st) continue
        for(int i=0;i<idx;i++){

            int cur=pos[i];
            bool can=true;
            int cmp=0;
            while(true){

                int tobe=cur+st;
                if(tobe >= n) tobe=(tobe)%n, cmp++;

//                if(pos[i] == 16 && st == 7){
//                    cout << tobe << endl;
//                }

                if(ns[ tobe ] != 1){
//                    cout << tobe << " STOPPED THAT MAN!" << endl;
                    can=false;
                    break;
                } else {
                    cur += st;
                }

                if(cur >= n) cur=cur%n;

                if(cmp > 1 && cur >= pos[i]){
                    if(cur == pos[i]){
                        break;
                    } else {
                        can=false;
                        break;
                    }
                }

            }
//            cout << pos[i] << " " << st << " " << can << endl;

            if(can) return printf("YES\n"), 0;

        }

    }

    return printf("NO\n"), 0;

}
