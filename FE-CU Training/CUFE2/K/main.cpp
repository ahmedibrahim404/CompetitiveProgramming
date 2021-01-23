#include <iostream>

using namespace std;

string a, b;

bool ch(char num){
    for(int i=0;i<=9;i++){
        if(num==i+'0') return 1;
    }
    return 0;
}

int main(){


    cin >> a >> b;
    int la=a.length(), lb=b.length();

    int en=0, win=0;
    for(int i=0;i<la;i++){
        if(ch(a[i])) break;
        en=i;

        if(a[i]-'a'>b[i]-'a'){
            win=1;
            break;
        } else if(a[i]-'a'<b[i]-'a'){

            win=2;
            break;

        }

    }

    if(win==1){
        printf(">\n");
        return 0;
    } else if(win==2){
        printf("<\n");
        return 0;
    }

    if(la>lb){
        printf(">\n");
        win=1;
    } else if(la<lb){
        printf("<\n");
        win=2;
    } else {

        for(int i=en+1;i<la;i++){
            if(a[i]-'0'>b[i]-'0') {printf(">\n");win=1;break;}
            else if(a[i]-'0'<b[i]-'0') {printf("<\n");win=2;break;}
            else continue;
        }

    }

    if(!win) printf("=\n");




//    for(int i=0;i)
    return 0;
}
