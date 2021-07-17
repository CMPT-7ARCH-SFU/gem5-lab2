#include "hw_defines.h"
void gemm()
{
    uint8_t *m1base = (uint8_t *)M1ADDR_V2;
    uint8_t *m2base = (uint8_t *)M2ADDR_V2;
    uint8_t *m3base = (uint8_t *)M3ADDR_V2;
    TYPE *m1 = (TYPE *)m1base;
    TYPE *m2 = (TYPE *)m2base;
    TYPE *m3 = (TYPE *)m3base;
#pragma clang loop unroll(full)
    for (int k = 0; k < vector_size; k++)
    {
        m3[k] = m1[k] * m2[k];
    }
}
