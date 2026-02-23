#include "inverter.h"
#include<string.h>

int save_database(hash_t *arr)
{
    char save_file[25];
    printf("Enter the file name where you want to save : ");
    scanf(" %[^\n]", save_file);
    FILE *check=fopen(save_file,"r");
    if (check!=NULL)
    {
        printf(RED "ERROR:⚠️ %s already exists. Enter another file name\n" RESET,save_file);
        fclose(check);
        return 0;
    }
    char *substr=strstr(save_file,".txt");
    //check the file is contain .txt or not
    if (substr!=NULL)
    { 
        if ((strcmp(substr,".txt"))!=0)
        {
            printf("ERROR :%s invalid file name extension\n",save_file);
            return 0;
        }
        else
        {
            FILE *fptr=fopen(save_file,"w");
            if (fptr==NULL)
            {
                printf("ERROR :File is not opened\n");
                return 0;
            }
            //run the loop upto 27th index
            for (int index=0;index<27;index++)
            {
                if (arr[index].mainlink!=NULL)
                {
                    main_t *temp_main=arr[index].mainlink;

                    while (temp_main!=NULL)
                    {
                        //Print main node details 
                        fprintf(fptr,"#%d;%d;%s;",index,temp_main->file_count,temp_main->word);

                        //Print all sub nodes in same line 
                        Sub_node_t *temp_sub = temp_main->sublink;
                        while (temp_sub != NULL)
                        {
                            fprintf(fptr,"%d;%s;",temp_sub->word_count,temp_sub->filename);
                            temp_sub=temp_sub->link;
                        }

                        //End of one word entry 
                        fprintf(fptr,"#\n");

                        temp_main=temp_main->main_link;
                    }
                }
            }
            fclose(fptr);
            return 1;
        }
    }
    else
    {
        printf("ERROR : %s invalid file name extension\n", save_file);
        return 0;
    }
}