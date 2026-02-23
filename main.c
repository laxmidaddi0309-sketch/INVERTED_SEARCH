#include<stdio.h>
#include "inverter.h"
#include "types.h"
int main(int argc,char* argv[])
{
    if(argc==1)
    {
        printf("ERROR :There is no command line arguments\n");
        return 0;
    }
    Slist *head=NULL;
    for(int i=1;i<argc;i++)
    {
        //validate the argv
        if(validate_arg(argv[i],&head)==SUCCESS)
        {
            //afetr validation completed insert the argv in Single linked list
            if(inverter_at_last(argv[i],&head)==SUCCESS)
            {
            }
        }
    }
    //printing sinle linked list
    print_list(head);
    hash_t arr[27];
    for(int i=0;i<27;i++)
    {
        arr[i].ind=i;
        arr[i].mainlink=NULL;
    }
    
     int choose,flag=0,flag1=0;
    while(choose)
    {
        printf("-------------------------------------------------\n");
        printf(BLUE "     ##### INVERTED SEARCH MENU ####\n" RESET);
        printf("-------------------------------------------------\n");
        printf("1.➕ create database\n2.👁️  Display databse\n3.💾 save database\n4.🔎 Search database\n5.🔁 update database\n6.🔚 Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter the option:");
        scanf("%d",&choose);
        printf("\n");
        switch(choose)
        {
            case 1:
                if(flag==0 && flag1==0)
                {
                    //call the create Database function
                    create_database(arr,head);
                    flag=1;
                    printf(GREEN "Create Database Successfully completed\n\n" RESET);
                }
                else
                {
                    printf(RED "ERROR: Create DATAbase already completed\n" RESET);
                    printf(RED "We cannot Create the Database\n\n" RESET);
                }
                break;
            case 2:
                if(flag==1 || flag1==1)
                {
                    //Call the Display function
                    display_database(arr);
                }
                else
                {
                    printf(RED "ERROR :No Database EXists ❌\n" RESET);
                    printf(RED "First you have to create/Update the Database\n\n" RESET);
                }
                break;
            case 3:
                if(flag==1 || flag1==1)
                {
                    //call the save function
                    if(save_database(arr))
                    printf(GREEN "Saved Database Successfully Completed\n\n" RESET);
                }
                else{
                    printf(RED "NO Database Exists We cannot save the data\n" RESET);
                    printf(RED "First you have to create/Update the Database\n\n" RESET);
                }
                break;
            case 4:
                if(flag==1 || flag1==1)
                {
                    search_database(arr);
                }
                else{
                    printf(RED "No Database exists We cannot search the data\n" RESET);
                    printf(RED "First you have to create/Update the Database\n\n" RESET);
                }
                break;
            case 5:
                if(flag==0 && flag1==0)
                {
                    if(update_database(arr,head))
                    {
                        create_database(arr,head);
                        printf(GREEN "Update Database completed\n\n" RESET);
                        flag1=1;
                    }
                }
                else{
                    printf(RED "ERROR:Create Database already completed\n" RESET);
                    printf(RED "We cannot Update the Database\n\n" RESET);
                }
                break;
            case 6:
                return 0;
                break;
            default :
                break;
        }
        printf(YELLOW "DO you want to continue yes(1)/NO(0)" RESET);
        scanf("%d",&choose);
    } 
}