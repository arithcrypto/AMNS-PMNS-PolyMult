#ifndef STRUCTS_DATA
#define STRUCTS_DATA

#define PHI_LOG2_N5 64
#define POLY_DEG 4
#define NB_COEFF 5
#define NB_ADD_MAX 0

#define RHO_LOG2 55  // rho = 1 << RHO_LOG2.

#define CONV_MASK 36028797018963967UL  // CONV_MASK = (1 << RHO_LOG2) - 1, for conversion

#define PHI_LOG2_N6_PMNS 52
#define POLY_DEG_N6_PMNS 5
#define NB_COEFF_N6_PMNS 6
#define NB_ADD_MAX_N6_PMNS 0


#define RHO_LOG2_N6_PMNS 47  // rho = 1 << RHO_LOG2.

#define CONV_MASK_N6_PMNS   0x7fffffffffffUL// CONV_MASK = (1 << RHO_LOG2) - 1, for conversion

#define REDINT_MASK_N6_PMNS 0xfffffffffffffUL  // REDINT_MASK = (1 << PHI_LOG2) - 1, for internal reduction
typedef __int128 int128;

//~ representations of polynomials Pi, used for conversion into the PMNS
//~ Note: each Pi is a representation of ((1 << RHO_LOG2)^i * phi^2)

#endif

