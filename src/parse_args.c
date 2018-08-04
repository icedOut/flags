/**
 * Implements parse_args.h, using the getopt library to simplify the
 * processing.
 *
 * @author Philippe Chartrand inspired from parse_args.c TP2 - Alexandre Blondin Masse
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "parse_args.h"
#include "utils.h"



#define DELIM ','
#define DELIMS ","

// ------- //
// Private //
// ------- //

/**
 * Retrives the type of output format from a string.
 *
 * @param s          The string from which the type is retrieved
 * @param arguments  The parsed arguments
 * @return           The status of the extraction
 */
enum Status get_type(const char *s,
                     struct Arguments *arguments) {
	if (strcmp(s, TEXT_TYPE) == 0){
	arguments->format = TEXT ;
	} else if (strcmp(s, DOT_TYPE) == 0){
	arguments->format = DOT;
	} else if (strcmp(s, PNG_TYPE) == 0 ){
	arguments->format = PNG;
	} else {
		return TP3_WRONG_FORMAT;
	}
	return TP3_OK;
}

/**
 * Retrives the country code from a string.
 *
 * @param s          The string from which the allowed cells are retrieved
 * @param arguments  The parsed arguments
 * @return           The status of the extraction
 */

enum Status get_country(const char *s,
						  struct Arguments *arguments){
	if (strlen(s) > 4){
		return TP3_WRONG_COUNTRY;
	}else{
	arguments->country = strdupli(s);
	return TP3_OK;
	}
}

/**
 * Retrives the filename for output file from a string.
 *
 * @param s          The string from which the allowed cells are retrieved
 * @param arguments  The parsed arguments
 * @return           The status of the extraction
 */

enum Status get_filename(const char *s,
						  struct Arguments *arguments){
	if (strlen(s)> 30) return TP3_WRONG_FILENAME;
	else{
	arguments->filename = strdupli(s);
	return TP3_OK;
	}
}




/**
 * Retrives the region from a string.
 *
 * @param s          The string from which the region is retrieved
 * @param arguments  The parsed arguments
 * @return           The status of the extraction
 */
enum Status get_region(const char*s,
						struct Arguments *arguments){
	if (strcmp(s, REGION_AMERICAS) == 0){
	arguments->region = AMERICAS;
	} else if (strcmp(s, REGION_AFRICA) == 0){
	arguments->region = AFRICA;
	} else if (strcmp(s, REGION_ASIA) == 0){
	arguments->region = ASIA;
	} else if (strcmp(s,REGION_EUROPE) == 0){
	arguments->region = EUROPE;
	} else if (strcmp(s,REGION_OCEANIA) == 0){
	arguments->region = OCEANIA;
	} else {
		return TP3_WRONG_REGION;
	}
	return TP3_OK;
}	
	

// ------ //
// Public //
// ------ //


struct Arguments *parse_arguments(int argc, char *argv[]) {
    struct Arguments *arguments = malloc(sizeof(struct Arguments));

	// Temporary variables
	bool show_help = false;

	// Default argument    
	arguments->status = TP3_OK;
	arguments->filename = NULL;
	arguments->country = NULL;
	arguments->show_languages = false;
	arguments->show_capitals = false;
	arguments->show_borders = false;
	arguments->show_flags = false;
	arguments->format = TEXT;
	arguments->region = ALL;

	// Resets index
    optind = 0;
    struct option long_opts[] = {
    	// set flag
    	{"help",			no_argument,		0,'h'},
    	{"show-languages",	no_argument,		0,'l'},
    	{"show-flags",		no_argument,		0,'f'},
    	{"show-borders",	no_argument,		0,'b'},
        {"show-capital",    no_argument,        0,'d'},
    	//Don't set flag
    	{"region",			required_argument,	0,'r'},
    	{"country",			required_argument,	0,'c'},
    	{"output-format",	required_argument,	0,'o'},
    	{"output-filename",	required_argument,	0,'u'},
    	{0, 0, 0, 0}
    };	

    // Parse options
    while (true) {
    	int option_index = 0;
    	int c = getopt_long(argc, argv, "hlfbdr:c:o:u:",
    						long_opts, &option_index);
    	if (c == -1) break;
    	switch (c) {
    		case 'h': show_help = true;
    				  break;
    		case 'l': arguments->show_languages = true;
    				  break;
    	    case 'f': arguments->show_flags = true;
    	    		  break;
    	    case 'b': arguments->show_borders = true;
    	    		  break;
            case 'd': arguments->show_capitals = true;
                      break;
    	    case 'r': if (arguments->status == TP3_OK ){
    	    		   arguments->status =
    	    		   		get_region(optarg, arguments);
    	    		}
    	    		break;
    	    case 'c': if (arguments->status == TP3_OK ){
    	    		  arguments->status =
    	    		  		get_country(optarg, arguments);
    	    		}
    	    		break;
    	    case 'o': if (arguments->status == TP3_OK){
    	    		  arguments->status =
    	    		  		get_type(optarg, arguments);
    	   			}
    	   			break;
    	    case 'u': if (arguments->status == TP3_OK){
    	    		  arguments->status =
    	    		  		get_filename(optarg, arguments);
    	    		}
    	    		break;
    	    case '?': if (arguments->status == TP3_OK) {
    	    			arguments->status = TP3_BAD_OPTION;
    	    		}
    	    		break;
    	}

    }
    
    if (optind < argc) {
        printf("Error: too many arguments\n");
        printf(USAGE);
        arguments->status = TP3_ERROR_TOO_MANY_ARGUMENTS;  
    } else if (show_help){
    	printf(USAGE);
    	exit(TP3_OK);
    } else if (arguments->status == TP3_WRONG_REGION){
    	printf("Error: unrecognized Region. \n");
    	printf("The supported regions are americas , africas, asia , oceania  and europe");
    	printf(USAGE);
    } else if (arguments -> status == TP3_WRONG_FORMAT){
    	printf("Error: unrecognized Format. \n");
    	printf("The supported formats are dot, png and txt .");
    	printf(USAGE);
    } else if (arguments -> status == TP3_BAD_OPTION){
    	printf("Error: arguments do not have the right format. \n");
    	printf(USAGE);
    } else if (arguments -> status == TP3_WRONG_COUNTRY){
    	printf("Error: unrecognized country code \n");
    	printf(" Country codes have 3 characters. Example:  can -> Canada \n");
    	printf(USAGE);
    } else if (arguments -> status == TP3_WRONG_FILENAME){
    	printf("ERROR: Filename is not valid");
    	printf("Filename has a maximum of 30 characters");
    }
    return arguments;
}

void free_arguments(struct Arguments *arguments) {
    free(arguments->filename);
    free(arguments->country);
    free(arguments);
}
