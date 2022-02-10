
void affiche104(__m512i l, __m512i h,char * s){

	uint64_t l64[8], h64[8];
	_mm512_store_si512(l64,l);
	_mm512_store_si512(h64,h);
		
	printf("%s := ",s);
	for(int i=0;i<8;i++) printf("%16.16lX%13.13lX ",h64[i],l64[i]&0xfffffffffffffUL);
	printf("\n");



}



#define idx_a (__m512i){1UL,2UL,0x3UL,0x4UL,0x5UL,0UL,}
#define sh_one (__m128i){0x1UL,0UL}

#define zero512 (__m512i){0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL}



#define mask52 (__m512i){REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS,REDINT_MASK_N6_PMNS}


#define idx_op (__m512i){0x0UL,0x2UL,0x4UL,0x6UL,0x8UL,0xAUL,0xCUL,0xEUL}

#define KQ_0 (__m512i){0x7a26c3751d730UL,0x48a4ee93d8d56UL,0xf1b78fd9c173dUL,0xce748ddd1b6dfUL,0x6909ed6937fcdUL,0xc11536d3b0edeUL,}
#define KQ_1 (__m512i){0xc11536d3b0edeUL,0x3b3bfa48ce60eUL,0x48a4ee93d8d56UL,0xf1b78fd9c173dUL,0xce748ddd1b6dfUL,0x6909ed6937fcdUL}
#define KQ_2 (__m512i){0x6909ed6937fcdUL,0x2a1f243ce8eabUL,0x3b3bfa48ce60eUL,0x48a4ee93d8d56UL,0xf1b78fd9c173dUL,0xce748ddd1b6dfUL,}
#define KQ_3 (__m512i){0xce748ddd1b6dfUL,0x377e7b46536acUL,0x2a1f243ce8eabUL,0x3b3bfa48ce60eUL,0x48a4ee93d8d56UL,0xf1b78fd9c173dUL,}
#define KQ_4 (__m512i){0xf1b78fd9c173dUL,0xc02c1db6dce1cUL,0x377e7b46536acUL,0x2a1f243ce8eabUL,0x3b3bfa48ce60eUL,0x48a4ee93d8d56UL,}
#define KQ_5 (__m512i){0x48a4ee93d8d56UL,0x3a5c7e6d9a493UL,0xc02c1db6dce1cUL,0x377e7b46536acUL,0x2a1f243ce8eabUL,0x3b3bfa48ce60eUL,}//*/

#define idx_0 (__m512i){0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL}
#define idx_1 (__m512i){0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL,0x1UL}
#define idx_2 (__m512i){0x2UL,0x2UL,0x2UL,0x2UL,0x2UL,0x2UL,0x2UL,0x2UL}
#define idx_3 (__m512i){0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL,0x3UL}
#define idx_4 (__m512i){0x4UL,0x4UL,0x4UL,0x4UL,0x4UL,0x4UL,0x4UL,0x4UL}
#define idx_5 (__m512i){0x5UL,0x5UL,0x5UL,0x5UL,0x5UL,0x5UL,0x5UL,0x5UL}

#define KZ_0 (__m512i){0x579a44c411dL,0x50e3ccdfa67L,0x6e4d0330fa4L,0x2f18fb678afL,0x174c74f7a18L,0x46d550f9a0L,}
#define KZ_1 (__m512i){0x46d550f9a0L,0x5c0799d3abdL,0x50e3ccdfa67L,0x6e4d0330fa4L,0x2f18fb678afL,0x174c74f7a18L,}
#define KZ_2 (__m512i){0x174c74f7a18L,0x1bb9ca073b8L,0x5c0799d3abdL,0x50e3ccdfa67L,0x6e4d0330fa4L,0x2f18fb678afL,}
#define KZ_3 (__m512i){0x2f18fb678afL,0x4665705f2c7L,0x1bb9ca073b8L,0x5c0799d3abdL,0x50e3ccdfa67L,0x6e4d0330fa4L,}
#define KZ_4 (__m512i){0x6e4d0330fa4L,0x9d65fe98853L,0x4665705f2c7L,0x1bb9ca073b8L,0x5c0799d3abdL,0x50e3ccdfa67L,}
#define KZ_5 (__m512i){0x50e3ccdfa67L,0xbf30d010a0bL,0x9d65fe98853L,0x4665705f2c7L,0x1bb9ca073b8L,0x5c0799d3abdL,}//*/

#define idx_opl (__m512i){0UL,2UL,4UL,6UL,0x8UL,0xAUL,0xCUL,0xEUL}
#define idx_oph (__m512i){0x1UL,0x3UL,0x5UL,0x7UL,0x9UL,0xBUL,0xDUL,0xFUL}


