#include<iostream>
using namespace std;
void merge(int *array, int l, int m, int r) {

    int i=0, j=0, k=l;
    // k => array
    // i, j => two subarrays
    int s1[m-l+1], s2[r-m];
    for(i=0;i<m-l+1;i++) s1[i]=array[i+l];
    for(i=0;i<r-m;i++) s2[i]=array[i+m+1];

    i=0, j=0;

    while(i < m-l+1 && j < r-m){
        if(s1[i] > s2[j]){
            array[k]=s2[j];
            j++;
        } else {
            array[k]=s1[i];
            i++;
        }
        k++;
    }

    while(i < m-l+1){
        array[k]=s1[i];
        i++;
        k++;
    }

    while(j < r-m){
        array[k]=s2[j];
        j++;
        k++;
    }

}
void mergeSort(int *array, int l, int r) {

    if(r>l){
        int mid=(l+r)>>1;
        mergeSort(array, l, mid);
        mergeSort(array, mid+1, r);
        merge(array, l, mid, r);
    }

}
int main() {
   int n;
   scanf("%d",&n);
   int arr[n];
   for(int i = 0; i<n; i++) {
      scanf("%d",&arr[i]);
   }
   mergeSort(arr, 0, n-1);
   for(int i=0;i<n;i++) printf("%d ", arr[i]);
   printf("\n");
}
