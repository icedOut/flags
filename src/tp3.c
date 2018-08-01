#include <stdio.h>
#include "parse_args.h"

int main(int argc, char **argv) {
	struct Arguments *arguments = parse_arguments(argc, argv);

	if(arguments->status != TP3_OK) {
		return arguments->status;
	} else {
		printf("Arguments OK");
	}
	free_arguments(arguments);
	return 0;
}