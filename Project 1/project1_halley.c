/*Author Name :- Viraj Amarasinghe
Prject Name:- project1_halley
Class :- COP3514 Progrm Design
Date:- 01/23/2022
Computer Engeineeering - University of South Florida. 
=========================================================
This program calculate the next apperence of Halley given any year after 1986 as input.
*/
//Halley is visible to naked eye every 76 years
//Last appearance was 1986
//=====================================================================
 
#include <stdio.h> 
int main()
{
    //input 
    int given_year; //user input
    int nof_time_p; //nuber of time pass
    int next_year ;
    printf("Enter the Year");
    scanf("%d", &given_year);
    nof_time_p= (given_year - 1986)/76; 
    next_year = (nof_time_p +1)*76+1986;

    if(given_year > 1986){
        printf("Next Year appearance: %d, \n", next_year);
        return 0;
    }
    //if user input less than 1986 print this nessage

    if (given_year <= 1986)
    {
        printf("Input year must be greater than 1986");
        return 0;
    }
    return 0;
}