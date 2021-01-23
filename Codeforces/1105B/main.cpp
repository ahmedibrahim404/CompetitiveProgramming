#include <iostream>

using namespace std;

int k, n;
char str[200000+9];
int ns[27];
int main(){

    scanf("%d %d", &n, &k);
    scanf("%s", str);

    for(int i=0;i<n;i++){

//        cout << "START AT " << i << endl;
        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(str[i] == str[j]) cnt++;
            else break;
        }

        ns[ str[i]-'a' ]+=cnt/k;
        i += cnt-1;

    }

    int mx=0;
    for(int i=0;i<27;i++) mx=max(mx, ns[i]);

    printf("%d\n", mx);

    return 0;
}
