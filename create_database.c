#include"inverter.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main_t *create_mainnode(char *word)
{
    //create the main new node
        main_t *new=malloc(sizeof(main_t));
        if(new==NULL)
        return 0;
        //update the new file data
        new->file_count=1;
        strcpy(new->word,word);
        new->sublink=NULL;
        new->main_link=NULL;
    return new;
}
Sub_node_t *create_subnode(char *file_name)
{
    //create the sub new node
    Sub_node_t *new=malloc(sizeof(Sub_node_t));
    if(new==NULL)
    return 0;
    //update the new data
    new->word_count=1;
    strcpy(new->filename,file_name);
    new->link=NULL;
    return new;
}
void create_database(hash_t *arr,Slist *head)
{
    char word[50];
    Slist *temp=head;
    while(temp!=NULL)
    {
        //check the file is present or not
        if(file_present(arr,temp->file_name))
        {
            printf(BLUE "File %s already present\n" RESET,temp->file_name);
            temp=temp->link;
            continue;
        }
        //if file is present open the file in read mode
        FILE *fptr=fopen(temp->file_name,"r");
        if(fptr==NULL)
        {
            printf(RED "ERROR:File open fails" RESET);
            temp=temp->link;
            continue;
        }
        //read the signle word from file upto end of file
        while(fscanf(fptr,"%s",word)!=EOF)
        {
            int ind;
            //check the lower letter or not
            //if lower letter subtract with 'a' 
            if(word[0]>='a' && word[0]<='z')
            {
                 ind=word[0]-'a';
            }
            //check the Upper letter or not
            //if upper letter subtract with 'A'
            else if(word[0]>='A' && word[0]<='Z')
            {
                ind=word[0]-'A';
            }
            //expect lower and upper letter store the 26th index
            else
            {
                ind=26;
            }
            main_t *maintemp=arr[ind].mainlink;
            main_t *prev=NULL;
            //traverse the main node upto NULL
            while(maintemp!=NULL)
            {
                if(strcmp(maintemp->word,word)==0)
                break;
                prev=maintemp;
                maintemp=maintemp->main_link;
            }
            if(maintemp==NULL)
            {
                 maintemp=create_mainnode(word);
                 Sub_node_t *sub_node=create_subnode(temp->file_name);
                 maintemp->sublink=sub_node;
                 if(prev==NULL)
                 {
                    arr[ind].mainlink=maintemp;
                 }
                 else
                 prev->main_link=maintemp;
            }
            else
            {
                Sub_node_t *subtemp=maintemp->sublink;
                Sub_node_t *subprev=NULL;
                //traverse the subnode upto NULL
                while(subtemp!=NULL)
                {
                    if(strcmp(subtemp->filename,temp->file_name)==0)
                    break;
                    subprev=subtemp;
                    subtemp=subtemp->link;
                }
                if(subtemp==NULL)
                {
                    Sub_node_t *newsub=create_subnode(temp->file_name);
                    if(subprev==NULL)
                    maintemp->sublink=newsub;
                    else
                    subprev->link=newsub;
                    maintemp->file_count++;
                }
                else{
                    subtemp->word_count++;
                }
            }
        }
        fclose(fptr);
        temp=temp->link;
    }
}