#ifndef POLYS_P
#define POLYS_P



//~ representations of polynomials Pi, used for conversion into the AMNS
//~ Note: each Pi is a representation of ((1 << RHO_LOG2)^i * phi^2)
static int64_t polys_P_n6_pmns[NB_COEFF_N6_PMNS][NB_COEFF_N6_PMNS] = {
	{0xa84c7201ed8L, 0x138ce43f6adbL, 0x112f90f72eb6L, 0xe5e533fe3aeL, 0xc0a4171e714L, 0x98d18150cd4L},
	{0xa5fddd1fba8L, 0x12954a72af72L, 0xf80a5ba2a50L, 0xfddbdab768aL, 0x1138271e5413L, 0xdcab47c8865L},
	{0xb9c4dcd9b62L, 0x11bca3a2f875L, 0x11d0b8a6c0e5L, 0xc72d380d444L, 0xae09696308cL, 0xafce2744bebL},
	{0xa8d4e68e615L, 0x1065c7795946L, 0xf5c97980508L, 0xca216f9c35cL, 0xa66b8300061L, 0xbff600de3e7L},
	{0x513a8974554L, 0x934698f4788L, 0xa64d81a75faL, 0x72b0d5d2636L, 0x582a396f88cL, 0x41347fac41fL},
	{0x3a2f04ef1adL, 0x6b78e7adeeeL, 0x8f9f33ac05eL, 0x88b1de71734L, 0x94b9c87e3d5L, 0x5f2703b7fc2L}};

static int64_t polys_P_n5_pmns[NB_COEFF][NB_COEFF] = {
	{0xed118f2a3d668L, 0x169a09d3b4b10aL, 0x16302470e5b3b1L, 0x1f3420c5e6cf93L, 0x1aaf905ee7a4eeL},
	{0x12541e5cb85cc0L, 0x1bb32959de9c3aL, 0x1987e3bba401b8L, 0x211c9ee62f05c9L, 0x1a55d3d047937aL},
	{0xa0596fe54002cL, 0xf753233f54436L, 0x10e21bb16fe249L, 0x15a17274898bc3L, 0x12003cc56b1e57L},
	{0xbd87fc7c59112L, 0x12cbbef18981abL, 0xe3f1f33bb7961L, 0xf20e8bd3a55e3L, 0x10a36209df6db8L},
	{0x107af8c3e0e57aL, 0x1e55d2e7da821eL, 0x1afefb7e86b9f6L, 0x1def553e396de5L, 0x192ad4a56a4421L}};

static int64_t polys_P_n5_amns[NB_COEFF][NB_COEFF] = {
	{0x1b948113204510L, 0xfd4218ecb7512L, 0x145b3fa5901760L, 0xe3102cb65f913L, 0xcf0b8428b9d3aL},
	{0x244cf52148d3acL, 0x1aebdf0b5aad20L, 0x1f907bc1062a6dL, 0x14c14beebe68f8L, 0x15b152cd7a27f2L},
	{0x1876672555912cL, 0x19693e40fc343bL, 0xfb4e7029e56e3L, 0x145935deb8293cL, 0xbd99adf1fc05aL},
	{0x1b8afee61a6e75L, 0x1499b0df2d645fL, 0x1d2b4e7f6d68e4L, 0xd3d9fd5d7be6fL, 0x1337d20d4ae782L},
	{0x219a3bd83935bfL, 0x16008853b30707L, 0x1bec08d050e0efL, 0x146497256bb387L, 0x11f97b14700b7eL}};



#endif

