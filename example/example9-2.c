#define NDEBUG
#include <assert.h>

void
func(void)
{
        int c;
        assert((c = getchar()) != EOF);
        putchar(c);
}