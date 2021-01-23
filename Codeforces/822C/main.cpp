#include <iostream>

using namespace std;

int main(){

    for (int i = 0; i <= w.length; i++) {
        for (int j = 0; j <= W; j++) {
            int weight = w[i];
            if(weight<=j){
                matrix[i][j] = Math.max(
                        v[i - 1] + matrix[i - 1][j - weight],
                        matrix[i - 1][j]);
            } else {
                matrix[i][j]=matrix[i-1][j];
            }

        }
    }

    return 0;
}
