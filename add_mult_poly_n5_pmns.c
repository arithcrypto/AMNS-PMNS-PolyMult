
typedef __int128 int128;


//~ Computes pa(X)*pb(X) mod(E)
void mult_mod_poly_n5_pmns(int64_t *rop, int64_t *pa, int64_t *pb){

	int128 *tmp_prod_result = (int128*) rop;

	int128 c5, c6, c7, c8;

	c5 = (int128)pa[1] * pb[4] + (int128)pa[2] * pb[3] + (int128)pa[3] * pb[2] + (int128)pa[4] * pb[1];
	c6 = (int128)pa[2] * pb[4] + (int128)pa[3] * pb[3] + (int128)pa[4] * pb[2];
	c7 = (int128)pa[3] * pb[4] + (int128)pa[4] * pb[3];
	c8 = (int128)pa[4] * pb[4];

	tmp_prod_result[0] = (int128)pa[0] * pb[0] + c5;
	tmp_prod_result[1] = (int128)pa[0] * pb[1] + (int128)pa[1] * pb[0] + c5 + c6;
	tmp_prod_result[2] = (int128)pa[0] * pb[2] + (int128)pa[1] * pb[1] + (int128)pa[2] * pb[0] + c6 + c7;
	tmp_prod_result[3] = (int128)pa[0] * pb[3] + (int128)pa[1] * pb[2] + (int128)pa[2] * pb[1] + (int128)pa[3] * pb[0] + c7 + c8;
	tmp_prod_result[4] = (int128)pa[0] * pb[4] + (int128)pa[1] * pb[3] + (int128)pa[2] * pb[2] + (int128)pa[3] * pb[1] + (int128)pa[4] * pb[0] + c8;

	internal_reduction_n5_pmns(rop, tmp_prod_result);
}

//~ Computes pa(X)^2 mod(E)
void square_mod_poly_n5_pmns(int64_t *rop, int64_t *pa){

	int128 tmp_prod_result[NB_COEFF];

	int128 c5, c6, c7, c8;

	c5 = (((int128)pa[3] * pa[2] + (int128)pa[4] * pa[1]) << 1);
	c6 = (((int128)pa[4] * pa[2]) << 1) + (int128)pa[3] * pa[3];
	c7 = (((int128)pa[4] * pa[3]) << 1);
	c8 = (int128)pa[4] * pa[4];

	tmp_prod_result[0] = (int128)pa[0] * pa[0] + c5;
	tmp_prod_result[1] = (((int128)pa[1] * pa[0]) << 1) + c5 + c6;
	tmp_prod_result[2] = (((int128)pa[2] * pa[0]) << 1) + (int128)pa[1] * pa[1] + c6 + c7;
	tmp_prod_result[3] = (((int128)pa[2] * pa[1] + (int128)pa[3] * pa[0]) << 1) + c7 + c8;
	tmp_prod_result[4] = (((int128)pa[3] * pa[1] + (int128)pa[4] * pa[0]) << 1) + (int128)pa[2] * pa[2] + c8;


	internal_reduction_n5_pmns(rop, tmp_prod_result);
}


