#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i=rand();
    if (i % 2 == 0){
        printf("J'ai le nombre pair %d -> ", i);
        printf("Youpi!\n");
    }
    else {
        printf("J'ai le nombre impair %d -> ", i);
        printf("Tralala\n");
    }
    printf("Ceci est toujours execute\n");
    return 0;
}