#define idx_c10 (__m512i){0x8UL,0x8UL,0x8UL,0x8UL,0x8UL,0x4UL,}
#define idx_c9 (__m512i){0UL,0UL,0UL,0x0UL,0xBUL,0x5UL,}
#define idx_c8 (__m512i){0UL,0UL,0x0UL,0xAUL,0x4UL,0x5UL,}
#define idx_c7 (__m512i){0UL,0x0UL,0x9UL,0x3UL,0x4UL,0x5UL,}
#define idx_c6 (__m512i){0UL,0x8UL,0x2UL,0x3UL,0x4UL,0x5UL,}

void mult_mod_poly_AVX512(int64_t *rop, int64_t *pa, int64_t *pb){

	__m512i pa512 = _mm512_loadu_epi64(pa);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);
	

	__m512i tmp512_b = _mm512_set1_epi64(pb[5]);
	
	__m512i acc512l = _mm512_madd52lo_epu64(zero512,pa512,tmp512_b);
	__m512i acc512h = _mm512_madd52hi_epu64(zero512,pa512,tmp512_b);

	__m512i cx512l = _mm512_permutex2var_epi64(acc512l,idx_c10,zero512);
	__m512i cx512h = _mm512_permutex2var_epi64(acc512h,idx_c10,zero512);

	tmp512_b = _mm512_set1_epi64(pb[4]);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);

	acc512l = _mm512_madd52lo_epu64(acc512l,pa512,tmp512_b);
	acc512h = _mm512_madd52hi_epu64(acc512h,pa512,tmp512_b);
	
	cx512l  = _mm512_permutex2var_epi64(cx512l,idx_c9,acc512l);
	cx512h  = _mm512_permutex2var_epi64(cx512h,idx_c9,acc512h);
	
	tmp512_b = _mm512_set1_epi64(pb[3]);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);

	acc512l = _mm512_madd52lo_epu64(acc512l,pa512,tmp512_b);
	acc512h = _mm512_madd52hi_epu64(acc512h,pa512,tmp512_b);
	
	cx512l  = _mm512_permutex2var_epi64(cx512l,idx_c8,acc512l);
	cx512h  = _mm512_permutex2var_epi64(cx512h,idx_c8,acc512h);
	
	tmp512_b = _mm512_set1_epi64(pb[2]);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);

	acc512l = _mm512_madd52lo_epu64(acc512l,pa512,tmp512_b);
	acc512h = _mm512_madd52hi_epu64(acc512h,pa512,tmp512_b);
	
	cx512l  = _mm512_permutex2var_epi64(cx512l,idx_c7,acc512l);
	cx512h  = _mm512_permutex2var_epi64(cx512h,idx_c7,acc512h);
	
	tmp512_b = _mm512_set1_epi64(pb[1]);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);

	acc512l = _mm512_madd52lo_epu64(acc512l,pa512,tmp512_b);
	acc512h = _mm512_madd52hi_epu64(acc512h,pa512,tmp512_b);
	
	cx512l  = _mm512_permutex2var_epi64(cx512l,idx_c6,acc512l);
	cx512h  = _mm512_permutex2var_epi64(cx512h,idx_c6,acc512h);
	
	tmp512_b = _mm512_set1_epi64(pb[0]);
	pa512 = _mm512_permutexvar_epi64(idx_a,pa512);

	acc512l = _mm512_madd52lo_epu64(acc512l,pa512,tmp512_b);
	acc512h = _mm512_madd52hi_epu64(acc512h,pa512,tmp512_b);
	
	acc512l = _mm512_add_epi64(acc512l,cx512l);
	acc512h = _mm512_add_epi64(acc512h,cx512h);
	
	
	//internal_reduction(rop, tmp_prod_result);
	
	//Computation of Q
	//~ computation of : op*neg_inv_ri_rep_coeff mod(E, mont_phi)
	
	__m512i opl512 = _mm512_permutexvar_epi64(idx_0,acc512l);
	__m512i q512 = _mm512_madd52lo_epu64(zero512,opl512,KQ_0);
	
	opl512 = _mm512_permutexvar_epi64(idx_1,acc512l);
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_1);

	opl512 = _mm512_permutexvar_epi64(idx_2,acc512l); 
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_2);
	
	opl512 = _mm512_permutexvar_epi64(idx_3,acc512l); 
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_3);
	
	opl512 = _mm512_permutexvar_epi64(idx_4,acc512l); 
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_4);
	
	opl512 =  _mm512_permutexvar_epi64(idx_5,acc512l);
	q512 = _mm512_and_epi64(_mm512_madd52lo_epu64(q512,opl512,KQ_5),mask52);


	
	//~ computation of : Q*red_int_coeff mod(E)

	__m512i tmpZero512l = _mm512_madd52lo_epu64(acc512l,KZ_0,_mm512_permutexvar_epi64(idx_0,q512)); 
	__m512i tmpZero512h = _mm512_madd52hi_epu64(acc512h,KZ_0,_mm512_permutexvar_epi64(idx_0,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_1,_mm512_permutexvar_epi64(idx_1,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_1,_mm512_permutexvar_epi64(idx_1,q512));
	 
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_2,_mm512_permutexvar_epi64(idx_2,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_2,_mm512_permutexvar_epi64(idx_2,q512));
	 
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_3,_mm512_permutexvar_epi64(idx_3,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_3,_mm512_permutexvar_epi64(idx_3,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_4,_mm512_permutexvar_epi64(idx_4,q512));
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_4,_mm512_permutexvar_epi64(idx_4,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_5,_mm512_permutexvar_epi64(idx_5,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_5,_mm512_permutexvar_epi64(idx_5,q512)); 
	

	// Final reconstruction
	
	__m512i carry = _mm512_srli_epi64(tmpZero512l,52);
	tmpZero512h = _mm512_add_epi64(carry,tmpZero512h);
	
	_mm512_store_epi64(rop,tmpZero512h);
	
	
}


#define idx_opl (__m512i){0UL,2UL,4UL,6UL,0x8UL,0xAUL,0xCUL,0xEUL}
#define idx_oph (__m512i){0x1UL,0x3UL,0x5UL,0x7UL,0x9UL,0xBUL,0xDUL,0xFUL}


inline void internal_reduction_512(int64_t *rop, int128 *op){


	//Computation of Q
	//~ computation of : op*neg_inv_ri_rep_coeff mod(E, mont_phi)

	__m512i opl512 = _mm512_set1_epi64((uint64_t)op[0]);
	__m512i q512 = _mm512_madd52lo_epu64(zero512,opl512,KQ_0);
	
	opl512 = _mm512_set1_epi64((uint64_t)op[1]);
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_1);

	opl512 = _mm512_set1_epi64((uint64_t)op[2]);
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_2);
	
	opl512 = _mm512_set1_epi64((uint64_t)op[3]);
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_3);
	
	opl512 = _mm512_set1_epi64((uint64_t)op[4]);
	q512 = _mm512_madd52lo_epu64(q512,opl512,KQ_4);
	
	opl512 = _mm512_set1_epi64((uint64_t)op[5]);
	q512 = _mm512_and_epi64(_mm512_madd52lo_epu64(q512,opl512,KQ_5),mask52);



	
	
	//~ computation of : Q*red_int_coeff mod(E)

	__m512i op512l = _mm512_loadu_epi64((int64_t*)op);
	__m512i op512h = _mm512_loadu_epi64((int64_t*)(op+4));
	
	__m512i tmp_op512l = _mm512_permutex2var_epi64(op512l,idx_opl,op512h);
	__m512i tmp_op512h = _mm512_permutex2var_epi64(op512l,idx_oph,op512h);

	op512l = _mm512_and_epi64(tmp_op512l,mask52);

	tmp_op512l = _mm512_srli_epi64(tmp_op512l,52);
	tmp_op512h = _mm512_slli_epi64(tmp_op512h,12);
	
	op512h =_mm512_or_epi64(tmp_op512l,tmp_op512h);
	
	__m512i tmpZero512l = _mm512_madd52lo_epu64(op512l,KZ_0,_mm512_permutexvar_epi64(idx_0,q512)); 
	__m512i tmpZero512h = _mm512_madd52hi_epu64(op512h,KZ_0,_mm512_permutexvar_epi64(idx_0,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_1,_mm512_permutexvar_epi64(idx_1,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_1,_mm512_permutexvar_epi64(idx_1,q512));
	 
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_2,_mm512_permutexvar_epi64(idx_2,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_2,_mm512_permutexvar_epi64(idx_2,q512));
	 
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_3,_mm512_permutexvar_epi64(idx_3,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_3,_mm512_permutexvar_epi64(idx_3,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_4,_mm512_permutexvar_epi64(idx_4,q512));
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_4,_mm512_permutexvar_epi64(idx_4,q512)); 
	
	tmpZero512l = _mm512_madd52lo_epu64(tmpZero512l,KZ_5,_mm512_permutexvar_epi64(idx_5,q512)); 
	tmpZero512h = _mm512_madd52hi_epu64(tmpZero512h,KZ_5,_mm512_permutexvar_epi64(idx_5,q512)); 



	// Final reconstruction
	
	__m512i carry = _mm512_srli_epi64(tmpZero512l,52);
	tmpZero512h = _mm512_add_epi64(carry,tmpZero512h);
	
	_mm512_store_epi64(rop,tmpZero512h);





}








