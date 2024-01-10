#include <stdio.h>
#include "opponents.h"
#include "file_logic.h"
#include "mainMenuDisplay.h"
#include "boardDisplay.h"
// importint .h failus

int main()
{
    int rowW, colW, col1,col2,col3,col4,row1,row2,row3,row4;

    Board board = allocateBoard();

    int rowValue = 0;
    int colValue = 0;

    int userChoice;
    int player = -1;
    int *array2 = (int*)calloc(4, sizeof(int));
    int *array3 = (int*)calloc(4, sizeof(int));

    int save = 0;

    int game_board[BOARD_SIZE][BOARD_SIZE] = {{0, H, 0, H, 0, H, 0, H},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0},
                                              {F, 0, 0, 0, 0, 0, 0, 0}};

    int game_select = 0;
    unsigned short int filesSaved = 0; //how many files has the user saved //Need for menuCLI
    unsigned short int foxOrHoundsTurn = 0; //Stores whoewers turn it is //1 if fox, 0 if hounds
    unsigned short int isPvP = 0; //is the mode selected PvP
    unsigned short int breakOut = 0; //int for breaking from Ignas loops

    //loop'ai kad zaidejas galetu sokineti tarp pasirinkimu, juos keisti
    while(1) //Igno loop'as
    {
        game_select = menuCLI (game_select, filesSaved); // igno kazkokia funkcija

        if(game_select != 1) break;

        while(1)
        {
            playerSelect = menuCLI(4, filesSaved);
            if(playerSelect == 4) break;

            if(playerSelect == 3) isPvP = 1;

            while(1)
            {
                difficulty = menuCLI(3, filesSaved);// igno difficulty and player choosing - what character to play
                if(difficulty == 5) break;

                if(difficulty == 4)
                {
                    //custom difficulty options
                    while(1)
                    {
                        difficulty = menuCLI(5, filesSaved);
                        if(difficulty == 0) break;
                        else
                        {
                            breakOut = 1;
                            break;
                        }
                    }
                }
                else
                {
                    breakOut = 1;
                    break;
                }
                if(breakOut) break;
            }
            if(breakOut) break;
        }
        if(breakOut) break;
        game_select = 0;
    }
    
    //Does this above in Ignas loop
    //game_select = menuCLI(game_select, filesSaved);; // igno kazkokia funkcija // filesSaved - kiek filu yra isaugota

    if (game_select == 1) //start new game
    {
        //Does this above in Ignas loop
        /*
        int difficulty = menuCLI(3, filesSaved); // igno difficulty and player choosing what character to play
        int playerSelect = menuCLI(4, filesSaved); // choosing what character to play
        */
        switch (difficulty)
        {
        case 1:
            difficulty = EASY;
            break;
        case 2:
            difficulty = MEDIUM;
            break;
        default:
            difficulty = HARD;
            break;
        }

        //Does this above in Ignas loop
        //select character game mode 0 fox 1 hound 2 pvp
        //igno CLI
        //player turi buti 0-2 intervale
    }
    else if (game_select == 2) //continue
    {
        // luko funkcija kuri is save file paima boarda ir difficulty
        // jeigu jo nera tai tsg grazina default boarda
        displayLastModifiedTime();
        //printf("\n Which save you want to open \n "); // ***Ignai please CLI this one
        //scanf("%d", &save);
        save = menuCLI(game_select, filesSaved);
        
        processInput(&save, array2, array3, &rowW, &colW, &player, &difficulty, board); //I have not added difficulty but I can add it

        Structas save_data = get_save_data(); // luko kazkokia funkcija kuri grazina structa kazkoki kur yra {int difficulty, int board[8][8]}

        int difficulty = save_data.difficulty;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                game_board[i][j] = save_data.board[i][j];
            }
        }
    }
    else //exit
    {
        freeMemory(board, array2, array3);
        exitGame(); // igno funkcija kuri isjungia programa
        return 0;
    }

    //this is to start new game ima need help and time

    if(save == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = '0';
            }
        }

        if(player == 0 || player == 3)
        {
            rowW = 7;
            colW = 4;
            col1 = 7;
            col2 = 5;
            col3 = 3;
            col4 = 1;
            row1 = 0;
            row2 = 0;
            row3 = 0;
            row4 = 0;
        }
        else if(player == 1)
        {
            rowW = 0;
            colW = 3;
            col1 = 0;
            col2 = 2;
            col3 = 4;
            col4 = 6;
            row1 = 7;
            row2 = 7;
            row3 = 7;
            row4 = 7;
        }
        board[rowW][colW] = 'F';
        board[row1][col1] = 'H';
        board[row2][col2] = 'H';
        board[row3][col3] = 'H';
        board[row4][col4] = 'H';
        array2[1] = row2;
        array2[2] = row3;
        array2[3] = row4;
        array3[0] = col1;
        array3[1] = col2;
        array3[2] = col3;
        array3[3] = col4;
    }
    else
    {
        if(player == 1 || player == 2)
        {
            row1 = array2[0];
            row2 = array2[1];
            row3 = array2[2];
            row4 = array2[3];
            col1 = array3[0];
            col2 = array3[1];
            col3 = array3[2];
            col4 = array3[3];
        }
    }

    
    do
    {                   //Reikia informacijos -: isPvP: 1 if playing VS another player, else 0 | foxOrHoundsTurn: 1 if fox, else 0 hounds
        int new_move = displayBoard (game_board, isPvP, difficulty, foxOrHoundsTurn); // igno funkcija kuri grazina skaiciuka kur paejo Fox

       if(player == 0 || player == 2) //fox = 0 hound = 1 pvp = 2
       {
           printBoard(board);
           check_lose();
           if(win==1 || lose == 4)
           {
               break
           }
           int enterNumber = getUserInput();
           if(enterNumber == 0)
           {
               save_game();
               break;
           }
           move = enterNumber;
           fMove(); //player moves
           if(player == 0)
           {
               boardTransfer(board, game_board);
           }
           
       }
        else
       {
           boardTransfer(board, game_board);
           printBoard(board);
           
           //bot moves

           transferBoard(board, game_board);
       }
        
       if(player == 0)
       {
           printBoard(board);
           boardTransfer(board, game_board);
           check_lose();
           
           if(win == 1 || lose == 4) 
           {
               break;
           }
           //bot moves

           transferBoard(board, game_board);
       }
        else if(player == 1 || player == 2)
       {
           printBoard(board);
           if(player == 1)
           {
               //jokubo check lose funkc.
               //jokubai galesi pritaikyt savo kazkaip nzn ir kad grazintu lose = 4 ir win = 1 jei salygos priimtos
           }
           else
           {
               check_lose();
               
               if(win == 1 || lose == 4) 
               {
                   break;
               }
           }

            printf("Hound to move 1-4 or save 0: "); //Ignai tavo CLI
            scanf("%d", &userChoice);
           
           if(userChoice == 0)
            {
                save_game(array2, array3, &rowW, &colW, &player, board);
                break;
            }
            generateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);
           
            printf("Enter a number to move the 'H' (1-2): "); // tavo CLI ignai
            scanf("%d", &move);

            hMove(board, &rowValue, &colValue, move);
            NewgenerateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);
            
       }

    } while (!luko_game_over_function()); // luko funkcija kuri tikrina ar game over

    freeMemory(board, array2, array3);
    Pwin_lose(&win, &lose, &player);
    
    //display_result(game_board); /// igno funkcija kuri paziuri kas laimejo ir isveda rezultata
    ///Reikia informacijos -: PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win <--------- need variables
    results (points, PlayerVSwho, playerWinVSbot, playerWinVSplayer);
}
