#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "parse_args.h"
#include "pays.h"
#include <string.h>
#include <stdbool.h>
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
	root = json_load_file(url, 0, &error);

	if(!root) {
		 fprintf(stderr, "Erreur de parsage \n");
		 return 1;
	}
	if(!json_is_array(root))
	{
    fprintf(stderr, "Erreur de racine\n");
    json_decref(root);
    return 1;
	}

	// INITIALISATION DU TABLEAU DE PAYS

	struct Pays liste[NOMBRE_PAYS];	

	// INSERTION DES INFORMATIONS DES PAYS DANS LE TABLEAU

for(i = 0; i < json_array_size(root); i++){
    json_t *data, *nom, *common, *region , *code , *flag , *capitalArray , *language, *languageObject ,*capital , *borderArray , *border;
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

  	code = json_object_get(data,"cca3");
  	if(!json_is_string(code)){
  		fprintf(stderr, "Erreur de code de pays");
  		return 1;
  	}

  	flag = json_object_get(data,"flag");
  	if(!json_is_string(flag)){
  		fprintf(stderr, "Erreur de drapeau");
  		return 1;
  	}
  	int nb_languages = 0 ;
  	languageObject = json_object_get(data,"languages");
  	void *iter = json_object_iter(languageObject);
  	while(iter){
  	language = json_object_iter_value(iter);
  	message_text = json_string_value(language);
  	liste[i].languages[nb_languages] = strdupli(message_text);
  	nb_languages ++;
  	iter = json_object_iter_next(languageObject, iter);
  	}
  	liste[i].nb_languages = nb_languages;
  


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
    liste[i].nb_borders = nb_borders;
    message_text = json_string_value(common);
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


// AFFICHAGE DES PAYS SELON LES ARGUMENTS

int i,j,k;
bool code_is_valid = false;
switch(arguments->format){

	case TEXT:
	 if(arguments->country != NULL){

	 for (j=0; j<NOMBRE_PAYS;j++){	
	 if(strcasecmp(arguments->country,liste[j].country_code) == 0 ){
	 	code_is_valid = true;
	 	printf("Nom : %s\n", liste[j].country);
		printf("Code : %s\n", liste[j].country_code);
		if(arguments->show_capitals){
		printf("Capital: %s\n", liste[j].capital);
		}
		if(arguments->show_languages){
		printf("Languages: ");
		for(k=0; k<liste[j].nb_languages; k++){
		printf("%s ", liste[j].languages[k]);	
		}
		printf("\n");
		}
		if(arguments->show_borders){
		printf("Borders: ");
		for(k=0;k<liste[j].nb_borders; k++){
		printf("%s ", liste[j].borders[k]);
		}
		printf("\n");
		}
	 }

	}
	 if (!code_is_valid){
	 	fprintf(stderr,"Le code de pays entrée est invalide");
	 	return 1;
	    }
	} 
	
	else{	
		 switch (arguments->region){
		 	case AFRICA:
		 	for (j=0;j<NOMBRE_PAYS;j++){
		 		if(strcasecmp("Africa",liste[j].region) == 0){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}
			printf("\n");		
		 	}
		 }
		 	break;

		 	case AMERICAS:
		 	for (j=0;j<NOMBRE_PAYS;j++){
		 		if(strcasecmp("Americas",liste[j].region) == 0){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}
			printf("\n");		
		 	}

		 	}
		 	break;

		 	case ASIA:
		 	for (j=0;j<NOMBRE_PAYS;j++){
		 		if(strcasecmp("Asia",liste[j].region) == 0){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}	
			printf("\n");	
		 	}
		 }
		break;

			case EUROPE:
			for (j=0;j<NOMBRE_PAYS;j++){
		 		if(strcasecmp("Europe",liste[j].region) == 0){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}	
			printf("\n");
		 	}		 	

		 }
		 break;

		 	case OCEANIA:
		 	for (j=0;j<NOMBRE_PAYS;j++){
		 		if(strcasecmp("Oceania",liste[j].region) == 0){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}
			printf("\n");		
		 	}		 	

		 }
		 break;

		 	case ALL:
		 	for (j=0;j<NOMBRE_PAYS;j++){
		 		printf("Nom : %s\n", liste[j].country);
				printf("Code : %s\n", liste[j].country_code);
				if(arguments->show_capitals){
				printf("Capital: %s\n", liste[j].capital);
				}
				if(arguments->show_languages){
				printf("Languages: ");
				for(k=0; k<liste[j].nb_languages; k++){
				printf("%s ", liste[j].languages[k]);	
				}
				printf("\n");
				}
				if(arguments->show_borders){
				printf("Borders: ");
				for(k=0;k<liste[j].nb_borders; k++){
				printf("%s ", liste[j].borders[k]);
				}
				printf("\n");
				}	
		 printf("\n");		 	
		 }
		 break;
		}
	}	
	break;

	case DOT:
	if(arguments->country != NULL){
	for (j=0; j<NOMBRE_PAYS;j++){

		if(strcasecmp(arguments->country,liste[j].country_code) == 0 ){
		printf ("graph { \n");
		printf ("   shape = none,\n");
		printf ("   label = <<table border=\"0\" cellspacing=\"0\">\n");
		printf ("<tr><td align=\"left\" border=\"1\"><b>Name</b>: %s </td></tr>\n",liste[j].country);
		printf ("<tr><td align=\"left\" border=\"1\"><b>Name</b>: %s </td></tr>\n",liste[j].country_code);

		if (arguments->show_flags){
		printf ("    <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"https://github.com/ablondin/countries/blob/png-flags/data/%s.png\" scale=\"true\"/></td></tr>\n",liste[j].country_code);
		}
		if (arguments->show_capitals){
		printf ("<tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>\n",liste[j].capital);
		}	
		if ( arguments->show_languages){
			printf("<tr><td align=\"left\" border=\"1\"><b>Language</b>:");
		for (i = 0; i < liste[j].nb_languages ; i++){
			printf ("%s ",liste[j].languages[i]);
		}
			printf ("</td></tr>\n");
		}
		if (arguments-> show_borders){
			printf("<tr><td> align=\"left\" border=\"1\"><b>Borders</b>:");
		for (i = 0; i < liste[j].nb_borders ; i++){
			printf("%s ",liste[j].borders[i]);
		}
			printf("</td></tr>\n");
			}	
			printf("</table>>\n");	
			printf("];\n");
			printf("}");
		}	
	}
}else if (arguments->country == NULL){
	for (j=0; j < NOMBRE_PAYS;j++){
		printf ("graph { \n");
		printf ("   shape = none,\n");
		printf ("   label = <<table border=\"0\" cellspacing=\"0\">\n");
		printf ("<tr><td align=\"left\" border=\"1\"><b>Name</b>: %s </td></tr>\n",liste[j].country);
		printf ("<tr><td align=\"left\" border=\"1\"><b>Name</b>: %s </td></tr>\n",liste[j].country_code);

		if (arguments->show_flags){
		printf ("    <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\"><img src=\"https://github.com/ablondin/countries/blob/png-flags/data/%s.png\" scale=\"true\"/></td></tr>\n",liste[j].country_code);
		}
		if (arguments->show_capitals){
		printf ("<tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>\n",liste[j].capital);
		}	
		if ( arguments->show_languages){
			printf("<tr><td align=\"left\" border=\"1\"><b>Language</b>:");
		for (i = 0; i < liste[j].nb_languages ; i++){
			printf ("%s ",liste[j].languages[i]);
		}
			printf ("</td></tr>\n");
		}
		if (arguments-> show_borders){
			printf("<tr><td> align=\"left\" border=\"1\"><b>Borders</b>:");
		for (i = 0; i < liste[j].nb_borders ; i++){
			printf("%s ",liste[j].borders[i]);
		}
			printf("</td></tr>\n");
			}	
			printf("</table>>\n");	
			printf("];\n");
			printf("}");
			printf("\n");
	}
}
	break;

	case PNG:
	printf(" en cour de développement \n");
	break;
}
	free_arguments(arguments);
	return 0;
	}

}