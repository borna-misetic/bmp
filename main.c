#include <stdio.h>
struct Game_DB
{
    char name[64];
    int year;
    char developer[64];
    char publisher[64];
    int awards;
} x[100];
int main()
{
    FILE *database;
    database = fopen("database.txt", "w");
    int lan, opt, ng, i;
lang:
    printf("Borna Multitool Program!\n");
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
        printf("D&D Character Sheet Creator (3)\n");
        printf("Multipurpose Calculator (4)\n");
        printf("Change language (5)\n");
        printf("Pick an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        db_en:
            printf("GAME DATABASE\n");
            printf("Make a new database (1)\n");
            printf("Add to the current database (2)\n");
            printf("Print database(3)\n");
            printf("Count data(4)\n");
            printf("Sort data (5)\n");
            printf("Delete data (6)\n");
            printf("Go back (7)\n");
            printf("Pick an option: ");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                printf("Enter the number of games you wish to enter (max 100): ");
                scanf("%d", &ng);
                for (i = 1; i <= ng; i++)
                {
                    printf("Enter the name of the %d. game: ", i);
                    scanf("%[^\n]s", x[i].name);
                    printf("%s", x[i].name);
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
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
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
        printf("Alat za izradu D&D lika (3)\n");
        printf("Visenamjenski Kalkulator (4)\n");
        printf("Promjeni jezik (5)\n");
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
            break;
        case 5:
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