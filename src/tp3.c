#include <stdio.h>
#include "parse_args.h"
#include "pays.h"
#include <jansson.h>

int main(int argc, char **argv) {

	struct Arguments *arguments = parse_arguments(argc, argv);
	char *url;
	url = "DATA/countries.json";
	json_t *root;
	json_error_t error;


	if(arguments->status != TP3_OK) {
		return arguments->status;
	} else {
		printf("Arguments OK \n");
	
	root = json_load_file(url, 0, &error);

	if(!root) {
		 printf( "Erreur de parsage \n");
	}else{
		printf("JSON Parsé avec succès \n");
	}
if(!json_is_array(root))
{
    fprintf(stderr, "error: root is not an array\n");
    json_decref(root);
    return 1;
}
	}
	free_arguments(arguments);
	return 0;
}