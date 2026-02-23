#include<stdio.h>
#include "inverter.h"

void display_database(hash_t *arr)
{
     printf("IND  FILE_COUNT  WORD  WORD_COUNT  FILE_NAME\n");
    printf("------------------------------------------------------------\n");
    for(int i=0;i<27;i++)
    {
        if(arr[i].mainlink!=NULL)
        {
            main_t *main_node_temp=arr[i].mainlink;
            while(main_node_temp!=NULL)
            {
                Sub_node_t *sub_node_temp=main_node_temp->sublink;
                while(sub_node_temp!=NULL)
                {
                  printf("%02d   %-11d %-10s %-11d %-10s\n",i,main_node_temp->file_count,main_node_temp->word,sub_node_temp->word_count,sub_node_temp->filename);
                    sub_node_temp=sub_node_temp->link;
                } 
                main_node_temp=main_node_temp->main_link;
            }
        }
    }
     printf("------------------------------------------------------------\n");
}