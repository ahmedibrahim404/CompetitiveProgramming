#include<bits/stdc++.h>
using namespace std;
int t, n;
char ns[10000+9][11];

struct Trie {

    bool isWord;
    Trie* children[11];

    Trie(){
        isWord=false;
        for(int i=0;i<11;i++) children[i]=NULL;
    }

};

void insert(Trie* root, char* word){


   for(int i=0; word[i] != '\0'; i++){
      if(root->children[word[i]-'0'] == NULL){
         root->children[word[i]-'0'] = new Trie;
      }
      root = root->children[word[i]-'0'];
   }

   root->isWord = true;

}

bool is(Trie* root, char *word){

    if(*word == '\0') return false;
    if(root->isWord) return true;

    int idx=*word-'0';
    if(root->children[idx] == NULL) return false;

    return is(root->children[idx], word+1);

}


int main(){
    scanf("%d", &t);

    while(t--){

        Trie* tr=new Trie;
        scanf("%d",&n);
        bool took=false;
        for(int i=0;i<n;i++){
            scanf("%s", ns[i]);
            insert(tr, ns[i]);
        }

        for(int i=0;i<n;i++){
            if(is(tr, ns[i])){
                took=true;
                break;
            }
        }


        if(!took)printf("YES\n");
        else printf("NO\n");


    }

    return 0;
}
