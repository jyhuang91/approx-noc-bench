#ifndef __TYPE__
#define __TYPE__
//#define DEBUG

#if defined(BASELINE) && defined(ENABLE_SSE4)
#error BASELINE and ENABLE_SSE4 are mutually exclusive
#endif

#define FTYPE float
//#define FTYPE double
#define BLOCK_SIZE 16 // Blocking to allow better caching

#define RANDSEEDVAL 100
#define DEFAULT_NUM_TRIALS  102400

typedef struct
{
  int Id;
  FTYPE dSimSwaptionMeanPrice;
  FTYPE dSimSwaptionStdError;

  int iN;
  FTYPE dYears;
  int iFactors;
  FTYPE *pdYield;
  FTYPE **ppdFactors;
} parm;
 
typedef struct
{
	FTYPE dStrike;
	FTYPE dCompounding;
	FTYPE dMaturity;
	FTYPE dTenor;
	FTYPE dPaymentInterval;
} parm_fp;


#endif //__TYPE__