//~ performs the internal reduction on 'op' and puts the result in 'rop'
//~ IMPORTANT : We take 'mont_phi = 1 << WORD_SIZE', so operations modulo mont_phi are automatically done using the appropriate variable type.
void internal_reduction_n5_pmns(int64_t *rop, int128 *op){

	uint64_t tmpQ[5];
	int128 tmpZero[5];
	//~ computation of : op*neg_inv_ri_rep_coeff mod(E, mont_phi)
	tmpQ[0] = (uint64_t)op[0] * 0x8ebaed2bef6ac1cfUL + (uint64_t)op[1] * 0xd81984a61ea59dfdUL + (uint64_t)op[2] * 0x453801e4e8ba05dbUL + (uint64_t)op[3] * 0xe56cfef468791c9UL + (uint64_t)op[4] * 0xc23b09c078082fecUL;
	tmpQ[1] = (uint64_t)op[0] * 0xc23b09c078082fecUL + (uint64_t)op[1] * 0x66d471d20e105fccUL + (uint64_t)op[2] * 0x1d51868b075fa3d8UL + (uint64_t)op[3] * 0x538ed1d42f4197a4UL + (uint64_t)op[4] * 0xd091d9afbe8fc1b5UL;
	tmpQ[2] = (uint64_t)op[0] * 0xe56cfef468791c9UL + (uint64_t)op[1] * 0xc23b09c078082fecUL + (uint64_t)op[2] * 0x66d471d20e105fccUL + (uint64_t)op[3] * 0x1d51868b075fa3d8UL + (uint64_t)op[4] * 0x538ed1d42f4197a4UL;
	tmpQ[3] = (uint64_t)op[0] * 0x453801e4e8ba05dbUL + (uint64_t)op[1] * 0xe56cfef468791c9UL + (uint64_t)op[2] * 0xc23b09c078082fecUL + (uint64_t)op[3] * 0x66d471d20e105fccUL + (uint64_t)op[4] * 0x1d51868b075fa3d8UL;
	tmpQ[4] = (uint64_t)op[0] * 0xd81984a61ea59dfdUL + (uint64_t)op[1] * 0x453801e4e8ba05dbUL + (uint64_t)op[2] * 0xe56cfef468791c9UL + (uint64_t)op[3] * 0xc23b09c078082fecUL + (uint64_t)op[4] * 0x66d471d20e105fccUL;

	//~ computation of : tmp_q*red_int_coeff mod(E)
	tmpZero[0] = (int128)tmpQ[0] * 0x62b84bb3e1458L + (int128)tmpQ[1] * 0x8f0d91b236334L + (int128)tmpQ[2] * 0x99368c63a7fa3L + (int128)tmpQ[3] * 0x181db9ec27818L + (int128)tmpQ[4] * 0x589622d658b34L;
	tmpZero[1] = (int128)tmpQ[0] * 0x589622d658b34L + (int128)tmpQ[1] * 0xf1c5dd661778cL + (int128)tmpQ[2] * 0x128441e15de2d7L + (int128)tmpQ[3] * 0xb154464fcf7bbL + (int128)tmpQ[4] * 0x70b3dcc28034cL;
	tmpZero[2] = (int128)tmpQ[0] * 0x181db9ec27818L + (int128)tmpQ[1] * 0x589622d658b34L + (int128)tmpQ[2] * 0xf1c5dd661778cL + (int128)tmpQ[3] * 0x128441e15de2d7L + (int128)tmpQ[4] * 0xb154464fcf7bbL;
	tmpZero[3] = (int128)tmpQ[0] * 0x99368c63a7fa3L + (int128)tmpQ[1] * 0x181db9ec27818L + (int128)tmpQ[2] * 0x589622d658b34L + (int128)tmpQ[3] * 0xf1c5dd661778cL + (int128)tmpQ[4] * 0x128441e15de2d7L;
	tmpZero[4] = (int128)tmpQ[0] * 0x8f0d91b236334L + (int128)tmpQ[1] * 0x99368c63a7fa3L + (int128)tmpQ[2] * 0x181db9ec27818L + (int128)tmpQ[3] * 0x589622d658b34L + (int128)tmpQ[4] * 0xf1c5dd661778cL;

	//~ computation of : (op + tmp_zero)/mont_phi
	rop[0] = (op[0] + tmpZero[0]) >> PHI_LOG2_N5;
	rop[1] = (op[1] + tmpZero[1]) >> PHI_LOG2_N5;
	rop[2] = (op[2] + tmpZero[2]) >> PHI_LOG2_N5;
	rop[3] = (op[3] + tmpZero[3]) >> PHI_LOG2_N5;
	rop[4] = (op[4] + tmpZero[4]) >> PHI_LOG2_N5;

}


void exact_coeffs_reduction_n5_pmns(int64_t *rop, int64_t *op){

	int i;
	int128 tmp[NB_COEFF];

	for(i=0; i<NB_COEFF; i++)
		tmp[i] = (int128) op[i];

	internal_reduction_n5_pmns(rop, tmp);

	int128 c5, c6, c7, c8;

	c5 = (int128)rop[1] * polys_P_n5_pmns[0][4] + (int128)rop[2] * polys_P_n5_pmns[0][3] + (int128)rop[3] * polys_P_n5_pmns[0][2] + (int128)rop[4] * polys_P_n5_pmns[0][1];
	c6 = (int128)rop[2] * polys_P_n5_pmns[0][4] + (int128)rop[3] * polys_P_n5_pmns[0][3] + (int128)rop[4] * polys_P_n5_pmns[0][2];
	c7 = (int128)rop[3] * polys_P_n5_pmns[0][4] + (int128)rop[4] * polys_P_n5_pmns[0][3];
	c8 = (int128)rop[4] * polys_P_n5_pmns[0][4];

	tmp[0] = (int128)rop[0] * polys_P_n5_pmns[0][0] + c5;
	tmp[1] = (int128)rop[0] * polys_P_n5_pmns[0][1] + (int128)rop[1] * polys_P_n5_pmns[0][0] + c5 + c6;
	tmp[2] = (int128)rop[0] * polys_P_n5_pmns[0][2] + (int128)rop[1] * polys_P_n5_pmns[0][1] + (int128)rop[2] * polys_P_n5_pmns[0][0] + c6 + c7;
	tmp[3] = (int128)rop[0] * polys_P_n5_pmns[0][3] + (int128)rop[1] * polys_P_n5_pmns[0][2] + (int128)rop[2] * polys_P_n5_pmns[0][1] + (int128)rop[3] * polys_P_n5_pmns[0][0] + c7 + c8;
	tmp[4] = (int128)rop[0] * polys_P_n5_pmns[0][4] + (int128)rop[1] * polys_P_n5_pmns[0][3] + (int128)rop[2] * polys_P_n5_pmns[0][2] + (int128)rop[3] * polys_P_n5_pmns[0][1] + (int128)rop[4] * polys_P_n5_pmns[0][0] + c8;

	internal_reduction_n5_pmns(rop, tmp);
}

