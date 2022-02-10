#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <stdint.h>

/**** Measurements procedures according to INTEL white paper

 "How to benchmark code execution times on INTEL IA-32 and IA-64" 
 
 *****/
 
/*inline  uint64_t cpucyclesStart (void) ;
inline  uint64_t cpucyclesStop (void) ;
inline  unsigned long rdpmc_instructions(void) ;*/

// rdpmc_instructions uses a "fixed-function" performance counter to return the count of retired instructions on
//       the current core in the low-order 48 bits of an unsigned 64-bit integer.
inline static unsigned long rdpmc_instructions(void)
{
   unsigned a, d, c;

   c = (1<<30);
   __asm__ __volatile__("rdpmc" : "=a" (a), "=d" (d) : "c" (c));

   return ((unsigned long)a) | (((unsigned long)d) << 32);;
}


