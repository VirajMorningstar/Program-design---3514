/*************************************************************
Author Name :-              Viraj Amarasinghe
* Date:-                    02/27/2022 
*Prject Name:-              project 4
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

=============
*Description: 
 This program calculats the amount of the computer that the company can build based on thier invetory.
 It takes the amount of parts and part types then take the list of the part to calculate 
 how many computers can be build.

============   
*/
//********************Program begin here**********************
# include <stdio.h>
int find_minimum(int *a, int n);
int main()
{
/*=================Input==============================================*/  
 int i, n, k;
    printf("Enter number of parts (N) \n"); // 
    scanf("%d", &n);
    int a[n];
      if(1>n ||n > 1000000) // input validation
         {
            printf("Invalid number of parts %d \n" ,n);
            printf("Must be in the range [1,1000000] \n");
            return 1;
         }
    printf("Enter number of part types (K):\n");
      scanf("%d",&k);
    
    if(1>k || k>10000)// input validation
      {
         printf("Invalid number of part types %d \n" ,n);
         printf("Must be in the range [1,10000]\n");
         return 1;
      }

    printf("Enter part List: \n");// Store part list
      for(i=0;i<n; i++)
         {
            scanf("%d", &a[i]);

            if(a[i] <1 || a[i]>k)
               {
                  printf("Invalid Part");
                  printf("Part must be in a range [1,%d]\n", k);
                  return 1; 
               }
                  

         }

   int count[k];// Counting array************
      for(i=0; i<k; i++)
         {
            count [i] = 0;

         }
      for(i=0; i<n; i++)
         {
            count [a[i] - 1]++ ;
         }
      
      for(i=0; i<k; i++)
      {
         if (count[i] < 1 )// input validation
            {
               printf("Invalid list of parts: \n");
               printf("You can Build 0 computers. \n");
               return 1;
            }
         if(count[i]> 1000)
            { 
               printf("Invalid list of parts. \n");
               printf("Part codes must be in the range. \n");
               return 1;
            }
      }
// priting out put message**********************************************************

      printf("The Factory can Build %d Computer(s). \n", find_minimum(count, k));
    

    return 0;
}// End of the main function***********************************

//A function to do pointer arithmetic 
int find_minimum(int *a, int n)


   {
      int minimum = *a;
      int *p; 

      for(p=a+1; p<a+n;p++)
       {
          if(*p<minimum)
          minimum = *p;
          
       }
      return minimum;
   }
//================End of the Program============================




