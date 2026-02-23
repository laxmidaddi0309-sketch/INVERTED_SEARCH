#include "inverter.h"
#include<string.h>
void search_database(hash_t *arr)
{
    char wordsearch[25];
    int found=0;
    printf("Enter the word : ");
    scanf(" %s",wordsearch);
    printf("---------------------------------------------------\n");
    for(int index = 0; index < 27; index++)
    {
        if(arr[index].mainlink!=NULL)
        {
            main_t *temp_main=arr[index].mainlink;
            while(temp_main != NULL)
            {
                //compare the entered word and temp of word or matched or not
                if(strcmp(temp_main->word,wordsearch) == 0)
                {
                    found=1;
                    printf(BLUE "Word " RESET UNDERLINE_WHITE "%s " RESET BLUE " present in " RESET UNDERLINE_WHITE "%d " RESET BLUE " files\n" RESET,temp_main->word,temp_main->file_count);
                    Sub_node_t *temp_sub=temp_main->sublink;
                    while(temp_sub != NULL)
                    {
                        printf(BLUE "In " RESET UNDERLINE_WHITE "%s " RESET BLUE ",the word present  "  RESET UNDERLINE_WHITE "%d " RESET BLUE "times\n" RESET,temp_sub->filename,temp_sub->word_count);
                        //updating the subnode
                        temp_sub = temp_sub->link;
                    }
                }
                //updating the main node
                temp_main = temp_main->main_link;
            }
        }
    }
    if(found==0)
    {
        printf(RED "ERROR :word %s is not found in database\n" RESET,wordsearch);
    }
    printf("---------------------------------------------------\n\n");
}