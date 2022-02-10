
typedef __int128 int128;


//~ Computes pa(X)*pb(X) mod(E)
void mult_mod_poly_n5_amns(int64_t *rop, int64_t *pa, int64_t *pb){

	int128 *tmp_prod_result = (int128*) rop;

	tmp_prod_result[0] = (int128)pa[0] * pb[0] + (((int128)pa[1] * pb[4] + (int128)pa[2] * pb[3] + (int128)pa[3] * pb[2] + (int128)pa[4] * pb[1]) << 1);
	tmp_prod_result[1] = (int128)pa[0] * pb[1] + (int128)pa[1] * pb[0] + (((int128)pa[2] * pb[4] + (int128)pa[3] * pb[3] + (int128)pa[4] * pb[2]) << 1);
	tmp_prod_result[2] = (int128)pa[0] * pb[2] + (int128)pa[1] * pb[1] + (int128)pa[2] * pb[0] + (((int128)pa[3] * pb[4] + (int128)pa[4] * pb[3]) << 1);
	tmp_prod_result[3] = (int128)pa[0] * pb[3] + (int128)pa[1] * pb[2] + (int128)pa[2] * pb[1] + (int128)pa[3] * pb[0] + (((int128)pa[4] * pb[4]) << 1);
	tmp_prod_result[4] = (int128)pa[0] * pb[4] + (int128)pa[1] * pb[3] + (int128)pa[2] * pb[2] + (int128)pa[3] * pb[1] + (int128)pa[4] * pb[0];

	internal_reduction_n5_amns(rop, tmp_prod_result);
}

//~ Computes pa(X)^2 mod(E)
void square_mod_poly_n5_amns(int64_t *rop, int64_t *pa){

	int128 tmp_prod_result[NB_COEFF];

	tmp_prod_result[0] = (int128)pa[0] * pa[0] + (((int128)pa[3] * pa[2] + (int128)pa[4] * pa[1]) << 2);
	tmp_prod_result[1] = (((int128)pa[1] * pa[0]) << 1) + (((((int128)pa[4] * pa[2]) << 1) + (int128)pa[3] * pa[3]) << 1);
	tmp_prod_result[2] = (((int128)pa[2] * pa[0]) << 1) + (int128)pa[1] * pa[1] + (((int128)pa[4] * pa[3]) << 2);
	tmp_prod_result[3] = (((int128)pa[2] * pa[1] + (int128)pa[3] * pa[0]) << 1) + (((int128)pa[4] * pa[4]) << 1);
	tmp_prod_result[4] = (((int128)pa[3] * pa[1] + (int128)pa[4] * pa[0]) << 1) + (int128)pa[2] * pa[2];

	internal_reduction_n5_amns(rop, tmp_prod_result);
}


