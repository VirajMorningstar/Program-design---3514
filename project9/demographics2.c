/*************************************************************
Author Name :-              Viraj Amarasinghe
* Date:-                    04/17/2022 
*Prject Name:-              project 9 - part 2
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

======================================================================
*Description: 
The program sort the states by percentage of population whose ages are equal or greater than 65 
years old. For that it takes a csv file name as an input and sort it in gretast to smallest. 

in this function we have use Qsort function with the quick sort library function to sort out.

======================================================================   
*/



//********************Program begin here**********************
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 100


struct state
    {
        char state[MAX +1];
        int populataion_2020;
        int population_2010;
        double pop_5_under;
        double pop_18_under;
        double pop_65_above;
    };

int struct_comp(const void*A, const void *B);// Qsort function to sort states by percentage of population whose ages are equal or greater than 65 years old.
void decending_array( struct state list[], int n); //a function to print the array in the desending order. 

int main()
{
    //structs array
    struct state state_list[100]; 
    char file_name[50];
    char sorted[50] = "sorted_";
    FILE *txt_file;
    FILE *output_file;
    int i, n;

    printf("Enter the file name: ");
    scanf("%s", file_name);
    strcat(sorted, file_name);

    txt_file = fopen(file_name, "r");
    if (txt_file == NULL) {
        printf("Error opening file named %s\n", file_name);
        return 1;
    } // end if

    output_file = fopen(sorted, "w");
    if (output_file == NULL) {
        printf("Error opening file named %s\n", sorted);
        return 1;
    } // end if
/*====================================================================*/
    i = 0;
    while (!feof(txt_file) && !ferror(txt_file)) 
        {
            if (fscanf(txt_file, "%[^,], %d, %d, %lf, %lf, %lf\n", 
            state_list[i].state, &state_list[i].populataion_2020, &state_list[i].population_2010, 
            &state_list[i].pop_5_under, &state_list[i].pop_18_under, &state_list[i].pop_65_above) == 6) 
                {
                    i += 1;
                } 
        } 

    qsort(state_list, i, sizeof(struct state),struct_comp);   

    //sort_states(state_list, i);
    
    decending_array(state_list, i);
    for (n = 0; n < i; n++) 
        {
            fprintf(output_file, "%s, %d, %d, %.1lf, %.1lf, %.1lf\n", state_list[n].state, state_list[n].populataion_2020, state_list[n].population_2010, 
            state_list[n].pop_5_under, state_list[n].pop_18_under, state_list[n].pop_65_above);
        }
    fclose(txt_file);
    fclose(output_file);
    
    return 0;

}
// end of the main function

void decending_array( struct state list[], int n)
    {

        int i, j;
        struct state temp;
        for (i = 0, j = n - 1; i < j; i++, j--) {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        } // end for
        return;
    } 
    //End of the decending array 

    int struct_comp(const void*A, const void *B)//Qsort function
    {
        const struct state *p = A;
        const struct state *q = B;
        if(p-> pop_65_above < q-> pop_65_above)
            {
            return -1;
            }
        else if(p-> pop_65_above ==q-> pop_65_above)
            {
                return 0;
            }

        return 1;


    }

/*==============================End of the program========================*/    