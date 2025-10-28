// testando geração de numero aleatório

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    current_time = time(NULL);
    srandom(current_time);
    printf("%ld\n ", random());

}