#ifndef USEFUL_FUNCTS
#define USEFUL_FUNCTS


void init_data();

void free_data();

void from_int_to_pmns(int64_t *rop, mpz_t op);

void from_pmns_to_int(mpz_t rop, int64_t *op, mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]);

int cmp_poly_evals(int64_t *pa, int64_t *pb, mpz_t modul_p, mpz_t gama_pow[POLY_DEG_N6_PMNS]);

void copy_poly(int64_t *rop, int64_t *op);

void add_lpoly(int128 *rop, int128 *pa, int128 *pb);

void scalar_mult_lpoly(int128 *rop, int64_t *op, uint64_t scalar);

void from_mont_domain(int64_t *rop, int64_t *op);

void print_element(int64_t *poly);

#endif

