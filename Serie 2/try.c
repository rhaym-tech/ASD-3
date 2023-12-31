#include <stdio.h>

int main() {
    int n ;

    int A[100];

    printf("Enter size: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter A[%d]: ");
        scanf("%d", &A[i]);
    }

}