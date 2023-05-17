#include <stdio.h>
void insertion_sort(int arr[5]) {
    int i = 1;
    while (i<5) {
        int j = i;
        while (j>0 && arr[j-1]>arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j = j-1;
        }
        i = i+1;
    }
    for(i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }

    // int k = 0;
    // // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
    // // Here, i++ is the same as i = i + 1
    // for(k = 0; k < 5; k++){
    //     printf("%d\n", arr[k]);
    // }
    // k = 0;
    // while(k < 5){
    //     printf("%d\n", arr[k]);
    //     k++; // same as i = i + 1
    // }
}
int main(){

    int arr[5] = {6,5,4,3,2};
    insertion_sort(arr);
    
    return 0;

}