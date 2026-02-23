#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "inverter.h"
#include<ctype.h>
#include "types.h"
Status validate_arg(char argv[],Slist **head)
{
    //check the argv is NULL or not
    if(argv==NULL)
    return FAILURE;
    // if not check the .txt file or not
    char *str=strstr(argv,".txt");
    if(str!=NULL)
    {
        //if yes compre the substring with .txt
        if(strcmp(str,".txt")!=0)
        {
            return FAILURE;
        }
        else
        {
            FILE* fptr=fopen(argv,"r");
            if(fptr==NULL)
            {
                printf(RED "ERROR:%s file not exits\n" RESET,argv);
                return FAILURE;
            }
            else
            {
                //Set the offset to end of the file
                fseek(fptr,0,SEEK_END);
                long size=ftell(fptr);
                //check the file is contain any data or not
                if(size==0)
                {
                    printf(RED "ERROR:%s FILE is not contain any content\n" RESET,argv);
                    return FAILURE;
                }
                //if contain the data compare the argv and file name
                else
                {
                    if(*head==NULL)
                    return SUCCESS;
                    Slist *temp=*head;
                    while(temp!=NULL)
                    {
                        if(strcmp(argv,temp->file_name)==0)
                        return FAILURE;
                        temp=temp->link;
                    }
                    return SUCCESS;
                }
            }
        }
    }
    else{
        printf(RED "ERROR:%s File name is not .txt\n\n" RESET,argv);
        return FAILURE;
    }


}
Status inverter_at_last(char argv[],Slist **head)
{
    //create the new node
    Slist *new=malloc(sizeof(Slist));
    if(new==NULL)
        return FAILURE;
    //copy the argv into filename
    strcpy(new->file_name,argv);
    new->link=NULL;
    //if list is empty insert the data and update the head
    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    //if list not empty 
    Slist *temp=*head;
    //traverse upto NULL
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    //update the temp with next node
    temp->link=new;
    return SUCCESS;
}
void print_list(Slist *head)
{
	if (head==NULL)
	{
		printf(BLUE "INFO:List is empty\n" RESET);
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ",head ->file_name);
		    head=head->link;
	    }
	    printf("NULL\n");
        printf(GREEN "All .txt Files Saved Successfully in Single Linked List\n\n" RESET);
    }
}
int file_present(hash_t arr[],char *filename)
{
    for(int i=0;i<27;i++)
    {
        main_t *temp_main=arr[i].mainlink;

        while(temp_main!=NULL)
        {
            Sub_node_t *temp_sub=temp_main->sublink;

            while(temp_sub!=NULL)
            {
                if(strcmp(temp_sub->filename,filename)==0)
                {
                    return 1;
                }
                temp_sub=temp_sub->link;
            }

            temp_main=temp_main->main_link;
        }
    }
    return 0;
}