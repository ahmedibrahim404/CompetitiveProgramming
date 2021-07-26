#include<bits/stdc++.h>
using namespace std;
string str;
int main(){

    while(getline(cin, str)){
        if(str=="\0") break;
        int ln=str.length(), c=0, w=0;
        for(int i=0;i<ln;i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='y') c++;
            else if(str[i] == ' ') w++;
        }
        w++;
        if(c==2*w) printf("NP\n");
        else printf("P\n");
    }
    return 0;
}
