#ifndef USEFUL_FUNCTS_N5_AMNS
#define USEFUL_FUNCTS_N5_AMNS


void init_data_n5_amns(	mpz_t modul_p, mpz_t gama_pow[POLY_DEG] );

void free_data_n5_amns(	mpz_t modul_p, mpz_t gama_pow[POLY_DEG] );

void from_int_to_amns_n5_amns(int64_t *rop, mpz_t op);

void from_amns_to_int_n5_amns(mpz_t rop, int64_t *op, mpz_t modul_p, mpz_t gama_pow[POLY_DEG] );

int cmp_poly_evals_n5_amns(int64_t *pa, int64_t *pb, mpz_t modul_p, mpz_t gama_pow[POLY_DEG] );

void copy_poly_n5_amns(int64_t *rop, int64_t *op);

void add_lpoly_n5_amns(int128 *rop, int128 *pa, int128 *pb);

void scalar_mult_lpoly_n5_amns(int128 *rop, int64_t *op, uint64_t scalar);

void from_mont_domain_n5_amns(int64_t *rop, int64_t *op);

void print_element_n5_amns(int64_t *poly);

#endif

