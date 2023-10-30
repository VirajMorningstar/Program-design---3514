/*************************************************************
Author Name :-              Viraj Amarasinghe
* Date:-                    03/27/2022 
*Prject Name:-              project 6
*Class :-                   COP3514 Progrm Design
*Computer Engeineeering:    University of South Florida. 

======================================================================
*Description: 
The program sort the states by percentage of population whose ages are equal or greater than 65 
years old. For that it takes a csv file name as an input and sort it in gretast to smallest. 

======================================================================   
*/


//********************Program begin here**********************
#include<stdio.h>
#include<string.h>
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

void sort_states(struct state list[], int n);// selection sort function to sort states by percentage of population whose ages are equal or greater than 65 years old.
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

    sort_states(state_list, i);
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

void sort_states(struct state a[], int n) 
{
   int i;
    struct state temp;

    while (n > 0) {
        struct state *max = a;
        for (i = 0; i < n; i++) 
            { //a loop to  find maximum value
                if (a[i].pop_65_above > (*max).pop_65_above) {
                max = a + i;
            }
            }
                temp = a[n - 1];
                a[n - 1] =  *max;
                *max = temp;
                n--; 
            }

}// end of the sort_states

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

/*==============================End of the program========================*/    