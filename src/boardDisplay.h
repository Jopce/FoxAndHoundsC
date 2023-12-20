    // VS_Player: 1 if playing VS another player, else 0, foxOrHoundsTurn: 1 if fox, else 0 hounds
    int displayBoard (int board[8][8], int VS_Player, int difficulty, int foxOrHoundsTurn);

    // Win and lose screens
    //PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win
    void results (int points, int PlayerVSwho, int playerWinVSbot, int playerWinVSplayer);
