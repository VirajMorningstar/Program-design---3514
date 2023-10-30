#include "tshirt.h"
#include "readline.h"


//////////////////////////
// function definitions //
//////////////////////////
/*======================================================================================*/
void help() 
{
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}
/*======================================================================================*/
struct tshirt * add_to_inventory(struct tshirt *inventory) 

{
	struct tshirt * student_org = (struct tshirt*)malloc(sizeof(struct tshirt));
	printf("Enter student organization name\n");
    read_line(student_org->org_name,ORG_NAME_LEN+1);
    printf("Enter tshirt size \n");
    read_line(student_org->size,ORG_NAME_LEN+1);

	if(inventory==NULL)
        {
            inventory = student_org;
            student_org->next = NULL;

            printf("Enter price \n ");
            scanf("%lf",&student_org->price);
            printf("Enter Quantity \n ");
            scanf("%d",&student_org->quantity);
            
            return inventory;
        }

        struct tshirt *temp = inventory;
        while(temp!=NULL)
        {
            if(strcmp(temp->org_name,student_org->org_name)==0 && strcmp(temp->size,student_org->size)==0)
            {
                printf(" this t-shirt already exists\n");
                free(student_org);
                return inventory;
            }
            temp = temp->next;
        }
        
        printf("Enter price \n ");
        scanf("%lf",&student_org->price);
        printf("Enter Quantity \n ");
        scanf("%d",&student_org->quantity);
// modification begin here - 
		student_org -> next = NULL;
		struct tshirt *cur, *prev;
        if(inventory==NULL)
            {
                return student_org;

            }
        
        for(cur=inventory, prev= NULL; cur!=NULL && strcmp(student_org-> org_name, cur->org_name)>0; prev=cur, cur=cur->next);
        if(cur ==NULL)
        {
            prev->next = student_org;
            return inventory;
        }

        for(;cur!=NULL && strcmp(student_org->size, cur->size)>=0 && strcmp(student_org-> org_name, cur->org_name)==0; prev=cur, cur=cur->next);


        student_org->next=cur;
        if(prev==NULL)
        {
            return student_org;
        }

        else
        {
            prev-> next=student_org;
            return inventory;

        }
//my modification ends

}
/*======================================================================================*/
void search_by_organization(struct tshirt *inventory) 
{
	struct tshirt *temp = inventory;
    char keyword[ORG_NAME_LEN+1];
    printf("\nEnter the organization name\n ");
    read_line(keyword,ORG_NAME_LEN+1);
	
	int flag = 0;

    while(temp!=NULL)
    {
        if(strcmp(temp->org_name, keyword)==0)
        {
           

            char student_organization[ORG_NAME_LEN+1];
            strcpy(student_organization,temp->org_name);

            char size[SIZE_LEN+1];
            strcpy(size,temp->size);

            double price = temp->price;
            int quantity = temp->quantity;

          if (flag==0)

          
          
			{
				printf("tshirt of organization : %s, exists.\n",keyword);
                printf("T-shirt details\n");
                printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| Student organization                               | Sz. | Price | Qty. |\n");
				printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
				
				flag++;
			}
			else 
				{
					{
						printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
					}
				}

		}
		
		

      	temp = temp->next;
    }

	if (flag == 0) 
			{
			printf("\n No. T-shirt not found\n");
			}
	else
		{
			printf("|----------------------------------------------------|-----|-------|------|\n");
		}
	

}
/*======================================================================================*/
void search_by_size(struct tshirt *inventory) 
{
	struct tshirt *temp = inventory;
    char keyword[SIZE_LEN+1];
    printf("\nEnter the tshirt size\n ");
    read_line(keyword,ORG_NAME_LEN+1);
	int flag = 0;
    while(temp!=NULL)
    {
        if(strcmp(temp->size, keyword)==0)
        {
            

            char student_organization[ORG_NAME_LEN+1];
            strcpy(student_organization,temp->org_name);

            char size[SIZE_LEN+1];
            strcpy(size,temp->size);

            double price = temp->price;
            int quantity = temp->quantity;

            if (flag==0)
			{
				printf("tshirt of size : %s, exists.\n",keyword);
                printf("\n T-shirt details\n");
                printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| Student organization                               | Sz. | Price | Qty. |\n");
				printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
				

				flag++;
			}
			else 
				{
					{
						printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
					}

				}

		}
		
		

      	temp = temp->next;
    }

	if (flag == 0) 
			{
			printf("\n T-shirt not found\n");
			}
	else
		{
			printf("|----------------------------------------------------|-----|-------|------|\n");
		}
 }
/*======================================================================================*/
void print_inventory(struct tshirt *inventory) 
{
	struct tshirt* temp = inventory;
	int flag = 0;
    while(temp!=NULL)
    {
        char student_organization[ORG_NAME_LEN+1];
        strcpy(student_organization,temp->org_name);

        char size[SIZE_LEN+1];
        strcpy(size,temp->size);

        double price = temp->price;
        int quantity = temp->quantity;
        temp = temp->next;
	
		if (flag == 0)
		{
			printf("|----------------------------------------------------|-----|-------|------|\n");
			printf("| Student organization                               | Sz. | Price | Qty. |\n");
			printf("|----------------------------------------------------|-----|-------|------|\n");
			printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
			

			flag=1;
		}
		else 
			{
				printf("| %-50s | %-3s | %5.2f | %4d |\n", student_organization, size, price, quantity);
			 }
	}

	if (flag == 0) 
			{
			printf("\n T-shirt not found\n");
			}
		else{printf("|----------------------------------------------------|-----|-------|------|\n");}
	
	
}
/*======================================================================================*/
void clear_inventory(struct tshirt *inventory) 
{

	struct tshirt *temp = inventory;
    while(temp!=NULL)
    {
        struct tshirt *toFree = temp;
        temp = temp->next;
        free(toFree);
    }

}