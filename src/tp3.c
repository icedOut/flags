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
	size_t i;


	if(arguments->status != TP3_OK) {
		return arguments->status;
	} else {
		printf("Arguments OK \n");
	
	root = json_load_file(url, 0, &error);

	if(!root) {
		 fprintf(stderr, "Erreur de parsage \n");
		 return 1;
	}else{
		printf("JSON Parsé avec succès \n");
	}
	if(!json_is_array(root))
	{
    fprintf(stderr, "Erreur de racine\n");
    json_decref(root);
    return 1;
	}

	for(i = 0; i < json_array_size(root); i++){
    json_t *data, *nom, *common, *capitale;
    const char *message_text;

    data = json_array_get(root, i);
    if(!json_is_object(data)){
    
        fprintf(stderr, "Erreur de parsage");
        json_decref(root);
        return 1;
    }

    nom = json_object_get(data,"name");
    if(!json_is_object(nom)){
    	fprintf( stderr , "Erreur de nom");
    	return 1;
    }
     common = json_object_get(nom,"common");
    if(!json_is_string(common)){
    	fprintf(stderr, "Erreur de nom commun");	
   	    return 1;
    }
    message_text = json_string_value(common);
    printf("%s\n",message_text);

	}
	free_arguments(arguments);
	return 0;
	}

}