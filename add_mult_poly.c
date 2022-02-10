/******************************************************

			Avec AVX512

******************************************************/
#include <immintrin.h>


#include "add_mult_poly.h"

#include "polys_P.h"

#include "gmp_stuff.c"

#include "useful_functs_n5_pmns.c"


#include "useful_functs_n5_amns.c"

#include "useful_functs.c"

void affiche512i(__m512i x, char* s){

	uint64_t x64[8];
	_mm512_store_si512(x64,x);
	
	printf("%s := ",s);
	for(int i=0;i<8;i++) printf("%16.16lX ",x64[i]);
	printf("\n");
}

void affiche512i_32(__m512i x, char* s){

	uint32_t x32[16];
	_mm512_store_si512((uint64_t*)x32,x);
	
	printf("%s := ",s);
	for(int i=0;i<16;i++) printf("%8.8X ",x32[i]);
	printf("\n");
}


void add_poly(int64_t *rop, int64_t *pa, int64_t *pb){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = pa[j] + pb[j];
}

void sub_poly(int64_t *rop, int64_t *pa, int64_t *pb){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = pa[j] - pb[j];
}

//~ computes : pa + 2.pb
void double_add_poly(int64_t *rop, int64_t *pa, int64_t *pb){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = pa[j] + 2*pb[j];
}

//~ computes : pa - 2.pb
void double_sub_poly(int64_t *rop, int64_t *pa, int64_t *pb){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = pa[j] - 2*pb[j];
}

void neg_poly(int64_t *rop, int64_t *op){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = -op[j];
}

//~ assumes 'scalar' and/or coeffs of 'op' small enough to avoid an overflow.
void scalar_mult_poly(int64_t *rop, int64_t *op, int64_t scalar){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = scalar * op[j];
}

//~ assumes 'scalar' and/or coeffs of 'op' small enough to avoid an overflow.
void double_poly_coeffs(int64_t *rop, int64_t *op){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = op[j] << 1;
}

//~ assumes 'nb_pos' and/or coeffs of 'op' small enough to avoid an overflow.
void lshift_poly_coeffs(int64_t *rop, int64_t *op, int nb_pos){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = op[j] << nb_pos;
}

//~ Computes pa(X)*pb(X) mod(E)
void mult_mod_poly(int64_t *rop, int64_t *pa, int64_t *pb){

	int128 tmp_prod_result[NB_COEFF_N6_PMNS];
	int128 c6, c7, c8, c9, c10;

	c6 = (int128)pa[1] * pb[5] + (int128)pa[2] * pb[4] + (int128)pa[3] * pb[3] + (int128)pa[4] * pb[2] + (int128)pa[5] * pb[1];
	c7 = (int128)pa[2] * pb[5] + (int128)pa[3] * pb[4] + (int128)pa[4] * pb[3] + (int128)pa[5] * pb[2];
	c8 = (int128)pa[3] * pb[5] + (int128)pa[4] * pb[4] + (int128)pa[5] * pb[3];
	c9 = (int128)pa[4] * pb[5] + (int128)pa[5] * pb[4];
	c10 = (int128)pa[5] * pb[5];

	tmp_prod_result[0] = (int128)pa[0] * pb[0] + c6;
	tmp_prod_result[1] = (int128)pa[0] * pb[1] + (int128)pa[1] * pb[0] + c6 + c7;
	tmp_prod_result[2] = (int128)pa[0] * pb[2] + (int128)pa[1] * pb[1] + (int128)pa[2] * pb[0] + c7 + c8;
	tmp_prod_result[3] = (int128)pa[0] * pb[3] + (int128)pa[1] * pb[2] + (int128)pa[2] * pb[1] + (int128)pa[3] * pb[0] + c8 + c9;
	tmp_prod_result[4] = (int128)pa[0] * pb[4] + (int128)pa[1] * pb[3] + (int128)pa[2] * pb[2] + (int128)pa[3] * pb[1] + (int128)pa[4] * pb[0] + c9 + c10;
	tmp_prod_result[5] = (int128)pa[0] * pb[5] + (int128)pa[1] * pb[4] + (int128)pa[2] * pb[3] + (int128)pa[3] * pb[2] + (int128)pa[4] * pb[1] + (int128)pa[5] * pb[0] + c10;

	internal_reduction(rop, tmp_prod_result);
}

