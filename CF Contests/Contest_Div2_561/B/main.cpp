#include <iostream>

using namespace std;


int k;
char vowels[] = {'a', 'e', 'o', 'i', 'u'};
int main(){

   cin >> k;
   if(k < 25) {
        cout << -1 << endl;
        return 0;
   }

   for(int i=1;i*i<=k;i++){

        if(k%i==0){

            int fir=i, sec=k/i;


            if(fir >= 5 && sec >= 5){


                for(int j=0;j<fir;j++){
                    int st=j;
                    for(int l=j;l<j+sec;l++){
                        cout << vowels[ l%5 ];
                    }
                }

                return 0;

            }

        }

   }

   cout << -1 << endl;

    return 0;
}
