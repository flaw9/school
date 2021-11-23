#include <stdio.h>

int main() {
    int i=0,n;
    do {
        printf("Saisir n, 1<=n<=20: ");
        scanf("%d",&n);
        i++;
    } while (n<1 || n>20);
    printf("n=%d, apres %d Itérations. \n", n, i);
    return 0;
}