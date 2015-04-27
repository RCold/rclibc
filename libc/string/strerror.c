#include "errno.h"
#include "string.h"

#define ERRMSGLEN 20

char *strerror(int errnum) {
	static char errmsg[ERRMSGLEN + 1];
	switch (errnum) {
	case 0:
		strcpy(errmsg, "No error");
		break;
#ifdef EDOM
	case EDOM:
		strcpy(errmsg, "Domain error");
		break;
#endif
#ifdef ERANGE
	case ERANGE:
		strcpy(errmsg, "Range error");
		break;
#endif
	default:
		strcpy(errmsg, "Unknown error");
	}
	return errmsg;
}
