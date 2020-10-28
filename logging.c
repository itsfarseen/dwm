#include <stdio.h>
#include <stdlib.h>
#include "logging.h"

static FILE* log_file;

FILE* log_fp() {
	if(log_file == NULL) {
		char *home = getenv("HOME");
		char filename[256];
		sprintf(filename, "%s/.dwm.log", home);
		log_file = fopen(filename, "ae");
		setvbuf( log_file, (char *)NULL, _IONBF, 0 );
	}
	return log_file;
}
