/*************************************************************
Author Name :-              Viraj Amarasinghe
* Date:-                    03/27/2022 
*Prject Name:-              project 6
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

======================================================================
*Description: 
The program compute a suffix with at amount of characters which is M ≥ 20) for each file.
the programe start from a zero suffix and add the next word to it.  if two words length more than 20 it resets 
the fist to zero and add the next to it. 


======================================================================   
*/


//********************Program begin here**********************
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int M;
    char output_str[1000];
    char read_str[1000];
    FILE *input_file;

    printf("Enter the Vlue of M: \n");
    scanf("%d", &M);

/*READING EACH FILE */

int i;
for(i =1; i <argc; i++)
{
    // If there is an eror of opening the file it reaches a NULL and termnate with a message. 
    input_file = fopen(argv[i], "r");
    if(input_file == NULL) 
    {
        printf("Error Opening File Named %s\n", argv[i]);

        return 1;
        
    }

    strcpy(output_str, "");
    while(!feof(input_file) && !ferror(input_file))
    {
        if(fscanf(input_file, "%s\n", read_str) == 1)
            {
                if((strlen(output_str)+strlen(read_str))<= M)
                {
                    strcat(output_str,read_str);
                }
                else
                {
                    strcat(output_str,read_str);
                    strcpy(output_str,read_str);
            }

            }// end of the if statments 

        else
            {
              printf("I think something went wrong, but I am not sure how");  
            }    
    }// End of the while loop

    printf("%s: %s\n", argv[i], output_str);
    fclose(input_file);
}// For loop end here

return 0;

}
/*End of the Program. Thank you for reading.*/