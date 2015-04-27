#undef assert

#ifdef NDEBUG
#define assert(e) ((void) 0)
#else /* NDEBUG */
#define assert(e) ((void) ((e) ? 0 : _wassert(#e, __FILE__, __LINE__)))

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void _wassert(const char *, const char *, unsigned int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* NDEBUG */
