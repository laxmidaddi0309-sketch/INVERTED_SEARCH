#ifndef INVERTER_H
#define INVERTER_H
#include<stdio.h>
#include "types.h"

#define RESET "\033[0m"

/* Regular Colors */
#define RED         "\033[31m"
#define GREEN       "\033[32m" 
#define BLUE        "\033[34m"
#define YELLOW      "\033[33m"

/* Underline */
#define UNDERLINE_WHITE     "\033[4;37m"


typedef struct node
{
    char file_name[50];
    struct node *link;
}Slist;
typedef struct subnode
{
    int word_count;
    char filename[50];
    struct subnode *link;
}Sub_node_t;
typedef struct mainnode
{
    int file_count;
    char word[50];
    Sub_node_t *sublink;
    struct mainnode *main_link;
}main_t;
typedef struct hash
{
    int ind;
    main_t *mainlink;
}hash_t;

Status validate_arg(char argv[],Slist **);
Status inverter_at_last(char argv[],Slist **head);
void print_list(Slist *head);
void create_database(hash_t *arr,Slist *head);
void print_database(hash_t *arr);
void display_database(hash_t *arr);
int save_database(hash_t *arr);
void search_database(hash_t *arr);
int file_present(hash_t arr[], char *filename);
int update_database(hash_t *arr,Slist *head);
#endif