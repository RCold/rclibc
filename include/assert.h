#undef assert

#ifdef NDEBUG
#define assert(e) ((void) 0)
#else
#define assert(e) ((e) ? (void) 0 : _wassert(#e, __FILE__, __LINE__))

#include <sys/cdefs.h>

__BEGIN_DECLS

void _wassert(const char *, const char *, unsigned int);

__END_DECLS

#endif /* NDEBUG */
