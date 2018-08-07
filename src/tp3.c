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

	// INSERTION DES INFORMATIONS DES PAYS DANS UN TABLEAU LOCAL

for(i = 0; i < json_array_size(root); i++){
    json_t *data, *nom, *common, *region , *code , *flag , *capitalArray , *capital , *borderArray , *border;
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

  	code = json_object_get(data,"cca2");
  	if(!json_is_string(code)){
  		fprintf(stderr, "Erreur de code de pays");
  		return 1;
  	}

  	flag = json_object_get(data,"flag");
  	if(!json_is_string(flag)){
  		fprintf(stderr, "Erreur de drapeau");
  		return 1;
  	}

  	capitalArray = json_object_get(data,"capital");
  	if(!json_is_array(capitalArray)){
  		printf("Erreur: capitalArray");
  		return 1;
  	}
  	size_t c;
  	if ((int)json_array_size(capitalArray)>0){
  	capital = json_array_get(capitalArray, c = 0);
    }

    borderArray = json_object_get(data,"borders");
    if(!json_is_array(borderArray)){
    	printf("Erreur: BorderArray");
    }
    int nb_borders = 0;
    for (c = 0; c < json_array_size(borderArray); c++){
    border = json_array_get(borderArray,c);
    message_text = json_string_value(border);
    liste[i].borders[c] =  strdupli(message_text);
    nb_borders ++;
    }
    liste[i].nb_borders = nb_borders ;

    message_text = json_string_value(common);
    printf("%s\n",message_text);
    liste[i].country = strdupli(message_text);

    message_text = json_string_value(region);
    liste[i].region = strdupli(message_text);

    message_text = json_string_value(code);
    liste[i].country_code = strdupli(message_text);

    message_text = json_string_value(flag);
     liste[i].flag = strdupli(message_text);

    if (capital != NULL) {
    message_text = json_string_value(capital);
    liste[i].capital = strdupli(message_text);	
    } 
}
	free_arguments(arguments);
	printf("\nTEST : PAYS # 259 : \n"); // 		TEST
	printf(" Pays : %s \n",liste[249].country); //  	TEST
	printf(" Region : %s \n", liste[249].region); // 		 TEST
	printf(" Code: %s \n", liste[249].country_code); // TEST
	printf(" Flag:%s \n",liste[249].flag); // 		TEST
	printf(" Capital: %s \n",liste[249].capital); // 		TEST
	printf(" %d Borders: %s %s %s %s  \n",liste[249].nb_borders, liste[249].borders[0],liste[249].borders[1],liste[249].borders[2],liste[249].borders[3]); // TEST
	return 0;

	}

}