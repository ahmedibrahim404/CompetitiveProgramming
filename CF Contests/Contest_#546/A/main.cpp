#include <iostream>
using namespace std;

int n;
int k;
pair<int, int> ch[109];
int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d %d", &ch[i].first, &ch[i].second);

    scanf("%d", &k);
    for(int i=0;i<n;i++){

        if(ch[i].first <= k && k <= ch[i].second){
            printf("%d", (n-i));
            break;
        }

    }

    return 0;
}
