#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "bench.h"
#include "../../common/m5ops.h"

volatile uint8_t  * top   = (uint8_t  *)0x2f000000;
volatile uint32_t * val_a = (uint32_t *)0x2f000001;
volatile uint32_t * val_b = (uint32_t *)0x2f000009;
volatile uint32_t * val_c = (uint32_t *)0x2f000011;

int main(void) {
	m5_reset_stats();
    bool fail = false;
    stage = 0;
    uint32_t base = 0x80c00000;
    TYPE *m1 = (TYPE *)base;
    TYPE *m2 = (TYPE *)(base + sizeof(TYPE) * N);
    TYPE *m3 = (TYPE *)(base + 2 * sizeof(TYPE) * N);

    for (int i = 0; i < N; i++) {
        printf("%d", m1[i]);
    }

    *val_a = (uint32_t)(void *)m1;
    *val_b = (uint32_t)(void *)m2;
    *val_c = (uint32_t)(void *)m3;
    // printf("%d\n", *top);
    *top = 0x01;
    int count;
    while (top !=0)
        count++;
    printf("Job complete\n");
#ifdef CHECK
    printf("Checking result\n");
    for(int i=0; i<N; i++) {
        if (m3[i] != 8*(m1[i]+m2[i]))
            {
                printf("Check failed\n");
                printf("Actual M3:%d \n", m3[i]);
            }
        }
#endif
	m5_dump_stats();
	m5_exit();
}
