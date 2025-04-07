#include <stdio.h>


int findMax(int arr[], int size) {
    int max = arr[0]; 
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }
    return max;
}

int main() {
    
    int data[] = { 3, 7, 2, 9, 10, 5 };
    int size = sizeof(data) / sizeof(data[0]);

    
    int maxVal = findMax(data, size);

    
    printf("ÃÖ´ñ°ªÀº %d\n", maxVal);

    return 0;
}