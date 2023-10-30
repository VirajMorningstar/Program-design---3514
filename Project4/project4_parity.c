/*************************************************************
Author Name :-            Viraj Amarasinghe
* Date:-                    02/27/2022 
*Prject Name:-              project 4
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

=============
/* Description: 
   This Programe determin whether the arrays are good or not based parity. Meanng the programe will take 
   input and declare an array the it compares compare each elements to see whether thay are either odd or even.
   If all the elements odd or even it printed good All elements Odd or Even. Else it printed not good. 
============    
*/
//********************Program begin here**********************

# include <stdio.h>
void find_parity(int *a, int n, int *all_even, int *all_odd);
int main()
{//Main function begins========INPUT=====================

    int n, all_even = 0, all_odd = 0; //declaring array length as n
    printf("Enter the length of the input array: \n");
    scanf("%d,\n", &n);
    int a[n]; 

//Stoting Array elements=================================

    printf("Enter the array elements: \n");
    int i;
    for(i=0;i<n;i++)
    scanf("%d, \n",&a[i]);

//Out Put=================================================

    find_parity(a, n, &all_even, &all_odd );  //Fuction call        

        if(all_odd == 1 && all_even ==0) 
            {
                printf("Out Put: Good, All Elements are Odd \n");
            }
        else if(all_even ==1 && all_odd == 0)

            {
                printf("Out Put:Good, All Elements are Even, \n");
            }
        else 
            {
                printf("Out Put: Not Good \n");
            }
        
    return 0;
}
//Void function doing the logical calculation=======================================

void find_parity(int *a, int n, int *all_even, int *all_odd) //Function Call 

{
  int i;
   for(i=0; i<n;i++)

   // Checking for all even and odd  elemts and store them sepratly=================

        if((a[i]) % 2 == 0)
            {
                *all_even = 1;
            }  
        else 
            {
                *all_odd = 1;

            }
            
}
/*****************==End of the Program===********************************************/