#include <bits/stdc++.h>

using namespace std ;

#define sz(v) (int)v.size()
#define ll long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pf push_front
#define pb push_back
#define fast FastInputOutput() ;
#define Clear( container , value ) memset( container , value , sizeof container )
#define PI acos( -1.0 )
#define forn( t , v , be , n ) for( t v = be ; v < n ; v++ )
#define fore( x , j ) for( auto x : j )
#define se second
#define fr first
//#define c_b fflush(stdin);

const ll Long_max = numeric_limits < ll > :: max() ;
const int Int_max = numeric_limits < int > :: max() ;

int dx[ ] = { 1, -1, 0, 0, 1, -1, -1, 1 } ;
int dy[ ] = { 0, 0, -1, 1, 1, -1, 1, -1 } ;

void File_input( string pathIn ) {
    freopen( pathIn.c_str(), "r", stdin ) ;
}

void File_output( string pathOut ) {
    freopen( pathOut.c_str(), "w", stdout ) ;
}

int msg() {
    srand( time( 0 ) ) ;
    vector < string > st = {
        "Wish everyone high ratings!",
        "Good luck!",
        "Have fun!",
        "Please, read all the problems!",
        "Go Go fight!"
    } ;
    cerr << st[ rand() % sz( st ) ] ;
    return 0 ;
}


void FastInputOutput() {
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}


int n , t ;
const int N = 2e5 + 5 ;
int pre[ N ][ 101 ] ;

int main(){

   cin >> n >> t ;
   vector < int > a( n + 1, 0 ), b( 101, 0 );
   vector < int > ans( n + 1 ) ;
   for(int i=0;i<n;i++){
      cin >> a[ i ] ;
   }


   ll sum=0;
    for(int i=0;i<n;i++){
        sum += a[i];


        if(sum < t){
            printf("0 ");
            b[ a[i] ]++;
            continue;
        }

        ll re=sum-t;
        int no=0;
        for( int j = 100 ; j > 0 ; j-- ){
            if(b[j] == 0) continue;
            ll cnt=j*b[j];
            if(cnt >= re){
                no += (re/j)+(re%j!=0);
                break;
            } else {
                re -= cnt;
                no += b[j];
            }
        }
        b[ a[i] ]++;

        printf("%d ",no);
   }



   return 0 ;
}
