#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
	if(argc != 4) {
		fprintf(stderr, "syntax: %s date oldformat newformat\n", argv[0]);
		return(1);
	}
	struct tm date;
	char* dummy = strptime(argv[1], argv[2], &date);
	if(dummy == NULL) {
		fprintf(stderr, "unable to parse date: %s using format: %s\n", argv[1], argv[2]);
		return(1);
	}
	char buf[2048];
	size_t err = strftime(buf, 2048, argv[3], &date);
	if(err == 0) {
		fprintf(stderr, "unable to parse date format: %s\n", argv[3]);
	}
	puts(buf);
}
