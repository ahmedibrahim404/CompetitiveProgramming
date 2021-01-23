#include <iostream>

using namespace std;
int n, as[26], bs[26];
string a, b;

string check(string str){

    for(int i=0;i<26;i++) bs[i]=0;
    int len=str.length();


    int l2=a.length(), took=0, st;
    int mx=0, stmx=0;
    for(int i=0;i<l2;i++){
        int cur=a[i]-'a';
        if(bs[ cur ]){
            took++;
            if(took==1) st=i;
            bs[cur]--;
        } else {
            if(took > mx) mx=took, stmx=st;
            took=0, st=0;
            for(int i=0;i<len;i++) bs[ str[i]-'a' ]++;
        }
    }


    return a.substr(stmx, mx);

}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        int len=a.length();
        for(int i=0;i<len;i++) as[ a[i]-'a' ]++, bs[ b[i]-'a' ]++;
        bool c=0;
        for(int i=0;i<26;i++){
            if(as[i] != bs[i]){
                c=1;
                break;
            }
        }
        if(c==0){
            cout << a << endl;
            continue;
        }


        string ans;
        int mxlen=0;
        for(int i=0;i<len;i++){
            string str=b.substr(i, i+1);
            string g=check(str); int cl=g.length();
            cout << i << "\n";
            if(cl > mxlen) mxlen=cl, ans=g;
            cout << g << " ";
            str=b.substr(i+1);
            g=check(str);cl=g.length();
            cout << g << "\n";
            if(cl > mxlen) mxlen=cl, ans=g;
            break;
        }

        cout << ans << endl;
    }

    return 0;
}
