#include<bits/stdc++.h>
using namespace std;

int n;
char s[140];
int main(){

    scanf("%d", &n);
    getc(stdin);

    while(n--){
		gets(s);

        stack<int> st;
        bool done=false;
        for(int i=0;i<strlen(s);i++){

            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            else {

                if( st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') ){
                    printf("No\n");
                    done=true;
                    break;
                }

                st.pop();

            }

        }

        if(done) continue;
        if(st.empty()) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
