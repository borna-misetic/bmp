#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>

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
void search_year_hr();
void search_dev_hr();
void search_pub_hr();

// ttt func
void board_en();
void board_hr();
int check();

// guessing funcs
void guess_en(int, int);
void guess_hr(int, int);

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
    srand(time(0));

lang: // language select

    printf("\nENGLISH (1)\n");
    printf("HRVATSKI (2)\n");
    printf("\nPlease select a language / Molimo odaberite jezik: ");
    scanf("%d", &lan);

    switch (lan)
    {

    case 1: // user picked english

    input1:
        printf("\nWELCOME!\n\n");
        printf("Game Database (1)\n");
        printf("Tic Tac Toe (2)\n");
        printf("Guess The Number (3)\n");
        printf("Change language (4)\n");
        printf("\nPick an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:

        // database eng
        db_en:
            printf("\nGAME DATABASE\n\n");
            printf("Make a new database (1)\n");
            printf("Add to the current database (2)\n");
            printf("Print database (3)\n");
            printf("Sort data (4)\n");
            printf("Search data (5)\n");
            printf("Swap data (6)\n");
            printf("Go back (7)\n\n");
            printf("Pick an option: ");
            scanf("%d", &opt);
            // user picked an option
            switch (opt)
            {
            case 1: // making a new db
                ng = 0;
                database = fopen("database.txt", "w");
                printf("\nEnter the number of games you wish to enter (max 100): ");
                scanf("%d", &ng); // user entered how many games they want added
                for (i = 0; i < ng; i++)
                {
                    printf("\nEnter the name of the %d. game: ", i + 1);
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
                printf("\nDatabase created.\n");
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
                printf("\nEnter how many more games do you want to add: ");
                scanf("%d", &add);
                add += br;
                for (i = br; i < add; i++)
                {
                    printf("\nEnter the name of the %d. game: ", i + 1);
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
                printf("\nDatabase appended.\n");
                fclose(database);
                goto db_en;
                break;
            case 3:
                database = fopen("database.txt", "r");
                i = 0;
                while (fscanf(database, " %d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
                {
                    printf("\nThe %d. game:\n", x[i].id);
                    printf("Name: %s\n", x[i].name);
                    printf("Year of release: %d\n", x[i].year);
                    printf("Developed by: %s\n", x[i].developer);
                    printf("Published by: %s\n", x[i].publisher);
                    printf("Number of awards won: %d\n", x[i].awards);
                    i++;
                }
                printf("\nDatabase printed.\n");
                fclose(database);
                goto db_en;
                break;
            case 4:
            sort_en:
                printf("\nAscending sort (1)\n");
                printf("Descending sort (2)\n");
                printf("Go back (3)\n");
                printf("\nPick an option: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                sort_asc_en:
                    printf("\nSort by game name (1)\n");
                    printf("Sort by year of release (2)\n");
                    printf("Sort by developer name (3)\n");
                    printf("Sort by publisher name (4)\n");
                    printf("Sort by number of awards (5)\n");
                    printf("Go back (6)\n");
                    printf("\nPick an option: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_asc_name();
                        printf("\nFile sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 2:
                        sort_asc_year();
                        printf("\nFile sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 3:
                        sort_asc_dev();
                        printf("\nFile sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 4:
                        sort_asc_pub();
                        printf("\nFile sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 5:
                        sort_asc_awards();
                        printf("\nFile sorted.\n");
                        goto sort_asc_en;
                        break;
                    case 6:
                        goto sort_en;
                        break;
                    default:
                        printf("\nBad input. Please try again.\n");
                        goto sort_asc_en;
                        break;
                    }
                    break;
                case 2:
                sort_des_en:
                    printf("\nSort by game name (1)\n");
                    printf("Sort by year of release (2)\n");
                    printf("Sort by developer name (3)\n");
                    printf("Sort by publisher name (4)\n");
                    printf("Sort by number of awards (5)\n");
                    printf("Go back (6)\n");
                    printf("\nPick an option: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_des_name();
                        printf("\nFile sorted.\n");
                        goto sort_des_en;
                        break;
                    case 2:
                        sort_des_year();
                        printf("\nFile sorted.\n");
                        goto sort_des_en;
                        break;
                    case 3:
                        sort_des_dev();
                        printf("\nFile sorted.\n");
                        goto sort_des_en;
                        break;
                    case 4:
                        sort_des_pub();
                        printf("\nFile sorted.\n");
                        goto sort_des_en;
                        break;
                    case 5:
                        sort_des_awards();
                        printf("\nFile sorted.\n");
                        goto sort_des_en;
                        break;
                    case 6:
                        goto sort_en;
                        break;
                    default:
                        printf("\nBad input. Please try again.\n");
                        goto sort_des_en;
                        break;
                    }
                    break;
                case 3:
                    goto db_en;
                    break;
                default:
                    printf("\nBad input. Please try again.\n");
                    goto sort_en;
                    break;
                }
                break;
            case 5:
            search_en:
                printf("\nSearch by year (1)\n");
                printf("Search by developer (2)\n");
                printf("Search by publisher (3)\n");
                printf("Go back (4)\n");
                printf("\nPick an option: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    search_year();
                    printf("\nDatabase searched.\n");
                    goto search_en;
                    break;
                case 2:
                    search_dev();
                    printf("\nDatabase searched.\n");
                    goto search_en;
                    break;
                case 3:
                    search_pub();
                    printf("\nDatabase searched.\n");
                    goto search_en;
                    break;
                case 4:
                    goto db_en;
                    break;
                default:
                    printf("\nBad input. Please try again.\n");
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
                printf("\nEnter the name of the game for which you want to swap data: ");
                scanf(" %[^\n]%*c", sw_name);
                for (i = 0; i < br; i++)
                {
                    if (strcmp(x[i].name, sw_name) == 0)
                    {
                        printf("\nEnter the year of release: ");
                        scanf("%d", &x[i].year);
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
                printf("\nData swapped.\n");
                fclose(database);
                goto db_en;
                break;
            case 7:
                goto input1;
                break;
            default:
                printf("\nBad input. Please try again.\n");
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
            guessing_en:
            printf("\n(1) Easy difficulty - 10 guesses\n");
            printf("(2) Medium difficulty - 7 guesses\n");
            printf("(3) Hard difficulty - 3 guesses\n");
            printf("\nPick an option: ");
            scanf("%d",&opt);
            switch(opt){
                case 1:
                    guess_en(200,10);
                    goto input1;
                break;
                case 2:
                    guess_en(200,7);
                    goto input1;
                break;
                case 3:
                    guess_en(200,3);
                    goto input1;
                break;
                default:
                    printf("\nWrong input. Please try again.\n");
                    goto guessing_en;
                break;
            }
            break;
        case 4:
            goto lang;
            break;
        default:
            printf("\nBad input. Please try again.\n");
            goto input1;
            break;
        }
        break;

        case 2: // user picked croatian

    input2:
        printf("\nDOBRODOSLI!\n\n");
        printf("Baza Podataka Igara (1)\n");
        printf("Krizic Kruzic (2)\n");
        printf("Pogodi Broj (3)\n");
        printf("Promjeni jezik (4)\n");
        printf("\nUnesite odabir: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:

        // database eng
        db_hr:
            printf("\nBAZA PODATAKA IGARA\n\n");
            printf("Kreirajte novu bazu (1)\n");
            printf("Dodajte sadrzaj postojecoj bazi (2)\n");
            printf("Ispisite bazu (3)\n");
            printf("Sortirajte podatke (4)\n");
            printf("Pretrazite podatke (5)\n");
            printf("Izmjenite podatke (6)\n");
            printf("Povratak (7)\n\n");
            printf("Unesite odabir: ");
            scanf("%d", &opt);
            // user picked an option
            switch (opt)
            {
            case 1: // making a new db
                ng = 0;
                database = fopen("database.txt", "w");
                printf("\nUnesite koliko igara zelite unesti (max 100): ");
                scanf("%d", &ng); // user entered how many games they want added
                for (i = 0; i < ng; i++)
                {
                    printf("\nUnesite ime %d. igre: ", i + 1);
                    scanf(" %[^\n]%*c", x[i].name);
                    printf("Unesite godinu izdanja %d. igre: ", i + 1);
                    scanf("%d", &x[i].year);
                    printf("Unesite ime razvojnog studija: ");
                    scanf(" %[^\n]%*c", x[i].developer);
                    printf("Unesite ime izdavackog studija: ");
                    scanf(" %[^\n]%*c", x[i].publisher);
                    printf("Unesite broj nagrada koje je igra osvojila: ");
                    scanf("%d", &x[i].awards);
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                printf("\nBaza podataka kreirana.\n");
                fclose(database);
                goto db_hr;
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
                printf("\nUnesite koliko jos igara zelite dodati: ");
                scanf("%d", &add);
                add += br;
                for (i = br; i < add; i++)
                {
                    printf("\nUnesite ime %d. igre: ", i + 1);
                    scanf(" %[^\n]%*c", x[i].name);
                    printf("Unesite godinu izdanja %d. igre: ", i + 1);
                    scanf("%d", &x[i].year);
                    printf("Unesite ime razvojnog studija: ");
                    scanf(" %[^\n]%*c", x[i].developer);
                    printf("Unesite ime izdavackog studija: ");
                    scanf(" %[^\n]%*c", x[i].publisher);
                    printf("Unesite broj nagrada koje je igra osvojila: ");
                    scanf("%d", &x[i].awards);
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                ng = add;
                add = 0;
                printf("\nPodaci dodani.\n");
                fclose(database);
                goto db_hr;
                break;
            case 3:
                database = fopen("database.txt", "r");
                i = 0;
                while (fscanf(database, " %d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
                {
                    printf("\n%d. igra:\n", x[i].id);
                    printf("Ime: %s\n", x[i].name);
                    printf("Godina izdanja: %d\n", x[i].year);
                    printf("Razvio: %s\n", x[i].developer);
                    printf("Izdao: %s\n", x[i].publisher);
                    printf("Broj osvojenih nagrada: %d\n\n", x[i].awards);
                    i++;
                }
                printf("\nPodaci ispisani.\n");
                fclose(database);
                goto db_hr;
                break;
            case 4:
            sort_hr:
                printf("\nUzlazno sortiranje (1)\n");
                printf("Silazno sortiranje (2)\n");
                printf("Povratak (3)\n");
                printf("\nUnesite odabir: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                sort_asc_hr:
                    printf("\nSortiraj po imenu igre (1)\n");
                    printf("Sortiraj po godini izdanja (2)\n");
                    printf("Sortiraj po imenu razvojnog studija (3)\n");
                    printf("Sortiraj po imenu izdavaca (4)\n");
                    printf("Sortiraj po broju nagrada (5)\n");
                    printf("Povratak (6)\n");
                    printf("\nUnesite odabir: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_asc_name();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_asc_hr;
                        break;
                    case 2:
                        sort_asc_year();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_asc_hr;
                        break;
                    case 3:
                        sort_asc_dev();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_asc_hr;
                        break;
                    case 4:
                        sort_asc_pub();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_asc_hr;
                        break;
                    case 5:
                        sort_asc_awards();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_asc_hr;
                        break;
                    case 6:
                        goto sort_hr;
                        break;
                    default:
                        printf("\nPogresan unos. Molimo ponovite unos.\n");
                        goto sort_asc_hr;
                        break;
                    }
                    break;
                case 2:
                sort_des_hr:
                    printf("\nSortiraj po imenu igre (1)\n");
                    printf("Sortiraj po godini izdanja (2)\n");
                    printf("Sortiraj po imenu razvojnog studija (3)\n");
                    printf("Sortiraj po imenu izdavaca (4)\n");
                    printf("Sortiraj po broju nagrada (5)\n");
                    printf("Povratak (6)\n");
                    printf("\nUnesite odabir: ");
                    scanf("%d", &opt);
                    switch (opt)
                    {
                    case 1:
                        sort_des_name();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_des_hr;
                        break;
                    case 2:
                        sort_des_year();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_des_hr;
                        break;
                    case 3:
                        sort_des_dev();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_des_hr;
                        break;
                    case 4:
                        sort_des_pub();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_des_hr;
                        break;
                    case 5:
                        sort_des_awards();
                        printf("\nDatoteka sortirana.\n");
                        goto sort_des_hr;
                        break;
                    case 6:
                        goto sort_hr;
                        break;
                    default:
                        printf("\nPogresan unos. Molimo ponovite unos.\n");
                        goto sort_des_hr;
                        break;
                    }
                    break;
                case 3:
                    goto db_hr;
                    break;
                default:
                    printf("\nPogresan unos. Molimo ponovite unos.\n");
                    goto sort_hr;
                    break;
                }
                break;
            case 5:
            search_hr:
                printf("\nPretrazivanje po godini izdanja (1)\n");
                printf("Pretrazivanje po razvojnom studiju (2)\n");
                printf("Pretrazivanje po izdavacu (3)\n");
                printf("Povratak (4)\n");
                printf("\nUnesite odabir: ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    search_year_hr();
                    printf("\nPodaci pretrazeni.\n");
                    goto search_hr;
                    break;
                case 2:
                    search_dev_hr();
                    printf("\nPodaci pretrazeni.\n");
                    goto search_hr;
                    break;
                case 3:
                    search_pub_hr();
                    printf("\nPodaci pretrazeni.\n");
                    goto search_hr;
                    break;
                case 4:
                    goto db_hr;
                    break;
                default:
                    printf("\nPogresan unos. Molimo ponovite unos.\n");
                    goto search_hr;
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
                printf("\nUnesite ime igre kojoj zelite izmjenjiti podatke: ");
                scanf(" %[^\n]%*c", sw_name);
                for (i = 0; i < br; i++)
                {
                    if (strcmp(x[i].name, sw_name) == 0)
                    {
                    printf("Unesite godinu izdanja igre: ");
                    scanf("%d", &x[i].year);
                    printf("Unesite ime razvojnog studija: ");
                    scanf(" %[^\n]%*c", x[i].developer);
                    printf("Unesite ime izdavackog studija: ");
                    scanf(" %[^\n]%*c", x[i].publisher);
                    printf("Unesite broj nagrada koje je igra osvojila: ");
                    scanf("%d", &x[i].awards);
                    }
                }
                for (i = 0; i < br; i++)
                {
                    x[i].id = i + 1;
                    fprintf(database, "%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id, x[i].name, x[i].year, x[i].developer, x[i].publisher, x[i].awards);
                }
                printf("\nPodaci izmjenjeni.\n");
                fclose(database);
                goto db_hr;
                break;
            case 7:
                goto input2;
                break;
            default:
                printf("\nPogresan unos. Molimo ponovite unos.\n");
                goto db_hr;
                break;
            }
            break;
        case 2: // tic tac toe
            do
            {
                board_hr();
                player = (player % 2) ? 1 : 2;
                printf("P%d, unesite broj:  ", player);
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
                    printf("Nemoguc potez.");
                    player--;
                    getch();
                }
                i = check();
                player++;
            } while (i == -1);
            board_hr();
            if (i == 1)
            {
                printf("P%d je pobjedio!\n", --player);
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
                goto input2;
            }
            else
            {
                printf("Izjednaceno.\n");
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
                goto input2;
            }
            break;
        case 3:
            guessing_hr:
            printf("\n(1) Lagano - 10 pogadjanja\n");
            printf("(2) Srednje - 7 pogadjanja\n");
            printf("(3) Tesko - 3 pogadjanja\n");
            printf("\nUnesite odabir: ");
            scanf("%d",&opt);
            switch(opt){
                case 1:
                    guess_hr(200,10);
                    goto input2;
                break;
                case 2:
                    guess_hr(200,7);
                    goto input2;
                break;
                case 3:
                    guess_hr(200,3);
                    goto input2;
                break;
                default:
                    printf("\nPogresan unos. Molimo ponovite unos.\n");
                    goto guessing_hr;
                break;
            }
            break;
        case 4:
            goto lang;
            break;
        default:
            printf("\nPogresan unos. Molimo ponovite unos.\n");
            goto input2;
            break;
        }
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
    printf("\nEnter the year you want to search for: ");
    scanf("%d", &s_year);
    for (i = 0; i < br; i++)
    {
        if (x[i].year == s_year)
        {
            printf("\nThe %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n\n", x[i].awards);
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
    printf("\nEnter the developer you want to search for: ");
    scanf(" %[^\n]%*c", s_dev);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].developer, s_dev) == 0)
        {
            printf("\nThe %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n\n", x[i].awards);
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
    printf("\nEnter the publisher you want to search for: ");
    scanf(" %[^\n]%*c", s_pub);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].publisher, s_pub) == 0)
        {
            printf("\nThe %d. game:\n", x[i].id);
            printf("Name: %s\n", x[i].name);
            printf("Year of release: %d\n", x[i].year);
            printf("Developed by: %s\n", x[i].developer);
            printf("Published by: %s\n", x[i].publisher);
            printf("Number of awards won: %d\n\n", x[i].awards);
        }
    }
    fclose(database);
}

void search_year_hr()
{
    FILE *database;
    int i = 0, br = 0, s_year;
    database = fopen("database.txt", "r");
    while (fscanf(database, "%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d\n", &x[i].id, x[i].name, &x[i].year, x[i].developer, x[i].publisher, &x[i].awards) == 6)
    {
        br++;
        i++;
    }
    printf("\nUnesite godinu za koju pretrazujete: ");
    scanf("%d", &s_year);
    for (i = 0; i < br; i++)
    {
        if (x[i].year == s_year)
        {
            printf("\n%d. igra:\n", x[i].id);
            printf("Ime: %s\n", x[i].name);
            printf("Godina izdanja: %d\n", x[i].year);
            printf("Razvio: %s\n", x[i].developer);
            printf("Izdao: %s\n", x[i].publisher);
            printf("Broj osvojenih nagrada: %d\n\n", x[i].awards);
        }
    }
    fclose(database);
}

void search_dev_hr()
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
    printf("\nUnesite ime razvojnog studija kojeg trazite: ");
    scanf(" %[^\n]%*c", s_dev);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].developer, s_dev) == 0)
        {
            printf("\n%d. igra:\n", x[i].id);
            printf("Ime: %s\n", x[i].name);
            printf("Godina izdanja: %d\n", x[i].year);
            printf("Razvio: %s\n", x[i].developer);
            printf("Izdao: %s\n", x[i].publisher);
            printf("Broj osvojenih nagrada: %d\n\n", x[i].awards);
        }
    }
    fclose(database);
}

void search_pub_hr()
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
    printf("\nUnesite ime izdavatelja kojeg trazite: ");
    scanf(" %[^\n]%*c", s_pub);
    for (i = 0; i < br; i++)
    {
        if (strcmp(x[i].publisher, s_pub) == 0)
        {
            printf("\n%d. igra:\n", x[i].id);
            printf("Ime: %s\n", x[i].name);
            printf("Godina izdanja: %d\n", x[i].year);
            printf("Razvio: %s\n", x[i].developer);
            printf("Izdao: %s\n", x[i].publisher);
            printf("Broj osvojenih nagrada: %d\n\n", x[i].awards);
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

void board_hr()
{
    system("cls");
    printf("\nKrizic kruzic\n");
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

void guess_en(int n, int g){
    int num, num_g=0,guess;
    num=rand()%n;
    printf("\nGuess a number between 1 and %d\n",n);
    do{
        if(num_g>g-1){
            printf("\nYou lose!\n");
            printf("The number was %d.\n",num);
            break;
        }
        scanf("%d",&guess);
        if(guess>num){
            printf("Lower number.\n");
            num_g++;
        }else if(guess<num){
            printf("Higher number.\n");
            num_g++;
        }else{
            printf("\nYou guessed the number in %d guesses.\n",num_g+1);
        }
    }while(guess!=num);

}

void guess_hr(int n, int g){
    int num, num_g=0,guess;
    num=rand()%n;
    printf("\nPogodite broj izmedu 1 i %d\n",n);
    do{
        if(num_g>g-1){
            printf("\nIzgubili ste!\n");
            printf("Broj je bio %d.\n",num);
            break;
        }
        scanf("%d",&guess);
        if(guess>num){
            printf("Manji broij.\n");
            num_g++;
        }else if(guess<num){
            printf("Veci broj.\n");
            num_g++;
        }else{
            printf("\nPogodili ste broj nakon %d pogadjanja.\n",num_g+1);
        }
    }while(guess!=num);

}
