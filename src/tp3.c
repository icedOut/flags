#include <stdio.h>
#include "parse_args.h"
#include "pays.h"
#include <jansson.h>

int main(int argc, char **argv) {

	struct Arguments *arguments = parse_arguments(argc, argv);
	char *url;
	url = "../DATA/countries.json";
	json_t *root;
	json_error_t error;


	if(arguments->status != TP3_OK) {
		return arguments->status;
	} else {
		printf("Arguments OK");
	
	root = json_load_file( url, 0, &error);

	if(!root) {
		 printf( "Erreur de parsage");
	}else{
		printf("JSON Parsé avec succès");
	}	
	}
	free_arguments(arguments);
	return 0;
}