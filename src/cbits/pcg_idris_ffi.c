/*
 * PCG Random Number Generation for C.
 *
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *       http://www.pcg-random.org
 */



/**************************************************************************************************
 * This code has been adapted from the original implementation to be used in an FFI for Idris!
 * Please see original code and website for implementation and usage details.
 *************************************************************************************************/

#include <time.h>
#include <inttypes.h>
#include "pcg_headers.h"


void pcg32_srandom_r(pcg32_random_t* rng, uint64_t initstate, uint64_t initseq)
{
    rng->state = 0U;
    rng->inc = (initseq << 1u) | 1u;
    pcg32_random_r(rng);
    rng->state += initstate;
    pcg32_random_r(rng);
}

void pcg_seed(int seed, int seq)
{
    uint64_t u_seed = seed;
    uint64_t u_seq  = seq;
    pcg32_srandom_r(&pcg32_global, u_seed, u_seq);
}

void pcg_seedTime()
{
    uint64_t seed = time(NULL);
    uint64_t seq  = time(NULL);
    pcg32_srandom_r(&pcg32_global, seed, seq);
}

uint32_t pcg32_random_r(pcg32_random_t* rng)
{
    uint64_t oldstate = rng->state;
    rng->state = oldstate * 6364136223846793005ULL + rng->inc;
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

int pcg_randInt()
{
    return (int)pcg32_random_r(&pcg32_global);
}

uint pcg_randNat()
{
    return (uint)pcg32_random_r(&pcg32_global);
}

uint32_t pcg32_boundedrand_r(pcg32_random_t* rng, uint32_t bound)
{
    uint32_t threshold = -bound % bound;
    for (;;) {
        uint32_t r = pcg32_random_r(rng);
        if (r >= threshold)
            return r % bound;
    }
}

int pcg_randBound(int bound)
{
    uint32_t u_bound = bound;
    return (int)pcg32_boundedrand_r(&pcg32_global, u_bound);
}

double pcg_randFloat()
{
    uint32_t bound = 1000000000;
    return ((double)pcg32_boundedrand_r(&pcg32_global, bound) / bound);
}



