#include <limits.h>

#if ULONG_MAX+1 != 0
      printf("Preprocessor: ULONG_MAX+1 != 0\n");
#endif

      if(ULONG_MAX+1 != 0)
              printf("Runtime: ULONG_MAX+1 != 0\n");