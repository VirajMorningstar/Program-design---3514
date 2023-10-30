/*
Author Name :- Viraj Amarasinghe
Prject Name:- project2_panic
Class :- COP3514 Progrm Design
Computer Engeineeering - University of South Florida. 
Description: This program calculate the amount of money that the client need to buy items. It takes three inputs and calculate the total price of items
and compare with the money that client has. this will tell you whether the client need more moeny or not. 
*/
#include <stdio.h>
int main()
{
    // declaring the variables
    int item_price = 0;  //price of unit
    int n_units =0;   //Number of units
    int total_cost = 0; // total cost
    int dolor_needs = 0; // Amount of dollers need to buy the items.
    int a_ofmoney = 0; // Amount of money that client has in the wallet. 

    // ==========input============
    // enter price 
    printf("Enter Item Price: \n");
    scanf("%d",&item_price);
    if(item_price <= 0)
    {
        printf("Invalid price. \n");
        printf("Price must be greater than 0. \n");
        return 1;

    }
    //enter number of units
    printf("Enter Number of Units: \n");
    scanf("%d", &n_units);
    if (n_units <= 0)
    { 
             
        printf(" Invalid Number of Units.\n");
        printf("Number of units must be greater than 0. \n");
        return 1;
        
    }
    //Enter money 
    printf("Enter money amount: \n");
    scanf("%d", &a_ofmoney);  
    
    if(a_ofmoney < 0)
    {  
       printf("Invalid money amount.\n");
       printf("Money amount must be greater than or equal to 0. \n");
       return 1;
    }  

//===========The enf of input=======
//=======Out Put================
    int i;
    for( i = 1; i<= n_units; i++)
    {
    
    total_cost += (item_price * i);

    }

    if (total_cost <= a_ofmoney)
    {
        printf("Has enough money");
        
    }

    if (total_cost > a_ofmoney)
    {
        dolor_needs = (total_cost - a_ofmoney);
        printf("Needs %d dolar(s) to complete the purchus.\n", dolor_needs);
    
    }    
 //===========The end of Out put=========
 
return 0;
}