#include "inverter.h"
#include <string.h>
#include <stdlib.h>

int update_database(hash_t *arr,Slist *head)
{
    char backup_file[30];

    printf("Enter backup file name : ");
    scanf("%s",backup_file);

     //Check .txt extension 
    char *str=strstr(backup_file,".txt");
    if (str==NULL || strcmp(str,".txt")!=0)
    {
        printf(RED "ERROR :Invalid file extension\n" RESET);
        return 0;
    }

    FILE *fptr=fopen(backup_file,"r");
    if (fptr==NULL)
    {
        printf(RED "ERROR : Backup file not found\n" RESET);
        return 0;
    }

    char line[256];
    while (fscanf(fptr,"%s",line)!=EOF)
    {
        int len=strlen(line);

        // Validate format 
        if (line[0]!='#' || line[len - 1]!='#')
        {
            printf( RED "ERROR:⚠️File already exist\n" RESET);
            fclose(fptr);
            return 0;
        }

        // Remove last #
        line[len-1]='\0';

        //Skip first # 
        char *token=strtok(&line[1],";");

        // find Index 
        int index=atoi(token);

        //find File count 
        token=strtok(NULL,";");
        int file_count=atoi(token);

        // find Word 
        token=strtok(NULL,";");

        //cretae new node for mainnode
        main_t *new_main=malloc(sizeof(main_t));
        //Check the new_main is creted or not
        if (new_main==NULL)
            return 0;
        //if main node created update the all data
        new_main->file_count=file_count;
        strcpy(new_main->word,token);
        new_main->sublink=NULL;
        new_main->main_link=NULL;

        //Insert main node at hash index 
        new_main->main_link=arr[index].mainlink;
        arr[index].mainlink=new_main;

        Sub_node_t *prev_sub=NULL;
        //Create sub nodes 
        for (int i=0;i<file_count;i++)
        {
            // find Filename 
            char *fname=strtok(NULL,";");

            //find Word count
            token=strtok(NULL,";");
            int word_count=atoi(token);

            Sub_node_t *new_sub=malloc(sizeof(Sub_node_t));
            if (new_sub==NULL)
                return 0;
            new_sub->word_count=word_count;
            //copy the token into filename
            strcpy(new_sub->filename,fname);
            new_sub->link=NULL;
            if (new_main->sublink==NULL)
            {
                new_main->sublink=new_sub;
                prev_sub=new_sub;
            }
            else
            {
                prev_sub->link=new_sub;
                prev_sub=new_sub;
            }
        }
    }
    fclose(fptr);
    return 1;
}