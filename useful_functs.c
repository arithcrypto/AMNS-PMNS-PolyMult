#include "useful_functs.h"


//~ Assumes allocation already done for 'rop'.
//~ IMPORTANT : convertion to montgomery domain will be done here
void from_int_to_pmns(int64_t *rop, mpz_t op){
	int i;
	mpz_t tmp;
	int128 tmp_poly[NB_COEFF_N6_PMNS];
	int128 tmp_sum[NB_COEFF_N6_PMNS];

	mpz_init_set(tmp, op);

	for(i=0; i<NB_COEFF_N6_PMNS; i++){
		rop[i] = 0;
		tmp_sum[i] = 0;
	}

	if(tmp->_mp_size == 0)
		return;

	i = 0;
	while(tmp->_mp_size && (i < NB_COEFF_N6_PMNS)){
		scalar_mult_lpoly(tmp_poly, polys_P_n6_pmns[i++], (tmp->_mp_d[0]) & CONV_MASK_N6_PMNS);
		add_lpoly(tmp_sum, tmp_sum, tmp_poly);

		mpz_tdiv_q_2exp (tmp, tmp, RHO_LOG2_N6_PMNS);
	}

	internal_reduction(rop, tmp_sum);

	mpz_clear(tmp);
}

//~ Assumes "rop" already initialized.
//~ IMPORTANT : convertion from montgomery domain will be done here.
void from_pmns_to_int(mpz_t rop, int64_t *op, mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]){
	int i;
	mpz_t tmp_sum;
	int64_t tmp_conv[NB_COEFF_N6_PMNS];

	mpz_init(tmp_sum);

	//~ convertion out of mont domain
	from_mont_domain(tmp_conv, op);

	mpz_set_si(rop, tmp_conv[0]);
	for(i=0; i<POLY_DEG_N6_PMNS; i++){
		mpz_mul_si(tmp_sum, gama_pow[i], tmp_conv[i+1]);
		mpz_add(rop, rop, tmp_sum);
	}
	mpz_mod (rop, rop, modul_p);

	mpz_clear(tmp_sum);
}

//~ computes : op/phi
void from_mont_domain(int64_t *rop, int64_t *op){

	int i;
	int128 tmp[NB_COEFF_N6_PMNS];

	for(i=0; i<NB_COEFF_N6_PMNS; i++)
		tmp[i] = (int128) op[i];

	internal_reduction(rop, tmp);
}

void init_data( mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]){

	int i;
	for(i=0; i<POLY_DEG_N6_PMNS; i++)
		mpz_init (gama_pow[i]);

	mpz_init (modul_p);


	mpz_set_str (modul_p, "103349220827586647386838057192180105918374329459686284788246894917634728462183", 10);

	mpz_set_str (gama_pow[0], "13668053055164921056493624725102577325833679314951915572518092052505373024228", 10);
	for(i=1; i<POLY_DEG_N6_PMNS; i++){
		mpz_mul (gama_pow[i], gama_pow[i-1], gama_pow[0]);
		mpz_mod (gama_pow[i], gama_pow[i], modul_p);
	}
}

void free_data( mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]){
	int i;
	for(i=0; i<POLY_DEG_N6_PMNS; i++)
		mpz_clear (gama_pow[i]);

	mpz_clear (modul_p);
}

//~ ----------------------------------------------------------------------------------------

//~ return a positive value if pa > pb, zero if pa = pb, or a negative value if pa < pb.
//~ Important : evaluation is done using the corresponding integers modulo 'p'.
int cmp_poly_evals(int64_t *pa, int64_t *pb, mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]){
	int rep;
	mpz_t a, b;
	mpz_inits (a, b, NULL);
	from_pmns_to_int(a, pa, modul_p, gama_pow);
	from_pmns_to_int(b, pb, modul_p, gama_pow);
	rep = mpz_cmp (a, b);
	mpz_clears (a, b, NULL);
	return rep;
}

void copy_poly(int64_t *rop, int64_t *op){
	int i;
	for(i=0; i<NB_COEFF_N6_PMNS; i++)
		rop[i] = op[i];
}

void add_lpoly(int128 *rop, int128 *pa, int128 *pb){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = pa[j] + pb[j];
}

//~ assumes 'scalar' and/or coeffs of 'op' small enough to avoid an overflow.
void scalar_mult_lpoly(int128 *rop, int64_t *op, uint64_t scalar){
	int j;
	for (j=0; j<NB_COEFF_N6_PMNS; j++)
		rop[j] = (int128)op[j] * scalar;
}

void print_element(int64_t *poly){
	int i;
	printf("[");
	for (i=0; i<POLY_DEG_N6_PMNS; i++)
		printf("%2ld, ", poly[i]);
	printf("%2ld]", poly[POLY_DEG_N6_PMNS]);
}

