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
	enum Region region;		/**< Contient of the coutry */
	char *borders[]; 		/**< Borders of the country */
	char *capital;			/**< Capital of the country */
	char *flag;				/**< Flag of the country */
	
	
}
