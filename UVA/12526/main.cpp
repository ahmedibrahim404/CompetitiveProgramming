#include <iostream>
#include <math.h>
using namespace std;
int n;
int total=0, no=0;
char str[81];

inline double round( double val ){
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

struct tire {

    bool word;
    tire* child[26];

    tire(){
        word=false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }

};

void insert(tire* root, char* str){


    if(*str == '\0'){
        root->word=true;
        return;
    }

    int idx=*str-'a';
    if(root->child[idx] == NULL) root->child[idx] = new tire;

    insert(root->child[idx], str+1);


}

void get( tire* root, int st ){

    if(root->word) {
        total += st;
        no++;
    }

    int c=0;
    for(int i=0;i<26;i++){
        if( root->child[i] != NULL ){
            c++;
        }
    }

    if(c == 0) return;
    else if(c==1 && !root->word) c=0;
    else c=1;

    for(int i=0;i<26;i++){
        if( root->child[i] != NULL ){
            get(root->child[i], st+c);
        }
    }

}

int main(){
    while(scanf("%d", &n) == 1){
        total=0, no=0;
        tire* tr=new tire();

        for(int i=0;i<n;i++) {
            scanf("%s", str);
            insert(tr, str);
        }

        for(int i=0;i<26;i++){
            if(tr->child[i] != NULL)
                get(tr->child[i], 1);
        }

        double ans=total/(double) no;
//        cout << ans << endl;
        printf("%.2lf\n", ans);

    }



    return 0;
}
