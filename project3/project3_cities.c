/*************************************************************
Author Name :-            Viraj Amarasinghe
* Date:-                    02/06/2022 
*Prject Name:-              project 3
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

=============
*Description: 
   This Programe calcuates the cities that a drone can visit based on given list of drones and locations.
   The profgrame take the number of the cities, the number of drones and the list of drones with the current location
   and the distance. The program will give out put of the cities that a drone can visit. 
============   
*/
//********************Program begin here**********************

#include <stdio.h>
#include <ctype.h>
int main(void)
{
   int C, i, D, M,N =0;  
   /*
      C = Current city
      D = travaling Distance
      M = Number of Drones
      N = Number of Cities
      i = Array index
   */
   
//====Input========
    
    printf("Enter Number of Cities: \n"); //user input - Number of cities which determin the size of array. 
   
    scanf("%d", &N); 
    int a[N]; // Declare the array length

     if(N < 1 || N > 100) // Limit for the input N
       if(N==0)  
         {
            printf("Invalid number of cities. %d. \n", N);
            printf("Must be in the range [1,100]");
            return 1;
         }
   

// get the number of drones

    printf("Enter the Number of Drones:- ");
    scanf("%d", &M); // M = number of drones

    if(M < 1 || M > 100) // Parameters for the input M
            {
                printf("Invalid number of drones %d. \n", M);
                printf("Must be in the range [1,100]");
                return 1;
            }
        
// List of the drones======

   printf("Enter Drone List: \n");
   int j;
   
   for(j=0;j<M;j++)
      {
         scanf("%d %d", &C,&D);      
  
         if(C<1 || C>N || D<1||D>N) // Parameters for the input C and D
            {
               printf("Invalid list of drones. \n");
               printf("Drone location and travel distance must be in the range [1,%d\n",N);
               return 1;
            }
         int smallest_city = C %D; // Storing values into the array. C is the value of array index which is the current location of the array. 
         int k;
         for(k = smallest_city; k< N+1; ) // This taks the input C and move it to the smallest array index it can go and start calculation from there. 
            {
               a[k-1] = k;
               k+= D;
               
            }

      }
//====Print the bprograme Out Put=======
   
      printf("cities Reached by a drone: \n");
         for(i=0; i < N;i++)
            {
               if (1<= a[i] && a[i] <=100)
            
                  printf("%d ",a[i]);
            }
   return 0;
}

//***********End of the program***********************