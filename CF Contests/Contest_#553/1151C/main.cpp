#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef long long ll;
vi ns;
int n, na, nb;

bool cmpr1(ii sec, ii fir){

    return sec.first > fir.first;

}

bool cmpr(ii sec, ii fir){

    if(fir.second > fir.first){

        return true;

    }

    return false;

}

bool cmpr2(ii sec, ii fir){

    if(sec.second < fir.second){
        return true;
    }

    return false;

}

int main(){


    scanf("%d", &n);
    ns=vi(n);

    for(int i=0;i<n;i++) scanf("%d %d", &ns[i].first, &ns[i].second);

    sort(ns.begin(), ns.end(), cmpr1);
    sort(ns.begin(), ns.end(), cmpr);

    int idx=0;
    for(int i=0;i<n;i++){
        if(ns[i].second > ns[i].first){
            idx=i;
            break;
        }
    }

    sort(ns.begin()+idx, ns.end(), cmpr2);

    ll sum=0;
    for(int i=0;i<n;i++){
        cout << ns[i].first << " " << ns[i].second << endl;
        sum += ns[i].first*(i) + ns[i].second*(n-(i+1));
    }

    printf("%lld", sum);

    return 0;
}
