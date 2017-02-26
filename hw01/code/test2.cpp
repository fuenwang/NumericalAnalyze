#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main(){
    struct timeval a,b;
    gettimeofday(&a, NULL);
    sleep(20);
    gettimeofday(&b, NULL);
    printf("%d\n", b.tv_sec - a.tv_sec);
    return 0;
}
