#include<bits/stdc++.h>
using namespace std;
#define NO_OF_ALPHABETS 26
#define MAX_WORD_SIZE 21
int n, k, p=0;
char str[MAX_WORD_SIZE];

struct TrieNode{
   TrieNode* child[NO_OF_ALPHABETS];
   bool isEndOfWord;

   TrieNode(){
        isEndOfWord=false;
        for(int i=0; i<NO_OF_ALPHABETS; i++)
            child[i] = NULL;
   }

};

void insert(TrieNode* root, char* word){

   for(int i=0; word[i] != '\0'; i++){

      if(root->child[word[i]-'a'] == NULL){
         root->child[word[i]-'a'] = new TrieNode;
      }

      root = root->child[word[i]-'a'];

   }

   root->isEndOfWord = true;

}

void printWord(char* strin, int n){
    if(n == strlen(str)) return;
    p++;
    for(int i=0; i<n; i++)
      printf("%c", strin[i]);
    printf("\n");
}

TrieNode* getNode(TrieNode* r, char* str){
//    if(str == NULL) return r;
    if(*str == '\0') return r;

   if(r->child[*str - 'a'] == NULL)
      return new TrieNode;
   else
      return getNode( r->child[*str - 'a'], str+1);

}

void printAllWords(TrieNode* root, char* wordArray, int pos = 0){
   if(root == NULL)
      return;

   if(root->isEndOfWord)
      printWord(wordArray, pos);

   for(int i=0; i<NO_OF_ALPHABETS; i++){
      if(root->child[i] != NULL){
         wordArray[pos] = i+'a';
         printAllWords(root->child[i], wordArray, pos+1);
      }
   }
}

void printAllPrefix(TrieNode* root, char* wordArray, int pos){
    TrieNode* node= getNode(root, wordArray);
    printAllWords(node, wordArray, pos);
}

bool isValidWord(TrieNode* r, char* str){
   if(str == NULL )
      return true;
   if(*str == '\0')
      return r->isEndOfWord;

   if(r->child[*str - 'a'] == NULL)
      return false;
   else
      return isValidWord( r->child[*str - 'a'], str+1);
}


int main(){

    TrieNode* root = new TrieNode;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", str);
        insert(root, str);
    }

    scanf("%d", &k);
    for(int i=0;i<k;i++){
        scanf("%s", str);
        TrieNode* node= getNode(root, str);
        char wordArray[MAX_WORD_SIZE];
        int j;
        p=0;
        printf("Case #%d:\n", i+1);
        for(j=0;j<strlen(str);j++) wordArray[j]=str[j];
        printAllWords(node, wordArray, j);
        if(p == 0) printf("No match.\n");
    }

}
