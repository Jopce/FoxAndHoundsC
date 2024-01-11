    // player: 0 for, 1 hound, 2 player, foxOrHoundsTurn: 0 fox, 1 hounds, wantUserInput, should be 1 if you want users to enter a number
    int displayBoard (int board[8][8], int player, int difficulty, int foxOrHoundsTurn, int wantUserInput);

    // Win and lose screens
    //PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win
    void results (int points, int PlayerVSwho, int playerWinVSbot, int playerWinVSplayer);
