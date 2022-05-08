#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// game db struct

struct Game_DB
{
    int id;
    char name[64];
    int year;
    char developer[64];
    char publisher[64];
    int awards;
} x[100], pom;

char grid[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// sort funcs
void sort_asc_name();
void sort_asc_year();
void sort_asc_dev();
void sort_asc_pub();
void sort_asc_awards();
void sort_des_name();
void sort_des_year();
void sort_des_dev();
void sort_des_pub();
void sort_des_awards();

// search funcs
void search_year();
void search_dev();
void search_pub();

// ttt func
void board_en();
void board_hr();
int check();

// guessing funcs
void guess_easy_en();
void guess_medium_en();
void guess_hard_en();
void guess_easy_hr();
void guess_medium_hr();
void guess_hard_hr();

// main function
int main()
{
    // files
    FILE *database;
    if (database == NULL)
    {
        printf("Unable to create file database.txt, exiting.");
        exit(1);
    }

    // vars
    int lan, opt, ng = 0, i, add = 0, player = 1, choice, br = 0;
    char mark, sw_name[64];

lang: // language select

    printf("ENGLISH (1)\n");
    printf("HRVATSKI (2)\n");
    printf("Please select a language: ");
    scanf("%d", &lan);

    switch (lan)
    {

    case 1: // user picked english

    input1:
        printf("WELCOME!\n");
        printf("Game Database (1)\n");
        printf("Tic Tac Toe (2)\n");
        printf("Guess The Number (3)\n");
        printf("Change language (4)\n");
        printf("Pick an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:

        // database eng
        db_en:
            printf("GAME DATABASE\n");
            printf("Make a new database (1)\n");
            printf("Add to the current database (2)\n");
            printf("Print database (3)\n");
            printf("Sort data (4)\n");
            printf("Search data (5)\n");
            printf("Swap data (6)\n");
            printf("Go back (7)\n");
            printf("Pick an option: ");
            scanf("%d", &opt);
            // user picked an option
            switch (opt)
            {
            case 1: // making a new db
                ng = 0;
                database = fopen("database.txt", "w");
                printf("Enter the number of games you wish to enter (max 100): ");
                scanf("%d", &ng); // user entered how many games they want added
                for (i = 0; i < ng; i++)
                {
                    printf("Enter the name of the %d. game: ", i + 1);
                    scanf(" %[^\n]%*c", x[i].name);
                    printf("Enter the year of release for the %d. game: ", i + 1);
                    scanf("%d", &x[i].year);
                    printf("Enter the name of the development studio: ");
                    scanf(" %[^\n]%*c", x[i].developer);
                    printf("Enter the name of the publishing studio: ");
                    scanf(" %[^\n]%*c", x[i].publisher);
                    printf("Enter the amount of awards the game won: ");
                    scanf("%d", &x[i].awards);
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                printf("Database created.\n");
                fclose(database);
                goto db_en;
                break;
            case 2:
                i = 0;
                br = 0;
                database = fopen("database.txt", "r");
                while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
                {
                    br++;
                    i++;
                }
                fclose(database);
                database = fopen("database.txt", "a");
                printf("Enter how many more games do you want to add: ");
                scanf("%d", &add);
                add += br;
                for (i = br; i < add; i++)
                {
                    printf("Enter the name of the %d. game: ", i + 1);
                    scanf(" %[^\n]%*c", x[i].name);
                    printf("Enter the year of release for the %d. game: ", i + 1);
                    scanf("%d", &x[i].year);
                    printf("Enter the name of the development studio: ");
                    scanf(" %[^\n]%*c", x[i].developer);
                    printf("Enter the name of the publishing studio: ");
                    scanf(" %[^\n]%*c", x[i].publisher);
                    printf("Enter the amount of awards the game won: ");
                    scanf("%d", &x[i].awards);
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                ng = add;
                add = 0;
                printf("Database appended.\n");
                fclose(database);
                goto db_en;
                break;
            case 3:
                database = fopen("database.txt", "r");
                i = 0;
                while (fscanf(database, " %d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
                {
                    printf("The %d. game:\n", x[i].id);
                    printf("Name: %s\n", x[i].name);
                    printf("Year of release: %d\n", x[i].year);
                    printf("Developed by: %s\n", x[i].developer);
                    printf("Published by: %s\n", x[i].publisher);
                    printf("Number of awards won: %d\n", x[i].awards);
                    i++;
                }
                printf("Database printed.\n");
                fclose(database);
                goto db_en;
                break;
            case 4:
            sort_en:
                printf("Ascending sort (1)\n");
                printf("Descending sort (2)\n");
                printf("Go back (3)\n");
                printf("Pick an option: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                sort_asc_en:
                    printf("Sort by game name (1)\n");
                    printf("Sort by year of release (2)\n");
                    printf("Sort by developer name (3)\n");
                    printf("Sort by publisher name (4)\n");
                    printf("Sort by number of awards (5)\n");
                    printf("Go back (6)\n");
                    printf("Pick an option: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_asc_name();
                        printf("File sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 2:
                        sort_asc_year();
                        printf("File sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 3:
                        sort_asc_dev();
                        printf("File sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 4:
                        sort_asc_pub();
                        printf("File sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 5:
                        sort_asc_awards();
                        printf("File sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 6:
                        goto sort_en;
                        break;
                    default:
                        printf("Bad input. Please try again.\n");
                        goto sort_asc_en;
                        break;
                    }
                    break;
                case 2:
                sort_des_en:
                    printf("Sort by game name (1)\n");
                    printf("Sort by year of release (2)\n");
                    printf("Sort by developer name (3)\n");
                    printf("Sort by publisher name (4)\n");
                    printf("Sort by number of awards (5)\n");
                    printf("Go back (6)\n");
                    printf("Pick an option: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_des_name();
                        printf("File sorted.\n");
                        goto sort_des_en;
                        break;
                    case 2:
                        sort_des_year();
                        printf("File sorted.\n");
                        goto sort_des_en;
                        break;
                    case 3:
                        sort_des_dev();
                        printf("File sorted.\n");
                        goto sort_des_en;
                        break;
                    case 4:
                        sort_des_pub();
                        printf("File sorted.\n");
                        goto sort_des_en;
                        break;
                    case 5:
                        sort_des_awards();
                        printf("File sorted.\n");
                        goto sort_des_en;
                        break;
                    case 6:
                        goto sort_en;
                        break;
                    default:
                        printf("Bad input. Please try again.\n");
                        goto sort_des_en;
                        break;
                    }
                    break;
                case 3:
                    goto db_en;
                    break;
                default:
                    printf("Bad input. Please try again.\n");
                    goto sort_en;
                    break;
                }
                break;
            case 5:
            search_en:
                printf("Search by year (1)\n");
                printf("Search by developer (2)\n");
                printf("Search by publisher (3)\n");
                printf("Go back (4)\n");
                printf("Pick an option: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    search_year();
                    printf("Database searched.\n");
                    goto search_en;
                    break;
                case 2:
                    search_dev();
                    printf("Database searched.\n");
                    goto search_en;
                    break;
                case 3:
                    search_pub();
                    printf("Database searched.\n");
                    goto search_en;
                    break;
                case 4:
                    goto db_en;
                    break;
                default:
                    printf("Bad input. Please try again.\n");
                    goto search_en;
                    break;
                }
                break;
            case 6:
                i = 0;
                br = 0;
                database = fopen("database.txt", "r");
                while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
                {
                    br++;
                    i++;
                }
                fclose(database);
                database = fopen("database.txt", "w");
                printf("Enter the name of the game for which you want to swap data: ");
                scanf(" %[^\n]%*c", sw_name);
                for (i = 0; i < br; i++)
                {
                    if (strcmp(x[i].name, sw_name) == 0)
                    {
                        printf("Enter the year of release: ");
                        scanf("%d", &x[i].developer);
                        printf("Enter the name of the development studio: ");
                        scanf(" %[^\n]%*c", x[i].developer);
                        printf("Enter the name of the publishing studio: ");
                        scanf(" %[^\n]%*c", x[i].publisher);
                        printf("Enter the amount of awards the game won: ");
                        scanf("%d", &x[i].awards);
                    }
                }
                for (i = 0; i < br; i++)
                {
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                printf("Data swapped.\n");
                fclose(database);
                goto db_en;
                break;
            case 7:
                goto input1;
                break;
            default:
                printf("Bad input. Please try again.\n");
                goto db_en;
                break;
            }
            break;
        case 2: // tic tac toe
            do
            {
                board_en();
                player = (player % 2) ? 1 : 2;
                printf("P%d, enter a number:  ", player);
                scanf("%d", &choice);
                mark = (player == 1) ? 'X' : 'O';
                if (choice == 1 && grid[1] == '1')
                {
                    grid[1] = mark;
                }
                else if (choice == 2 && grid[2] == '2')
                {
                    grid[2] = mark;
                }
                else if (choice == 3 && grid[3] == '3')
                {
                    grid[3] = mark;
                }
                else if (choice == 4 && grid[4] == '4')
                {
                    grid[4] = mark;
                }
                else if (choice == 5 && grid[5] == '5')
                {
                    grid[5] = mark;
                }
                else if (choice == 6 && grid[6] == '6')
                {
                    grid[6] = mark;
                }
                else if (choice == 7 && grid[7] == '7')
                {
                    grid[7] = mark;
                }
                else if (choice == 8 && grid[8] == '8')
                {
                    grid[8] = mark;
                }
                else if (choice == 9 && grid[9] == '9')
                {
                    grid[9] = mark;
                }
                else
                {
                    printf("Invalid move.");
                    player--;
                    getch();
                }
                i = check();
                player++;
            } while (i == -1);
            board_en();
            if (i == 1)
            {
                printf("P%d wins!\n", --player);
                grid[0] = '0';
                grid[1] = '1';
                grid[2] = '2';
                grid[3] = '3';
                grid[4] = '4';
                grid[5] = '5';
                grid[6] = '6';
                grid[7] = '7';
                grid[8] = '8';
                grid[9] = '9';
                player = 1;
                goto input1;
            }
            else
            {
                printf("Game draw.\n");
                grid[0] = '0';
                grid[1] = '1';
                grid[2] = '2';
                grid[3] = '3';
                grid[4] = '4';
                grid[5] = '5';
                grid[6] = '6';
                grid[7] = '7';
                grid[8] = '8';
                grid[9] = '9';
                player = 1;
                goto input1;
            }
            break;
        case 3:
            printf("");
            break;
        case 4:
            goto lang;
            break;
        default:
            printf("Bad input. Please try again.\n");
            goto input1;
            break;
        }
        break;

    case 2: // user picked croatian

    unos:
        printf("DOBRODOSLI!\n");
        printf("Baza Podataka Igara (1)\n");
        printf("Krizic Kruzic (2)\n");
        printf("Pogodi Broj (3)\n");
        printf("Promjeni jezik (4)\n");
        printf("Odaberi: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            goto lang;
            break;
        default:
            printf("Pogresan unos. Ponovite unos.\n");
            goto unos;
            break;
        }
        break;
    default:
        printf("Bad input. Please try again.\n");
        printf("Pogresan unos. Ponovite unos.\n");
        goto lang;
        break;
    }
    return 0;
}

// sorting functions
void sort_asc_name()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].name[0] > x[j].name[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_asc_year()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].year > x[j].year)
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_asc_dev()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].developer[0] > x[j].developer[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_asc_pub()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].publisher[0] > x[j].publisher[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_asc_awards()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].awards > x[j].awards)
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_des_name()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].name[0] < x[j].name[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_des_year()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].year < x[j].year)
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_des_dev()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].developer[0] < x[j].developer[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_des_pub()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].publisher[0] < x[j].publisher[0])
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

void sort_des_awards()
{
    FILE *database;
    int i = 0, br = 0, j;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    for (i = 0; i < br - 1; i++)
    {
        for (j = i + 1; j < br; j++)
        {
            if (x[i].awards < x[j].awards)
            {
                pom = x[i];
                x[i] = x[j];
                x[j] = pom;
            }
        }
    }
    fclose(database);
    database = fopen("database.txt", "w");
    for (i = 0; i < br; i++)
    {
        x[i].id = i + 1;
        fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
    }
    fclose(database);
}

// search functions

void search_year()
{
    FILE *database;
    int i = 0, br = 0, s_year;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    printf("Enter the year you want to search for: ");
    scanf("%d", &s_year);
    for (i = 0; i < br; i++)
    {
        if (x[i].year == s_year)
        {
            printf("The %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n", x[i].awards);
        }
    }
    fclose(database);
}

void search_dev()
{
    FILE *database;
    int i = 0, br = 0;
    char s_dev[64];
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    printf("Enter the developer you want to search for: ");
    scanf(" %[^\n]%*c", s_dev);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].developer, s_dev) == 0)
        {
            printf("The %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n", x[i].awards);
        }
    }
    fclose(database);
}

