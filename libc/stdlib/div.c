#include "stdlib.h"

div_t div(int numer, int denom) {
	div_t ret;
	ret.quot = numer / denom;
	ret.rem = numer - denom * ret.quot;
	if (ret.quot < 0 && ret.rem > 0) {
		ret.quot += 1;
		ret.rem -= denom;
	}
	return ret;
}
