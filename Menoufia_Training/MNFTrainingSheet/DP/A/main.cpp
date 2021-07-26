#include <iostream>

using namespace std;
int t , n;
string str;
        string sub="abacaba";

int cnt(){
        int tot=0, idx;
        for(int i=0;i<n;i++){
            if(str[i]!='a') continue;
            idx=1;
            for(int j=i+1;j<n;j++){
                if(str[j]==sub[idx]){
                    idx++;
                } else break;
                if(idx==sub.length()){
                    tot++;
                    break;
                }
            }
        }
        return tot;

}

int main(){
    cin >>t;
    while(t--){
        cin >> n >> str;
        int idx=0;
        bool is=0;
        int tot=cnt();

        if(tot==1){
            for(int i=0;i<n;i++) if(str[i]=='?') str[i]='z';
            cout << "Yes\n" << str << endl;
            continue;
        } else if(tot>1){
            cout<<"No"<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            if(str[i]!='a' && str[i]!='?') continue;
            idx=1;
            for(int j=i+1;j<n;j++){
                if(str[j]==sub[idx]){
                    idx++;
                } else if(str[j]=='?'){
                    idx++;
                } else {
                    idx=0;
                    break;
                }
                if(idx==sub.length()){
                    string pre;
                    for(int k=0;k<7;k++) pre[k]=str[i+k], str[i+k] = sub[k];
                    if(cnt()==1){
                        is=1;

                        break;
                    }
                    else{
                        for(int k=0;k<7;k++) str[i+k] = pre[k];

                    }
                }
            }

        }

        tot=cnt();

        if(tot==1){
            for(int i=0;i<n;i++) if(str[i]=='?') str[i]='z';
            cout << "Yes\n" << str << endl;
        } else {
            cout<<"No"<<endl;
        }

    }
    return 0;
}
