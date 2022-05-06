#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

// game db struct

struct Game_DB
{
    int id;
    char name[64];
    int year;
    char developer[64];
    char publisher[64];
    int awards;
} x[100],pom;

char grid[10]={'0','1','2','3','4','5','6','7','8','9'};

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

// ttt func
void board_en();
void board_hr();
int check();

// main function
int main()
{
    // files
    FILE *database;
    if(database==NULL){
        printf("Unable to create file database.txt, exiting.");
    }
    /* FILE *sheet;
    if(sheet==NULL){
        printf("Unable to create file sheet.txt, exiting.");
    } */
    
    // vars
    int lan, opt, ng=0, i, add=0, player=1,choice;
    char mark;

lang:   // language select
    
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
        
        // database eng
        db_en:
            printf("GAME DATABASE\n");
            printf("Make a new database (1)\n");
            printf("Add to the current database (2)\n");
            printf("Print database(3)\n");
            printf("Sort data (4)\n");
            printf("Filter data(5)\n");
            printf("Delete data (6)\n");
            printf("Go back (7)\n");
            printf("Pick an option: ");
            scanf("%d", &opt);
            // user picked an option
            switch (opt)
            {
            case 1: // making a new db
                ng=0;
                if(database!=NULL){
                    remove(database);
                }
                database = fopen("database.txt", "w");
                printf("Enter the number of games you wish to enter (max 100): ");
                scanf("%d", &ng); // user entered how many games they want added
                for (i = 0; i < ng; i++)
                {
                    printf("Enter the name of the %d. game: ",i + 1);
                    scanf(" %[^\n]%*c",x[i].name);
                    printf("Enter the year of release for the %d. game: ", i + 1);
                    scanf("%d",&x[i].year);
                    printf("Enter the name of the development studio: ");
                    scanf(" %[^\n]%*c",x[i].developer);
                    printf("Enter the name of the publishing studio: ");
                    scanf(" %[^\n]%*c",x[i].publisher);
                    printf("Enter the amount of awards the game won: ");
                    scanf("%d",&x[i].awards);
                    x[i].id=i+1;
                    fprintf(database,"%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id,x[i].name,x[i].awards,x[i].developer,x[i].publisher,x[i].awards);
                }
                printf("Database created.\n");
                fclose(database);
                goto db_en;
                break;
            case 2:
                database = fopen("database.txt","a");
                printf("Enter how many more games do you want to add: ");
                scanf("%d",&add);
                add+=ng;
                for(i=ng;i<add;i++){
                    printf("Enter the name of the %d. game: ",i + 1);
                    scanf(" %[^\n]%*c",x[i].name);
                    printf("Enter the year of release for the %d. game: ", i + 1);
                    scanf("%d",&x[i].year);
                    printf("Enter the name of the development studio: ");
                    scanf(" %[^\n]%*c",x[i].developer);
                    printf("Enter the name of the publishing studio: ");
                    scanf(" %[^\n]%*c",x[i].publisher);
                    printf("Enter the amount of awards the game won: ");
                    scanf("%d",&x[i].awards);
                    x[i].id=i+1;
                    fprintf(database,"%d\n%s\n%d\n%s\n%s\n%d\n", x[i].id,x[i].name,x[i].awards,x[i].developer,x[i].publisher,x[i].awards);
                }
                ng=add;
                add=0;
                printf("Database appended.\n");
                fclose(database);
                goto db_en;
            break;
            case 3:
                database = fopen("database.txt","r");
                i=0;
                while(fscanf(database," %d\n%[^,]\n%d\n%[^,]\n%[^,]\n%d\n",&x[i].id,x[i].name,&x[i].year,x[i].developer,x[i].publisher,x[i].awards)==6){
                    printf("The %d. game:\n",x[i].id);
                    printf("Name: %s\n",x[i].name);
                    printf("Year of release %d:\n",x[i].year);
                    printf("Developed by: %s\n",x[i].developer);
                    printf("Published by: %s:\n",x[i].publisher);
                    printf("Number of awards won: %d\n",x[i].awards);
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
                scanf("%d",&opt);
                switch(opt){
                    case 1:
                    sort_asc_en:
                        printf("Sort by game name (1)\n");  
                        printf("Sort by year of release (2)\n");  
                        printf("Sort by developer name (3)\n");  
                        printf("Sort by publisher name (4)\n");  
                        printf("Sort by number of awards (5)\n");  
                        scanf("%d",&opt);
                        switch(opt){
                            /*case 1:
                                sort_asc_name();
                            break;
                            case 2:
                                sort_asc_year();
                            break;
                            case 3:
                                sort_asc_dev();
                            break;
                            case 4:
                                sort_asc_pub();
                            break;
                            case 5:
                                sort_asc_awards();
                            break;*/
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
                        scanf("%d",&opt);
                        switch(opt){
                            case 1:
                            break;
                            case 2:
                            break;
                            case 3:
                            break;
                            case 4:
                            break;
                            case 5:
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
        case 2: // tic tac toe
            do{
                board_en();
                player=(player%2) ? 1:2;
                printf("P%d, enter a number:  ", player);
                scanf("%d", &choice);
                mark=(player==1) ? 'X':'O';
                if(choice == 1 && grid[1]=='1'){
                    grid[1]=mark;
                }else if(choice == 2 && grid[2]=='2'){
                    grid[2]=mark;
                }else if(choice == 3 && grid[3]=='3'){
                    grid[3]=mark;
                }else if(choice == 4 && grid[4]=='4'){
                    grid[4]=mark;
                }else if(choice == 5 && grid[5]=='5'){
                    grid[5]=mark;
                }else if(choice == 6 && grid[6]=='6'){
                    grid[6]=mark;
                }else if(choice == 7 && grid[7]=='7'){
                    grid[7]=mark;
                }else if(choice == 8 && grid[8]=='8'){
                    grid[8]=mark;
                }else if(choice == 9 && grid[9]=='9'){
                    grid[9]=mark;
                }else{
                    printf("Invalid move.");
                    player--;
                    getch();
                }
                i=check();
                player++;
            }while(i==-1);
            board_en();
            if(i==1){
                printf("P%d wins!\n",--player);
                grid[0]='0';
                grid[1]='1';
                grid[2]='2';
                grid[3]='3';
                grid[4]='4';
                grid[5]='5';
                grid[6]='6';
                grid[7]='7';
                grid[8]='8';
                grid[9]='9';
                player=1;
                goto input1;
            }else{
                printf("Game draw.\n");
                grid[0]='0';
                grid[1]='1';
                grid[2]='2';
                grid[3]='3';
                grid[4]='4';
                grid[5]='5';
                grid[6]='6';
                grid[7]='7';
                grid[8]='8';
                grid[9]='9';
                player=1;
                goto input1;
            }
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

// sorting functions
void sort_asc_name(){
    
}

// tic tac toe functions

void board_en(){
    system("cls");
    printf("\nTic Tac Toe\n");
    printf("P1 (X) - P2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",grid[1], grid[2], grid[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[4], grid[5], grid[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", grid[7], grid[8], grid[9]);
    printf("     |     |     \n\n");
}

int check(){
    if(grid[1]==grid[2]&&grid[2]==grid[3]){
        return 1;
    }else if(grid[4]==grid[5]&&grid[5]==grid[6]){
        return 1;
    }else if(grid[7]==grid[8]&&grid[8]==grid[9]){
        return 1;
    }else if(grid[1]==grid[4]&&grid[4]==grid[7]){
        return 1;
    }else if(grid[2]==grid[5]&&grid[5]==grid[8]){
        return 1;
    }else if(grid[3]==grid[6]&&grid[6]==grid[9]){
        return 1;
    }
    else if(grid[1]==grid[5]&&grid[5]==grid[9]){
        return 1;
    }
    else if(grid[3]==grid[5]&&grid[5]==grid[7]){
        return 1;
    }
    else if(grid[1]!='1'&&grid[2]!='2'&&grid[3]!='3'&&grid[4]!='4'&&grid[5]!='5'&&grid[6]!='6'&&grid[7]!='7'&&grid[8]!='8'&&grid[9]!='9'){
        return 0;
    }else{
        return -1;
    }
}
