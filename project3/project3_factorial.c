/*************************************************************
*   Author Name :-             Viraj Amarasinghe
*   Date:-                     02/06/2022 
*   Prject Name:-              project 3
*   Class :-                   COP3514 Progrm Design
*   Computer Engeineeering:    University of South Florida. 
=============
*   Description: 
        This Programe calculats and displays the factorial of each element in an integer array. 
        The user will enter the array length and the elements of the array. 
============   
*/
//********************Program begin here**********************
#include <stdio.h>
void calculate_fact(int a[], int n, int b[]);
int fact(int n);

//========== Main Function============
int main(void)

{/******Input****************/   
    int n;
    printf("Enter the length of the Array: \n");
    scanf("%d",&n);
    int a[n]; //set the length of the array
    int b[n];
    int i;

    printf("Enter the Elements of the array. \n");
    for(i=0; i<n;i++)
        {
            scanf("%d", &a[i]);        
        }       

    calculate_fact(a, n, b); // priting the out put into the new array b[n]
        printf("Out Put:");
        for (i = 0; i < n; i++)
            printf(" %d", b[i]);
            printf("\n");
    return 0;
}
void calculate_fact(int a[], int n, int b []) // void function
{   int i;
    for(i=0; i<n;i++)
        {
            b[i] = fact (a[i]);//Call function fact again it self
        }    

}
int fact(int n) // Calculate the factorial of an element of a number
    {
        if (n<= 1) 
        return 1;
        else
        return n * fact(n - 1);
    }
/**********The End of the Functiomn**********************/