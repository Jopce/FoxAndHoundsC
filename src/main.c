#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "opponents.h"
#include "files_logic.h"
#include "mainMenuDisplay.h"
#include "boardDisplay.h"
// importint .h failus

int main()
{
    int rowW, colW;

    Board board = allocateBoard();

    int move;
    int win = 0;
    int lose = 0;
    int difficulty = 0;

    int rowValue = 0;
    int colValue = 0;

    int userChoice;
    int player = -1;
    int *array1 = (int*)calloc(8, sizeof(int));
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
    int isPaused = 0;
    int filesSaved = 0; //how many files has the user saved //Need for menuCLI
    int foxOrHoundsTurn = 0; //Stores whoewers turn it is //1 if fox, 0 if hounds
    int breakOut = 0; //int for breaking from Ignas loops, also used as temporal storage

    //loop'ai kad zaidejas galetu sokineti tarp pasirinkimu, juos keisti
    while(1) //Igno loop'as
    {
        game_select = menuCLI (game_select); // igno kazkokia funkcija

        if(game_select != 1) break;

        while(1)
        {
            player = menuCLI(4);
            if(player == 3) break;

            if(player == 2)
            {
                breakOut = 1;
                break;
            }

            while(1)
            {
                difficulty = menuCLI(3);// igno difficulty and player choosing - what character to play
                if(difficulty == 5) break;

                if(difficulty == 4)
                {
                    //custom difficulty options
                    while(1)
                    {
                        difficulty = menuCLI(5);
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
        //printf("\n Which save you want to open \n "); // ***Ignai please CLI this one
        //scanf("%d", &save);
        save = savedGameMenu();
        displayLastModifiedTime();
        
        processInput(&save, array2, array3, &rowW, &colW, &player, &difficulty, board); //I have not added difficulty but I can add it

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
            array1[1] = 7;
            array1[3] = 5;
            array1[5] = 3;
            array1[7] = 1;
            array1[0] = 0;
            array1[2] = 0;
            array1[4] = 0;
            array1[6] = 0;
        }
        else if(player == 1)
        {
            rowW = 0;
            colW = 3;
            array1[1] = 0;
            array1[3] = 2;
            array1[5] = 4;
            array1[7] = 6;
            array1[0] = 7;
            array1[2] = 7;
            array1[4] = 7;
            array1[6] = 7;
        }
        board[rowW][colW] = 'F';
        board[array1[0]][array1[1]] = 'H';
        board[array1[2]][array1[3]] = 'H';
        board[array1[4]][array1[5]] = 'H';
        board[array1[6]][array1[7]] = 'H';
        array2[0] = array1[0];
        array2[1] = array1[2];
        array2[2] = array1[4];
        array2[3] = array1[6];
        array3[0] = array1[1];
        array3[1] = array1[3];
        array3[2] = array1[5];
        array3[3] = array1[7];
    }
    else
    {
        if(player == 1 || player == 2)
        {
            array1[0] = array2[0];
            array1[2] = array2[1];
            array1[4] = array2[2];
            array1[6] = array2[3];
            array1[1] = array3[0];
            array1[3] = array3[1];
            array1[5] = array3[2];
            array1[7] = array3[3];
        }
    }

    
    do
    {                   //Reikia informacijos -: isPvP: 1 if playing VS another player, else 0 | foxOrHoundsTurn: 1 if fox, else 0 hounds
        int new_move = displayBoard (board, player, difficulty, foxOrHoundsTurn, 1); // igno funkcija kuri grazina skaiciuka kur paejo Fox

       if(player == 0 || player == 2) //fox = 0 hound = 1 pvp = 2
       {
           //printBoard(board);
           breakOut = displayBoard (board, player, difficulty, foxOrHoundsTurn, 0);
           
           check_lose(board, &rowW, &colW, &win, &lose);
           if(win==1 || lose == 4)
           {
               break;
           }
           int enterNumber = getUserInput();
           if(enterNumber == 0)
           {
               save_game(array2, array3, &rowW, &colW, &player, &difficulty, board);
               break;
           }
           move = enterNumber;
           fMove(board, &rowW, &colW, move); //player moves
           if(player == 0)
           {
               boardTransfer(board, game_board);
           }
           
       }
        else
       {
           boardTransfer(board, game_board);
           //printBoard(board);
           breakOut = displayBoard (board, player, difficulty, foxOrHoundsTurn, 0);
           
            // bot is fox
            Move bot_move = opponent_move(game_board, difficulty, 1);

            for (int i = 0; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    game_board[i][j] = bot_move.board[i][j];
                }
            }

           transferBoard(board, game_board);
       }
        
       if(player == 0)
       {
           //printBoard(board);
           breakOut = displayBoard (board, player, difficulty, foxOrHoundsTurn, 0);
           boardTransfer(board, game_board);
           check_lose(board, &rowW, &colW, &win, &lose);
           
           if(win == 1 || lose == 4) 
           {
               break;
           }

           // bot is hounds
            Move bot_move = opponent_move(game_board, difficulty, 0);

            for (int i = 0; i < BOARD_SIZE; i++)
            {
                for (int j = 0; j < BOARD_SIZE; j++)
                {
                    game_board[i][j] = bot_move.board[i][j];
                }
            }

           transferBoard(board, game_board);
       }
        else if(player == 1 || player == 2)
       {
           //printBoard(board);
           breakOut = displayBoard (board, player, difficulty, foxOrHoundsTurn, 0);
           if(player == 1)
           {
               //jokubo check lose funkc.
               //jokubai galesi pritaikyt savo kazkaip nzn ir kad grazintu lose = 4 ir win = 1 jei salygos priimtos

                if (evaluate(game_board) == INT_MAX)
                {
                    win = 1;
                }
                else if (evaluate(game_board) == INT_MIN)
                {
                    lose = 4;
                }
           }
           else
           {
               check_lose(board, &rowW, &colW, &win, &lose);
               
               if(win == 1 || lose == 4) 
               {
                   break;
               }
           }
           
            //printf("Hound to move 1-4 or save 0: "); //Ignai tavo CLI
            //scanf("%d", &userChoice);
            //Igno Pause menu loopas
            while(1)
            {
                isPaused = displayBoard (board, player, difficulty, foxOrHoundsTurn, 1); // igno funkcija kuri grazina skaiciuka kur paejo Fox

                if(isPaused != 0)
                {
                    userChoice = isPaused;
                    break;
                }
                else
                {
                    isPaused = pauseMenu();

                    if(isPaused == 0) //exit with saving
                    {
                        userChoice = isPaused;
                        break;
                    }
                    if(isPaused == 1) continue; //exit without save? not implemented yet
                    if(isPaused == 2) continue; //continue option
                }
            }
           
           
           if(userChoice == 0)
            {
                save_game(array2, array3, &rowW, &colW, &player, &difficulty, board);
                break;
            }
            generateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);

           
            //printf("Enter a number to move the 'H' (1-2): "); // tavo CLI ignai
            //scanf("%d", &move);
            move = displayBoard (board, player, difficulty, foxOrHoundsTurn, 1);

            hMove(board, &rowValue, &colValue, move);
            NewgenerateRowAndColNames(userChoice, &rowValue, &colValue, array2, array3);
            
       }

    } while (1); // luko funkcija kuri tikrina ar game over

    freeMemory(board, array2, array3);
    //Pwin_lose(&win, &lose, &player);
    Pwin_loseCLI (&win, &lose, &player);
}