//~ performs the internal reduction on 'op' and puts the result in 'rop'
//~ IMPORTANT : We take 'mont_phi = 1 << WORD_SIZE', so operations modulo mont_phi are automatically done using the appropriate variable type.
void internal_reduction_n5_amns(int64_t *rop, int128 *op){

	uint64_t tmpQ[5];
	int128 tmpZero[5];
	//~ computation of : op*neg_inv_ri_rep_coeff mod(E, mont_phi)
	tmpQ[0] = (uint64_t)op[0] * 0x1129f5fc2c321c33UL + (uint64_t)op[1] * 0xf5a948ceb521b850UL + (uint64_t)op[2] * 0x71fb266a83f90e2UL + (uint64_t)op[3] * 0xdef5b5acc37b7422UL + (uint64_t)op[4] * 0x11cc4ea0422533c2UL;
	tmpQ[1] = (uint64_t)op[0] * 0x8e62750211299e1UL + (uint64_t)op[1] * 0x1129f5fc2c321c33UL + (uint64_t)op[2] * 0xf5a948ceb521b850UL + (uint64_t)op[3] * 0x71fb266a83f90e2UL + (uint64_t)op[4] * 0xdef5b5acc37b7422UL;
	tmpQ[2] = (uint64_t)op[0] * 0x6f7adad661bdba11UL + (uint64_t)op[1] * 0x8e62750211299e1UL + (uint64_t)op[2] * 0x1129f5fc2c321c33UL + (uint64_t)op[3] * 0xf5a948ceb521b850UL + (uint64_t)op[4] * 0x71fb266a83f90e2UL;
	tmpQ[3] = (uint64_t)op[0] * 0x38fd933541fc871UL + (uint64_t)op[1] * 0x6f7adad661bdba11UL + (uint64_t)op[2] * 0x8e62750211299e1UL + (uint64_t)op[3] * 0x1129f5fc2c321c33UL + (uint64_t)op[4] * 0xf5a948ceb521b850UL;
	tmpQ[4] = (uint64_t)op[0] * 0xfad4a4675a90dc28UL + (uint64_t)op[1] * 0x38fd933541fc871UL + (uint64_t)op[2] * 0x6f7adad661bdba11UL + (uint64_t)op[3] * 0x8e62750211299e1UL + (uint64_t)op[4] * 0x1129f5fc2c321c33UL;

	//~ computation of : tmp_q*red_int_coeff mod(E)
	tmpZero[0] = (int128)tmpQ[0] * 0x3a3483a5c4307L + (int128)tmpQ[1] * 0xbbfcc652c5982L + (int128)tmpQ[2] * 0xd32a8cadac744L + (int128)tmpQ[3] * 0x2e5aa5181e8c4L + (int128)tmpQ[4] * 0x15ef483d342842L;
	tmpZero[1] = (int128)tmpQ[0] * 0xaf7a41e9a1421L + (int128)tmpQ[1] * 0x3a3483a5c4307L + (int128)tmpQ[2] * 0xbbfcc652c5982L + (int128)tmpQ[3] * 0xd32a8cadac744L + (int128)tmpQ[4] * 0x2e5aa5181e8c4L;
	tmpZero[2] = (int128)tmpQ[0] * 0x172d528c0f462L + (int128)tmpQ[1] * 0xaf7a41e9a1421L + (int128)tmpQ[2] * 0x3a3483a5c4307L + (int128)tmpQ[3] * 0xbbfcc652c5982L + (int128)tmpQ[4] * 0xd32a8cadac744L;
	tmpZero[3] = (int128)tmpQ[0] * 0x69954656d63a2L + (int128)tmpQ[1] * 0x172d528c0f462L + (int128)tmpQ[2] * 0xaf7a41e9a1421L + (int128)tmpQ[3] * 0x3a3483a5c4307L + (int128)tmpQ[4] * 0xbbfcc652c5982L;
	tmpZero[4] = (int128)tmpQ[0] * 0x5dfe632962cc1L + (int128)tmpQ[1] * 0x69954656d63a2L + (int128)tmpQ[2] * 0x172d528c0f462L + (int128)tmpQ[3] * 0xaf7a41e9a1421L + (int128)tmpQ[4] * 0x3a3483a5c4307L;

	//~ computation of : (op + tmp_zero)/mont_phi
	rop[0] = (op[0] + tmpZero[0]) >> PHI_LOG2_N5;
	rop[1] = (op[1] + tmpZero[1]) >> PHI_LOG2_N5;
	rop[2] = (op[2] + tmpZero[2]) >> PHI_LOG2_N5;
	rop[3] = (op[3] + tmpZero[3]) >> PHI_LOG2_N5;
	rop[4] = (op[4] + tmpZero[4]) >> PHI_LOG2_N5;

}


void exact_coeffs_reduction_n5_amns(int64_t *rop, int64_t *op){

	int i;
	int128 tmp[NB_COEFF];

	for(i=0; i<NB_COEFF; i++)
		tmp[i] = (int128) op[i];

	internal_reduction_n5_amns(rop, tmp);

	tmp[0] = (int128)rop[0] * polys_P_n5_amns[0][0] + (((int128)rop[1] * polys_P_n5_amns[0][4] + (int128)rop[2] * polys_P_n5_amns[0][3] + (int128)rop[3] * polys_P_n5_amns[0][2] + (int128)rop[4] * polys_P_n5_amns[0][1]) << 1);
	tmp[1] = (int128)rop[0] * polys_P_n5_amns[0][1] + (int128)rop[1] * polys_P_n5_amns[0][0] + (((int128)rop[2] * polys_P_n5_amns[0][4] + (int128)rop[3] * polys_P_n5_amns[0][3] + (int128)rop[4] * polys_P_n5_amns[0][2]) << 1);
	tmp[2] = (int128)rop[0] * polys_P_n5_amns[0][2] + (int128)rop[1] * polys_P_n5_amns[0][1] + (int128)rop[2] * polys_P_n5_amns[0][0] + (((int128)rop[3] * polys_P_n5_amns[0][4] + (int128)rop[4] * polys_P_n5_amns[0][3]) << 1);
	tmp[3] = (int128)rop[0] * polys_P_n5_amns[0][3] + (int128)rop[1] * polys_P_n5_amns[0][2] + (int128)rop[2] * polys_P_n5_amns[0][1] + (int128)rop[3] * polys_P_n5_amns[0][0] + (((int128)rop[4] * polys_P_n5_amns[0][4]) << 1);
	tmp[4] = (int128)rop[0] * polys_P_n5_amns[0][4] + (int128)rop[1] * polys_P_n5_amns[0][3] + (int128)rop[2] * polys_P_n5_amns[0][2] + (int128)rop[3] * polys_P_n5_amns[0][1] + (int128)rop[4] * polys_P_n5_amns[0][0];

	internal_reduction_n5_amns(rop, tmp);
}