void search_pub()
{
    FILE *database;
    int i = 0, br = 0;
    char s_pub[64];
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    printf("Enter the publisher you want to search for: ");
    scanf(" %[^\n]%*c", s_pub);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].publisher, s_pub) == 0)
        {
            printf("The %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n", x[i].awards);
        }
    }
    fclose(database);
}

// tic tac toe functions

void board_en()
{
    system("cls");
    printf("\nTic Tac Toe\n");
    printf("P1 (X) - P2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", grid[1], grid[2], grid[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);
    printf("     |     |     \n\n");
}

int check()
{
    if (grid[1] == grid[2] && grid[2] == grid[3])
    {
        return 1;
    }
    else if (grid[4] == grid[5] && grid[5] == grid[6])
    {
        return 1;
    }
    else if (grid[7] == grid[8] && grid[8] == grid[9])
    {
        return 1;
    }
    else if (grid[1] == grid[4] && grid[4] == grid[7])
    {
        return 1;
    }
    else if (grid[2] == grid[5] && grid[5] == grid[8])
    {
        return 1;
    }
    else if (grid[3] == grid[6] && grid[6] == grid[9])
    {
        return 1;
    }
    else if (grid[1] == grid[5] && grid[5] == grid[9])
    {
        return 1;
    }
    else if (grid[3] == grid[5] && grid[5] == grid[7])
    {
        return 1;
    }
    else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' && grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

// guessing game functions