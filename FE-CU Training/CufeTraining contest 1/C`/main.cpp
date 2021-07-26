#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &(x))
#define sclld(x) scanf("%lld", &(x))
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define MT make_tuple
#define MP make_pair
#define lastOne(x) (31 - __builtin_clz(x))
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl

typedef long long ll;
typedef pair<int, int> ii;
const double PI = 2*acos(0);
const double EPS =  1e-9;
const int oo = 2e9;
const ll OO = 2e18;
const ll MOD = 11092019;

const int N = 2e5+5;
int par[N];
int n, k;
int bst[N];
vector<int> arr(n), pos(k+1), ans;

void brute(int idx, int cur, int arr[], bool bef[]){
    if(idx==n){
        if(cur != k) return;

        for(int i=0;i<k;i++){
            if(bst[i]>arr[i]){
                for(int j=0;j<k;j++) bst[j]=arr[j];
                return;
            } else if(bst[i] < arr[i]) {
                return;
            }
        }

        return;
    }

    brute(idx+1, cur, arr, bef);


    if(bef[ arr[idx] ]==0){
        arr[cur]=arr[idx];
        bef[ arr[idx] ]=1;
        brute(idx+1, cur+1, arr, bef);
        bef[ arr[idx] ]=0;
    }
}


int findPar(int n)
{
    if (n == par[n])
        return n;
    return par[n] = findPar(par[n]);
}
void unin(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if (x == y)
        return;
    par[x] = y;
}

int is[N];

int main()
{

//    int T=0;
//    while(true){
//        T++;
    memset(is, -1, sizeof is);
    n=rand()%18;
    k=rand()%n;
        if(!k) k=(n-1);


        for(int i=0;i<k;i++){
            bst[i]=(k-i);
        }

    for(int i=0;i<N;i++) par[i]=i;

    cout << n << " ,, " << k << "\n";

//    scanf("%d%d", &n, &k);
    arr=vector<int>(n);
    pos=vector<int>(k+1);
    ans.clear();
    fill(all(pos), -1);
    iota(par, par+n+1, 0);
    for (int i = 0; i < n; i++){
        arr[i]=1+(i*k+n)%k; // random

        if(is[ arr[i] ] != -1){
            while(is[ arr[i] ] != -1 && arr[i] < k){
                arr[i]++;
            }
            if(is[ arr[i] ] != -1){
                while( is[ arr[i] ] != -1 && arr[i] > 1 ){
                    arr[i]--;
                }
            }
        }

        is[arr[i]]=1;

    }




    int newarr[k];bool isbef[N];
    for(int i=0;i<N;i++) isbef[i]=0;
    brute(0, 0, newarr, isbef);
    cout << "ANS: \n";
    for(int i=0;i<k;i++) cout << bst[i] << " ";
    cout << "\n";


//    }




    return 0;
}
