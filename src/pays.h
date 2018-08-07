/**
 * Contains all the information parsed from the JSON file
 *
 * 
 *
 * @author Philippe Chartrand
 */

#include <stdbool.h>
#include "parse_args.h"


// --------- //
// --TYPES-- //
// --------- //

struct Pays{
	char *country;			/**< country code */
	char *country_code;		/**< 3 letter country codde */
	char *region;		    /**< Contient of the coutry */
	char *capital;			/**< Capital of the country */
	char *flag;				/**< Flag of the country */
	char *borders[10]; 		/**< Borders of the country */
	char *languages[25];	/**< Languages of the country */
	int  nb_borders ; 		/**< Number of borders the country has */
	int  nb_languages ; 	/**< Number of languages the country has */
};




// --------- //
// FUNCTIONS //
// --------- //

/**
 * Returns the parsed JSON object countries
 */
char* get_json();