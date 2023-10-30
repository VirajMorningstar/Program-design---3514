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


//////////////////////
// data definitions //
//////////////////////

#ifndef TSHIRT_H
#define TSHIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt {
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;
	struct tshirt *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);

#endif