#include <inttypes.h>

//-- types
struct pcg_state_setseq_64 {
    uint64_t state;
    uint64_t inc;

};
typedef struct pcg_state_setseq_64 pcg32_random_t;

#define PCG32_INITIALIZER   { 0x853c49e6748fea9bULL, 0xda3e39cb94b95bdbULL }

static pcg32_random_t pcg32_global = PCG32_INITIALIZER;

typedef unsigned int uint;

//-- internals
void     pcg32_srandom_r(pcg32_random_t*, uint64_t, uint64_t);
uint32_t pcg32_random_r(pcg32_random_t*);
uint32_t pcg32_boundedrand_r(pcg32_random_t*, uint32_t);

//-- exported as Idris FFI
void   pcg_seed(int, int);
void   pcg_seedTime(void);
int    pcg_randInt(void);
uint   pcg_randNat(void);
int    pcg_randBound(int);
double pcg_randFloat(void);

