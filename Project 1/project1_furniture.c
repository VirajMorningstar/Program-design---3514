/*Author Name :- Viraj Amarasinghe
Prject Name:- project1_furniture
Class :- COP3514 Progrm Design
Date:- 01/23/2022
Computer Engeineeering - University of South Florida. 
This programe calculate the monthly ental cost of furnitures
*/

#include <stdio.h> 
int main()

    //decalring variables. 
    {
    
    int fmcost =0;
    int monthly_cost = 0;
    int yearlly_cost = 0;
    int amount =0;
    int amount_ofyears=0;
    int final_year =0;
    int selected_item;

    /* The menue of the furnture to be selected*/
    
    printf("Please Select from the following menu: ");
    printf("1 Sofa, 2 Loveseat, 3 4 Post bed, 4 Dresser, 5 kitchen Table. \n");
    scanf("%d", &selected_item);

    //==============================================
    //if the user select an item not in the menue, follwing function will work. 

    if( selected_item <1) //if less than 1 
    {
        printf("Please enter a number in range of 1 to 5.\n");
        return 0;
    }
    // if user select a number bigger than 5
    if(selected_item >5)
    {
        printf("Invalid input. The input should be in the range of 1 to 5.\n");
        return 0;
    }
    //========================================

    //Let the user to enter months rentad
    int months_rented;
    printf("Enter months rented:");
    scanf("%d", &months_rented);

    if (months_rented<1)
    {
        printf("Invalid input. Enter a positive number for months rented. \n");
        return 0;

    }
    //===================================================
    // calculat the cost
    switch (selected_item)
    {
        case 1: fmcost = 60;
                monthly_cost = 45;
                yearlly_cost = 450;
                break;
        case 2: fmcost = 45;
                monthly_cost = 30;
                yearlly_cost = 280;
                break;
        case 3: fmcost = 55;
                monthly_cost = 38;
                yearlly_cost = 350;
                break;
        case 4: fmcost = 28;
                monthly_cost = 25;
                yearlly_cost = 200;
                break;
        case 5: fmcost = 35;
                monthly_cost = 20;
                yearlly_cost = 220;
                break;
                  
    }
    //calculate the cost for the first 12 months. 
       
    amount = fmcost + (months_rented - 1)*monthly_cost;
    amount_ofyears= months_rented/12;
        
        
     if (amount > yearlly_cost)
    {
        amount = yearlly_cost; 
        
    }
        

    if (months_rented>12)
    {
        
        final_year = ((months_rented % 12) *monthly_cost);

        if (final_year > yearlly_cost)
        {
            final_year=yearlly_cost;
        }

        amount = (amount_ofyears * yearlly_cost) + final_year;
        
    }
    printf("Amount due is $ %d \n ", amount);

    return 0;
}