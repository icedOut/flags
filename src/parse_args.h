/**
 * Provides basic services to process the main arguments. Error codes are also
 * provided in the case of invalid input from the user.
 *
 * @author Philippe Chartrand - Insipred from Parse_args.c - tp2 : Alexandre Blondin massé
 */
#include <stdbool.h>
#include "cellular.h"

#define TEXT_TYPE "text"
#define DOT_TYPE "dot"
#define PNG_TYPE "png"
#define SUPPORTED_TYPES "\"" TEXT_TYPE "\", \"" DOT_TYPE "\" and \""\ PNG_TYPE "\""
#define DEFAULT_FORMAT 
#define USAGE "\
Usage: bin/tp3 [--help] [--output-format FORMAT] [--output-filename FILENAME] \n\
 	[--show-languages] [--show-capital] [--show-borders] [--show-flag]\n\
 	[--country COUNTRY] [--region REGION]\n\
\n\
Displays information about countries.
\n\
Optional arguments:\n\
  --help                     Show this help message and exit.\n\
  --output-format FORMAT     Selects the ouput format (either "text", "dot" or "png").\n\
                             The "dot" format is the one recognized by Graphviz.\n\
                             The default format is "text".\n\
  --output-filename FILENAME The name of the output filename. This argument is\n\
                             mandatory for the "png" format. For the "text" and "dot"\n\
                             format, the result is printed on stdout if no output\n\
                             filename is given.\n\
  --show-languages           The official languages of each country are displayed.\n\
  --show-capital             The capital of each country is displayed.\n\
  --show-borders             The borders of each country are displayed.\n\
  --show-flag                The flag of each country is displayed\n\
                             (only for "dot" and "png" format).\n\
  --country COUNTRY          The country code (e.g. "can", "usa") to be displayed.\n\
  --region REGION            The region of the countries to be displayed.\n\
                             The supported regions are "africa", "americas",\n\
                             "asia", "europe" and "oceania".\n\
"

/**
 * The status of the program.
 */
enum Status {	
	TP2_OK,					/**< Everything is OK */
	TP2_ERROR
};


/**
 * The parsed arguments
 */
struct Arguments {
	char *format; 					/**< Format to use */
	char *filename; 				/**< Filename to use for output file */
	char *country; 					/**< country code to be displayed */
	char *region; 					/**< Region to be displayed */
	bool show_languages;			/**< Are we showing the languages? */
	bool show_capitals;				/**< Are we showing the country's capitals? */
	bool show_borders;				/**< Are we showing the borders in between countrys? */
	bool show_flags;				/**< Are we showing the country's flags? */
	enum Status status;				/**< The status of the parsing */
}

/**
 * Returns the parsed arguments provided by the user.
 *
 * @param argc  The number of arguments including the program name
 * @param argv  The arguments provided by the user
 * @return      The parsed arguments
 */
struct Arguments *parse_arguments(int argc, char **argv);

/**
 * Frees the arguments.
 *
 * @param arguments  The arguments to free
 */
void free_arguments(struct Arguments *arguments);




