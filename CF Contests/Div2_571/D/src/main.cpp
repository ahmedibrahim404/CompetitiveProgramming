#include <iostream>
using namespace std;

int n;
double no;
bool can[100000+9];
int ns[100000+9];
bool inc[100000+9];
int main() {
    cin >> n;
    int sum=0, pos=0, neg=0;

    for(int i=0;i<n;i++){
        cin >> no;
        if((double) no-(int) no==0) can[i]=0;
        else can[i]=1; 
        if(no>0 && can[i]) pos++;
        else if(no < 0 && can[i]) neg++;
        ns[i]=no;
        if(ns[i] == 0)if(no>0) inc[i]=1; else inc[i]=0;
        sum += (int) no;
    }


    int ren=0, rep=0;
    if(sum > 0){
        ren += sum;
    } else if(sum < 0) {
        rep += -sum;
    }

    for(int i=0;i<n;i++){
        if(ns[i] > 0){
            if(rep && can[i]){
                ns[i]++;
                rep--;
            }
        } else if(ns[i] < 0) {
            if(ren && can[i]){
                ns[i]--;
                ren--;
            }
        } else {
            if(ren && can[i] && inc[i]==0) ns[i]--, ren--;
            else if(rep && can[i] && inc[i]==1) ns[i]++, rep--;
        }
    }

    for(int i=0;i<n;i++) cout << ns[i] << endl;



}