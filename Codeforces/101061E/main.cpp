#include <iostream>

using namespace std;
int t;
string s;
int n, m;

const int N = 1 << 17 + 1;

int lg[N];
int sp[18][N], sp2[18][N];
int arr[N];
void init(){

    lg[0]=-1;
    for(int i=0;i<n;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = i;
        sp2[0][i] = i;
    }

}

void buildSP(){

    for(int j=1;(1<<j) <= n;j++){
        for(int i=0;i+(1<<(j-1)) <= n;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];


            sp[j][i] = arr[a] < arr[b] ? b : a;

            a = sp2[j-1][i];
            b = sp2[j-1][i+(1<<(j-1))];


            sp2[j][i] = arr[a] <= arr[b] ? a : b;
        }
    }

}

int getMax(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return arr[a] < arr[b] ? b : a;
}


int getMin(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp2[l][st];
    int b = sp2[l][en - (1<<l) + 1 ];
    return arr[a] <= arr[b] ? a : b;
}

int main(){
    cin >> t;
    while(t--){
        cin >> s >> m;
        n=s.length();


        for(int i=0;i<n;i++){
            arr[i] = s[i]-'0';
        }
        init();
        buildSP();


        int p=0;int mm = m;
        int ns[n]={0};
        for(int i=0;m;i++){
            int st=p;int en=st+m;
            if(n-p-1 < m){
                ns[p]++;
                ns[n]--;
                break;
            }
            if(st > en) break;
            int idx=getMin(st, en);
            if(idx -1 >= p){
                ns[p]++;
                ns[idx]--;
            }
            m -= (idx - p);
            p=idx+1;
        }

        for(int i=1;i<n;i++) ns[i] += ns[i-1];
        for(int i=0;i<n;i++) if(!ns[i]) cout << s[i];
        cout << "\n";


        p=0;m=mm;
        for(int i=0;i<n;i++) ns[i]=0;
        for(int i=0;m;i++){
            int st=p;int en=st+m;
            if(n-p-1 < m){
                ns[p]++;
                ns[n]--;
                break;
            }

            if(st > en) break;
            int idx=getMax(st, en);
            if(idx -1 >= p){
                ns[p]++;
                ns[idx]--;
            }
            m -= (idx - p);
            p=idx+1;
        }

        for(int i=1;i<n;i++) ns[i] += ns[i-1];
        for(int i=0;i<n;i++) if(!ns[i]) cout << s[i];
        cout << "\n";
    }
    return 0;
}
