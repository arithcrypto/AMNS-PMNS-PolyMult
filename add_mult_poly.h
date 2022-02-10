#ifndef POLY_MULT_ADD
#define POLY_MULT_ADD


#include <immintrin.h>

#include <stdint.h>

#include <stdio.h>
#include <gmp.h>

#include "gmp_stuff.h"

#include "structs_data.h"

#include "useful_functs_n5_pmns.h"

#include "useful_functs_n5_amns.h"

#include "useful_functs.h"

typedef __int128 int128;

// This is a special gcc mode for 128-bit integers. It's implemented on 64-bit
// platforms only as far as I know.
typedef unsigned uint128_t __attribute__((mode(TI)));


// typedef for main...
union int512_t{
	int64_t i64[8];
	__m128i i128[4];
	__m256i i256[2];
	__m512i i512[1];

};

typedef union int512_t int512;


void sub_poly(int64_t *rop, int64_t *pa, int64_t *pb);
void add_poly(int64_t *rop, int64_t *pa, int64_t *pb);
void double_add_poly(int64_t *rop, int64_t *pa, int64_t *pb);
void double_sub_poly(int64_t *rop, int64_t *pa, int64_t *pb);
void neg_poly(int64_t *rop, int64_t *op);
void scalar_mult_poly(int64_t *rop, int64_t *op, int64_t scalar);
void double_poly_coeffs(int64_t *rop, int64_t *op);
void lshift_poly_coeffs(int64_t *rop, int64_t *op, int nb_pos);

void mult_mod_poly(int64_t *rop, int64_t *pa, int64_t *pb);

void square_mod_poly(int64_t *rop, int64_t *pa);

void internal_reduction(int64_t *rop, int128 *op);

void exact_coeffs_reduction(int64_t *rop, int64_t *op);

void mult_mod_poly_AVX512(int64_t *rop, int64_t *pa, int64_t *pb);

void internal_reduction_512(int64_t *rop, int128 *op);

void mult_mod_poly_n5_pmns(int64_t *rop, int64_t *pa, int64_t *pb);

void internal_reduction_n5_pmns(int64_t *rop, int128 *op);

void exact_coeffs_reduction_n5_pmns(int64_t *rop, int64_t *op);

void mult_mod_poly_n5_amns(int64_t *rop, int64_t *pa, int64_t *pb);

void internal_reduction_n5_amns(int64_t *rop, int128 *op);

void exact_coeffs_reduction_n5_amns(int64_t *rop, int64_t *op);


#endif

