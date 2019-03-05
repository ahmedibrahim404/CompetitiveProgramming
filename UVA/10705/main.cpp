
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll tc; cin>>tc;
    while(tc--){
        ll k; cin>>k;
        string s; cin>>s;

        vector<unsigned ll>p; p.pb(1);
        FOR(i,1,k-1) p.pb(p[p.size()-1]<<1);

        unsigned ll mx=0,mn=0;
        FOR(i,0,k-1){
            if(s[i]=='p') mx += p[k-1-i];
            else mn += p[k-1-i];
        }

        ll n; cin>>n;
        unsigned ll x;
        if((n>0 && (x=n) > mx) || (n<0 && (x=(ll)-n) > mn)){
            cout<<"Impossible\n";
            continue;
        }

        string ans;
        FOR(i,0,k-1){
            if(s[i]=='p') ans += "1";
            else ans += "0";
        }

        unsigned ll diff=mx-n;
        FOR(i,0,k-1) if(diff >= p[k-1-i]){
             diff -= p[k-1-i];
             if(s[i]=='p') ans[i]='0';
             else ans[i]='1';
        }

        cout<<ans<<endl;
    }

    return 0;
}
