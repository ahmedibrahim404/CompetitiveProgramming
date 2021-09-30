#include <iostream>

using namespace std;

/**

    xOr => [
        A ^ B ^ C ^ D = E, for any bit in E equals 1 => must be odd number of bit 1 in (A, B, C, D)
        1010
        0101
        1010
        _____
        0101
        eoeo => e for even, o for odd
    ]

**/

/**

    X%(2^n) = X&(2^n-1) =>> trick

**/

int getBit(int num, int idx){
    return ((num>>idx)&1);
}

int setBit(int num, int idx, int val){
    if(getBit(num, idx)== val) return num;
    if(val) return ( num+(1<<idx) );
    return ( num-(1<<idx) );
}

int setBit1(int num, int idx){
    return num | (1<<idx);
}

int setBit0(int num, int idx){
    return num & ~(1<<idx);
}



/**

    what happens while subtracting one from any number??
    50          => 110010
    50 -1       => 110001

    removes the last bit and set all bits before it equal => 1

    11000110000 ( subtract 1 )
    11000101111

    so x&(x-1) removes the last bit


**/

int countBits(int num){
    int cnt=0;
    while(num){
        cnt++;
        num &= num-1;
    }
    return cnt;
}

int grayCode(int num){
    return num^(num>>1);
}

void printNumber(int n, int sz){
    if(!sz){
        return;
    }
    printNumber(n>>1, sz-1);
    if(n&1)printf("1");
    else printf("0");
}


// print all subsets of a number
/**

    01011
    => [
        00000
        01000
        01010
        01001
        01011
        00010
        00011
        00001
    ]

    if it was just of len 5 we can start from
        00000
        and go to
        11111
    but here me need only bits 1
    then we can always subtract ( add if we start from 0 ) & mask

**/

void printSubsets(int mask){

    for(int i=mask;i;i=(i-1)&mask){
        printNumber(i, 5);
        printf("\n");
    }
    // nice man!
}



int main(){

    printSubsets(11);

//    int cnt=0;
//    for(int i=1;i<=100;i++){
//    int num=i;
//    int gray=grayCode(num);
//    if(abs(__builtin_popcount(gray)-cnt) > 1){
//        // THIS WILL NEVER HAPPEN BECAUSE IT'S ALWAYS EQUAL TO 1 !!!!
//        cout << "FALSE!!!" << endl;
//        break;
//    }
//    cnt=__builtin_popcount(gray);
//    printNumber(grayCode(num));
//    printf("\n");
//    }




    return 0;
}
