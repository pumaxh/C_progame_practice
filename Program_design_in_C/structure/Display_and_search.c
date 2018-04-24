/*
 * Displays all products in the database that satisfy the search
 * parameters specified by the program user.
 */

#include <stdio.h>
#include <string.h>

#define MIN_STOCK  1111     /* minimum stock number */
#define MAX_STOCK  9999     /* maximum stock number */
#define MAX_PRICE  1000.00  /* maximum product price */
#define STR_SIZ    80       /* number of characters in a string */

typedef struct {
    int     stock_num;
    char    category[STR_SIZ];
    char    tech_descript[STR_SIZ];
    double  price;
} product_t;

typedef struct {
    int     low_stock, high_stock;
    char    low_category[STR_SIZ], high_category[STR_SIZ];
    char    low_tech_descript[STR_SIZ], high_tech_descript[STR_SIZ];
    double  low_price, high_price;
} search_params_t;

void get_params(search_params_t *params);
char menu_choose(search_params_t params);

/* Insert prototypes of functions needed by get_params and display_match */
int main()
{
#if 0
    char            inv_filename[STR_SIZ]; /* name of inventor file */
    FILE            *inventoryp;           /* inventory file pointer */
#endif
    search_params_t params;                /* search parameter bounds */
#if 0
    /* Get name of inventory file and open it */
    printf("Enter name of inventory file> ");
    scanf("%s", inv_filename);
    inventoryp = fopen(inv_filename, "rb");
#endif
    /* Get the search parameters */
    get_params(&params);
#if 0
    /* Display all products that satisfy the search parameters */
    display_match(inventoryp, params);
#endif
    return 0;
}

/* prompts the user to enter the search parameters */

void get_params(search_params_t *params)
{
    char choice;

    params->low_stock = MIN_STOCK;
    params->high_stock = MAX_STOCK;
    params->low_price = 0.0;
    params->high_price = MAX_PRICE;
    snprintf(params->low_category, STR_SIZ, "aaaa");
    snprintf(params->high_category, STR_SIZ, "zzzz");
    snprintf(params->low_tech_descript, STR_SIZ, "aaaa");
    snprintf(params->high_tech_descript, STR_SIZ, "zzzz");
    
    do{
        choice = menu_choose(*params);
        switch (choice)
        {
            case 'a':
                scanf("%d", &params->low_stock);
                break;
            case 'b':
                scanf("%d", &params->high_stock);
                break;
            case 'c':
                scanf("%s", params->low_category);
                break;
            case 'd':
                scanf("%s", params->high_category);
                break;
            case 'e':
                scanf("%s", params->low_tech_descript);
                break;
            case 'f':
                scanf("%s", params->high_tech_descript);
                break;
            case 'g':
                scanf("%lf", &params->low_price);
                break;
            case 'h':
                scanf("%lf", &params->high_price);
                break;
            case 'q':
                break;
            default:
                printf("Error input string, exit.");
                choice = 'q';
        }
    }while(choice != 'q');
    return;
}

/*
  * Displays records of all products in the inventory that satisfy search
  * parameters.
  * Pre: databasep accesses a binary file of product_t records that has
  * been opened as an input file, and params is defined
  */
char menu_choose(search_params_t params)
{
    char choice;

    printf("Select by letter a search parameter to set or enter ");
    printf("\"q\" to quit\naccept parameters shown.\n");
    printf("    Search parameter                          Current value\n\n");
    printf("[a] Low bound for stock number                %4d\n",
            params.low_stock);
    printf("[b] High bound for stock number               %4d\n",
            params.high_stock);
    printf("[c] Low bound for category                    %s\n",
            params.low_category);
    printf("[d] High bound for category                   %s\n",
            params.high_category);
    printf("[e] Low bound for technical description       %s\n",
            params.low_tech_descript);
    printf("[f] High bound for technical description      %s\n",
            params.high_tech_descript);
    printf("[g] Low bound for price                       $%7.2f\n",
            params.low_price);
    printf("[h] High bound for price                      $%7.2f\n\n",
            params.high_price);

    printf("Selection> ");
    scanf(" %c", &choice);

    return choice;
}

/* Determines whether record prod satisfies all search parameters */
int match(product_t prod, search_params_t params)
{
    return (strcmp(params.low_category, prod.category) <= 0             &&
            strcmp(prod.category, params.high_category) <= 0            &&
            strcmp(params.low_tech_descript, prod.tech_descript) <= 0   &&
            strcmp(prod.tech_descript, params.high_tech_descript) <= 0  &&
            params.low_price <= prod.price                              &&
            prod.price <= params.high_price);
}

/*
  * *** STUB ***
  * Displays each field of prod. Leaves a blank line after the product
  * display.
  */
 void show(product_t prod)
{
    return;
}

/*
  * Displays records of all products in the inventory that satisfy search
  * parameters.
  * Pre: databasep accesses a binary file of product_t records that has
  * been opened as an input file, and params is defined
  */
void display_match(FILE *databasep, search_params_t params)
{
    product_t next_prod;
    int       no_matches = 1;
    int       status;

    /* Advances to first record with a stock number greater than or equal to lower bound. */
    printf("\nProducts satisfying the search parameters:\n");
    while(   next_prod.stock_num <= params.high_stock
          && status == 1)
    {
        if(match(next_prod, params))
        {
            no_matches = 0;
            show(next_prod);
        }
        status = fread(&next_prod, sizeof(product_t), 1, databasep);
    }
    /* Displays a message if no products found */
    if(no_matches)
    {
        printf("No products available\n");
    }
}

