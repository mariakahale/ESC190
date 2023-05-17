#include <stdio.h>

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    int i = 0;
    for (i = 0; i<=arr1_sz;i++) {
        int j = 0;
        if (arr1[i+j] == arr2[j]) {

            while ((arr1[i+j] == arr2[j]) && (j<(arr2_sz-1)) && ((i+j) < arr1_sz)) {
                j++;
            } 

            if (j==(arr2_sz-1)){
                int k = 0;
                for (k = 0; k<arr2_sz;k++) {
                    arr1[i+k] = 0;
                }
            }
        }
    }
    int f = 0;
    for(f = 0; f < 6; f++){
        printf("%d ", arr1[f]);
    }
    }

int main() {
    int arr1[6] = {5,6,7,8,6,7};
    int arr2[2] = {6,7};
    int arr1_sz = 6;
    int arr2_sz = 2;
    seq_replace(arr1, arr1_sz, arr2, arr2_sz);

    return 0;
}

