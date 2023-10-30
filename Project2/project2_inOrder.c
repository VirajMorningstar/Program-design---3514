/*Author Name :- Viraj Amarasinghe
Prject Name:- project2_
Class :- COP3514 Progrm Design
Computer Engeineeering - University of South Florida. 
Description: This programe determins if the input is in order. This will check the letters in the inpiut and check 
whether they  are in alphabetic order. THe prgram convert upper cases to lower case and then the compare nabhoring 
character and detemin the order. Once it is done it will sat whether it is in order or not. 
*/
#include <stdio.h>
int main()
{
    //in put=========================
    
    char ch,ch1;
    ch = 0;
    ch1 = 1;
   
    printf("Enter input:");
//Out Put============================

    while((ch=getchar())!='\n') // take the user input and the new line is not equal to characters. 
    {
         //converts to lower case using ASCII values!
        if(ch >= 65 && ch <= 90) //if characters are upper case!
        
            {
                ch += 32;
            }
        if (ch< 97 || ch>122) //If any other numbers are entered. 
            {
                printf("Not In order");
                return 1;
            }
            
       
       
            
                
        if (ch < ch1)
            {   
                printf("Not in order");
                return 1;
            }   
         
        ch1=ch;        
    }

printf("in order");
  
 return 0;   
}