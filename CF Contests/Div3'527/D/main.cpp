    #include <iostream>

    using namespace std;
    typedef pair<int, int> pi;

    const int MAX=100000+3;
    int T;
    string s;
    int ns[MAX];
    bool is[MAX];
    bool vis[MAX];
    pi ps[MAX];
    int main(){
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
        cin >> T;
        while(T--){
            for(int i=0;i<MAX;i++) is[i]=vis[i]=0;
            cin >> s;
            int cm=0, p=0;
            int len=s.length();
            char pre=s[0];int cnt=1;
            for(int i=1;i<len+1;i++){
                if(i < len && s[i]==pre) cnt++;
                else {
                    if(cnt%2) is[cm]=(s[i-1]=='1'?1:0), ns[cm++]=1;
                    else {
                        if(cm) ps[p].first=cm-1, ps[p].second=cm, p++;
                    }
                    pre=s[i], cnt=1;
                }
            }

            for(int i=0;i<p;i++){
                int st=ps[i].first, en=ps[i].second;

                if(is[st] != is[en]) continue;
                while(st>=0 && en <cm && !vis[st] && !vis[en]){
                    if(ns[st]&&ns[en] && is[st]==is[en]) {
                        vis[st]=vis[en]=1;
                        st--, en++;
                    } else break;
                }
            }

            bool dd=0;
            for(int i=0;i<cm;i++){
                if(vis[i]) continue;
                int ty=is[i];
                while(ns[i]--) dd=1, cout << ty;
            }

            if(!dd) cout << "EMPTY";

            cout << endl;



        }
        return 0;
    }
