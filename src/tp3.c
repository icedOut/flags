#include <stdio.h>
#include "parse_args.h"
#include "pays.h"
#include "utils.h"
#include <jansson.h>
#define NOMBRE_PAYS 250

int main(int argc, char **argv) {

	struct Arguments *arguments = parse_arguments(argc, argv);
	char *url;
	url = "DATA/countries.json";
	json_t *root;
	json_error_t error;
	size_t i;

// PASRSAGE DU FICHIER COUNTRIES.JSON

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

	// INITIALISATION DU TABLEAU DE PAYS
	struct Pays liste[NOMBRE_PAYS];	

	// INSERTION DES PAYS DANS UN TABLEAU LOCAL

	for(i = 0; i < json_array_size(root); i++){
    json_t *data, *nom, *common, *region;
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
  	
  	region = json_object_get(data,"region");
  	if(!json_is_string(region)){
  		fprintf(stderr, "Erreur de région");
  		return 1;
  	}


    message_text = json_string_value(common);
    printf("%s\n",message_text);
    liste[i].country = strdupli(message_text);

    message_text = json_string_value(region);
    liste[i].region = strdupli(message_text);
	}
	free_arguments(arguments);
	printf("%s \n",liste[249].country); // TEST
	printf("%s \n", liste[249].region); // TEST
	return 0;

	}

}