//~ Computes pa(X)^2 mod(E)
void square_mod_poly(int64_t *rop, int64_t *pa){

	int128 tmp_prod_result[NB_COEFF_N6_PMNS];
	int128 c6, c7, c8, c9, c10;

	c6 = (((int128)pa[4] * pa[2] + (int128)pa[5] * pa[1]) << 1) + (int128)pa[3] * pa[3];
	c7 = (((int128)pa[4] * pa[3] + (int128)pa[5] * pa[2]) << 1);
	c8 = (((int128)pa[5] * pa[3]) << 1) + (int128)pa[4] * pa[4];
	c9 = (((int128)pa[5] * pa[4]) << 1);
	c10 = (int128)pa[5] * pa[5];

	tmp_prod_result[0] = (int128)pa[0] * pa[0] + c6;
	tmp_prod_result[1] = (((int128)pa[1] * pa[0]) << 1) + c6 + c7;
	tmp_prod_result[2] = (((int128)pa[2] * pa[0]) << 1) + (int128)pa[1] * pa[1] + c7 + c8;
	tmp_prod_result[3] = (((int128)pa[2] * pa[1] + (int128)pa[3] * pa[0]) << 1) + c8 + c9;
	tmp_prod_result[4] = (((int128)pa[3] * pa[1] + (int128)pa[4] * pa[0]) << 1) + (int128)pa[2] * pa[2] + c9 + c10;
	tmp_prod_result[5] = (((int128)pa[3] * pa[2] + (int128)pa[4] * pa[1] + (int128)pa[5] * pa[0]) << 1) + c10;


	internal_reduction(rop, tmp_prod_result);
}

