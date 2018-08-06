/**
 * Contains all the information parsed from the JSON file
 *
 * 
 *
 * @author Philippe Chartrand
 */

#include <stdbool.h>
#include "parse_args.h"

#define URL_COUNTRIES "https://github.com/mledoze/countries/blob/master/countries.json"
#define URL_SIZE     256

// --------- //
// --TYPES-- //
// --------- //

struct Pays{
	char *country;			/**< country code */
	char *country_code;		/**< 3 letter country codde */
	char *region;		    /**< Contient of the coutry */
	char *capital;			/**< Capital of the country */
	char *flag;				/**< Flag of the country */
	char *borders[]; 		/**< Borders of the country */
};




// --------- //
// FUNCTIONS //
// --------- //

/**
 * Returns the parsed JSON object countries
 */
char* get_json();