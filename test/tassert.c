#define NDEBUG

#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int val = 0;

static void field_abort(int sig) {
	if (val == 1) {
		puts("SUCCESS testing <assert.h>");
		exit(EXIT_SUCCESS);
	} else {
		puts("FAILURE testing <assert.h>");
		exit(EXIT_FAILURE);
	}
}

static void dummy(void) {
	assert(val == 1);
	return;
}

#undef NDEBUG
#include <assert.h>

int main(void) {
	assert(signal(SIGABRT, &field_abort) != SIG_ERR);
	dummy();
	assert(val == 0);
	fputs("Sample assertion failure message:\n", stderr);
	val = 1;
	assert(val == 0);
	puts("FAILURE testing <assert.h>");
	return EXIT_FAILURE;
}