//~ performs the internal reduction on 'op' and puts the result in 'rop'
//~ IMPORTANT : We take 'mont_phi = 1 << WORD_SIZE', so operations modulo mont_phi are automatically done using the appropriate variable type.
void internal_reduction(int64_t *rop, int128 *op){

	uint64_t tmpQ[NB_COEFF_N6_PMNS];
	int128 tmpZero[NB_COEFF_N6_PMNS];

	//~ computation of : op*neg_inv_ri_rep_coeff mod(E, mont_phi)
	tmpQ[0] = ((uint64_t)op[0] * 0x7a26c3751d730UL + (uint64_t)op[1] * 0xc11536d3b0edeUL + (uint64_t)op[2] * 0x6909ed6937fcdUL + (uint64_t)op[3] * 0xce748ddd1b6dfUL + (uint64_t)op[4] * 0xf1b78fd9c173dUL + (uint64_t)op[5] * 0x48a4ee93d8d56UL) & REDINT_MASK_N6_PMNS;
	tmpQ[1] = ((uint64_t)op[0] * 0x48a4ee93d8d56UL + (uint64_t)op[1] * 0x3b3bfa48ce60eUL + (uint64_t)op[2] * 0x2a1f243ce8eabUL + (uint64_t)op[3] * 0x377e7b46536acUL + (uint64_t)op[4] * 0xc02c1db6dce1cUL + (uint64_t)op[5] * 0x3a5c7e6d9a493UL) & REDINT_MASK_N6_PMNS;
	tmpQ[2] = ((uint64_t)op[0] * 0xf1b78fd9c173dUL + (uint64_t)op[1] * 0x48a4ee93d8d56UL + (uint64_t)op[2] * 0x3b3bfa48ce60eUL + (uint64_t)op[3] * 0x2a1f243ce8eabUL + (uint64_t)op[4] * 0x377e7b46536acUL + (uint64_t)op[5] * 0xc02c1db6dce1cUL) & REDINT_MASK_N6_PMNS;
	tmpQ[3] = ((uint64_t)op[0] * 0xce748ddd1b6dfUL + (uint64_t)op[1] * 0xf1b78fd9c173dUL + (uint64_t)op[2] * 0x48a4ee93d8d56UL + (uint64_t)op[3] * 0x3b3bfa48ce60eUL + (uint64_t)op[4] * 0x2a1f243ce8eabUL + (uint64_t)op[5] * 0x377e7b46536acUL) & REDINT_MASK_N6_PMNS;
	tmpQ[4] = ((uint64_t)op[0] * 0x6909ed6937fcdUL + (uint64_t)op[1] * 0xce748ddd1b6dfUL + (uint64_t)op[2] * 0xf1b78fd9c173dUL + (uint64_t)op[3] * 0x48a4ee93d8d56UL + (uint64_t)op[4] * 0x3b3bfa48ce60eUL + (uint64_t)op[5] * 0x2a1f243ce8eabUL) & REDINT_MASK_N6_PMNS;
	tmpQ[5] = ((uint64_t)op[0] * 0xc11536d3b0edeUL + (uint64_t)op[1] * 0x6909ed6937fcdUL + (uint64_t)op[2] * 0xce748ddd1b6dfUL + (uint64_t)op[3] * 0xf1b78fd9c173dUL + (uint64_t)op[4] * 0x48a4ee93d8d56UL + (uint64_t)op[5] * 0x3b3bfa48ce60eUL) & REDINT_MASK_N6_PMNS;

	//~ computation of : tmp_q*red_int_coeff mod(E)
	tmpZero[0] = (int128)tmpQ[0] * 0x579a44c411dL + (int128)tmpQ[1] * 0x46d550f9a0L + (int128)tmpQ[2] * 0x174c74f7a18L + (int128)tmpQ[3] * 0x2f18fb678afL + (int128)tmpQ[4] * 0x6e4d0330fa4L + (int128)tmpQ[5] * 0x50e3ccdfa67L;
	tmpZero[1] = (int128)tmpQ[0] * 0x50e3ccdfa67L + (int128)tmpQ[1] * 0x5c0799d3abdL + (int128)tmpQ[2] * 0x1bb9ca073b8L + (int128)tmpQ[3] * 0x4665705f2c7L + (int128)tmpQ[4] * 0x9d65fe98853L + (int128)tmpQ[5] * 0xbf30d010a0bL;
	tmpZero[2] = (int128)tmpQ[0] * 0x6e4d0330fa4L + (int128)tmpQ[1] * 0x50e3ccdfa67L + (int128)tmpQ[2] * 0x5c0799d3abdL + (int128)tmpQ[3] * 0x1bb9ca073b8L + (int128)tmpQ[4] * 0x4665705f2c7L + (int128)tmpQ[5] * 0x9d65fe98853L;
	tmpZero[3] = (int128)tmpQ[0] * 0x2f18fb678afL + (int128)tmpQ[1] * 0x6e4d0330fa4L + (int128)tmpQ[2] * 0x50e3ccdfa67L + (int128)tmpQ[3] * 0x5c0799d3abdL + (int128)tmpQ[4] * 0x1bb9ca073b8L + (int128)tmpQ[5] * 0x4665705f2c7L;
	tmpZero[4] = (int128)tmpQ[0] * 0x174c74f7a18L + (int128)tmpQ[1] * 0x2f18fb678afL + (int128)tmpQ[2] * 0x6e4d0330fa4L + (int128)tmpQ[3] * 0x50e3ccdfa67L + (int128)tmpQ[4] * 0x5c0799d3abdL + (int128)tmpQ[5] * 0x1bb9ca073b8L;
	tmpZero[5] = (int128)tmpQ[0] * 0x46d550f9a0L + (int128)tmpQ[1] * 0x174c74f7a18L + (int128)tmpQ[2] * 0x2f18fb678afL + (int128)tmpQ[3] * 0x6e4d0330fa4L + (int128)tmpQ[4] * 0x50e3ccdfa67L + (int128)tmpQ[5] * 0x5c0799d3abdL;

	//~ computation of : (op + tmp_zero)/mont_phi
	rop[0] = (op[0] + tmpZero[0]) >> PHI_LOG2_N6_PMNS;
	rop[1] = (op[1] + tmpZero[1]) >> PHI_LOG2_N6_PMNS;
	rop[2] = (op[2] + tmpZero[2]) >> PHI_LOG2_N6_PMNS;
	rop[3] = (op[3] + tmpZero[3]) >> PHI_LOG2_N6_PMNS;
	rop[4] = (op[4] + tmpZero[4]) >> PHI_LOG2_N6_PMNS;
	rop[5] = (op[5] + tmpZero[5]) >> PHI_LOG2_N6_PMNS;
}

