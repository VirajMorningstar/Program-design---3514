/*************************************************************
Author Name :-              Viraj Amarasinghe
* Date:-                    04/17/2022 
*Prject Name:-              project 8
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

======================================================================
*Description: 
The program manage the database of a T-shirt store. The programe allove the user to add itemes to the ordred inventory in 
an alphabetical order and it seach for items of the inventory. 
so they can track all the items in the store. 
======================================================================   
*/


//********************Program begin here**********************



#include "tshirt.h"
#include "readline.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() 
{
	char code;

	struct tshirt *inventory = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);
				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':
				print_inventory(inventory);
				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
	return 0;
}


/*==============================END OF THE PROGRAM> Have a great day. Thank you for reading. Come Again. lol. :) ========================================================*/

