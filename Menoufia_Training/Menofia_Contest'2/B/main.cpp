#include<bits/stdc++.h>
using namespace std;
set < pair<int, int> > st;
pair<int, int> ns[3000+9];
int n, x, y;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        st.insert(make_pair(x, y));
        ns[i].first=x, ns[i].second=y;
    }
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1=ns[i].first, x2=ns[j].first, y1=ns[i].second, y2=ns[j].second;
            if((x1+x2)%2==0 && (y1+y2)%2==0){
                int x3=(x1+x2)/2, y3=(y1+y2)/2;
                if(st.find( make_pair(x3, y3) ) != st.end()) c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