void exact_coeffs_reduction(int64_t *rop, int64_t *op){

	int i;
	int128 tmp[NB_COEFF_N6_PMNS];

	for(i=0; i<NB_COEFF_N6_PMNS; i++)
		tmp[i] = (int128) op[i];

	internal_reduction(rop, tmp);
	int128 c6, c7, c8, c9, c10;

	c6 = (int128)rop[1] * polys_P_n6_pmns[0][5] + (int128)rop[2] * polys_P_n6_pmns[0][4] + (int128)rop[3] * polys_P_n6_pmns[0][3] + (int128)rop[4] * polys_P_n6_pmns[0][2] + (int128)rop[5] * polys_P_n6_pmns[0][1];
	c7 = (int128)rop[2] * polys_P_n6_pmns[0][5] + (int128)rop[3] * polys_P_n6_pmns[0][4] + (int128)rop[4] * polys_P_n6_pmns[0][3] + (int128)rop[5] * polys_P_n6_pmns[0][2];
	c8 = (int128)rop[3] * polys_P_n6_pmns[0][5] + (int128)rop[4] * polys_P_n6_pmns[0][4] + (int128)rop[5] * polys_P_n6_pmns[0][3];
	c9 = (int128)rop[4] * polys_P_n6_pmns[0][5] + (int128)rop[5] * polys_P_n6_pmns[0][4];
	c10 = (int128)rop[5] * polys_P_n6_pmns[0][5];

	tmp[0] = (int128)rop[0] * polys_P_n6_pmns[0][0] + c6;
	tmp[1] = (int128)rop[0] * polys_P_n6_pmns[0][1] + (int128)rop[1] * polys_P_n6_pmns[0][0] + c6 + c7;
	tmp[2] = (int128)rop[0] * polys_P_n6_pmns[0][2] + (int128)rop[1] * polys_P_n6_pmns[0][1] + (int128)rop[2] * polys_P_n6_pmns[0][0] + c7 + c8;
	tmp[3] = (int128)rop[0] * polys_P_n6_pmns[0][3] + (int128)rop[1] * polys_P_n6_pmns[0][2] + (int128)rop[2] * polys_P_n6_pmns[0][1] + (int128)rop[3] * polys_P_n6_pmns[0][0] + c8 + c9;
	tmp[4] = (int128)rop[0] * polys_P_n6_pmns[0][4] + (int128)rop[1] * polys_P_n6_pmns[0][3] + (int128)rop[2] * polys_P_n6_pmns[0][2] + (int128)rop[3] * polys_P_n6_pmns[0][1] + (int128)rop[4] * polys_P_n6_pmns[0][0] + c9 + c10;
	tmp[5] = (int128)rop[0] * polys_P_n6_pmns[0][5] + (int128)rop[1] * polys_P_n6_pmns[0][4] + (int128)rop[2] * polys_P_n6_pmns[0][3] + (int128)rop[3] * polys_P_n6_pmns[0][2] + (int128)rop[4] * polys_P_n6_pmns[0][1] + (int128)rop[5] * polys_P_n6_pmns[0][0] + c10;


	internal_reduction(rop, tmp);
}

#include "add_mult_poly_AVX512.c"

#include "add_mult_poly_n5_amns.c"

#include "add_mult_poly_n5_pmns.c"
