    typedef int** Board;
    // VS_Player: 1 if playing VS another player, else 0, foxOrHoundsTurn: 1 if fox, else 0 hounds
    int displayBoard (Board board, int *player, int *difficulty, int foxOrHoundsTurn, int wantUserInput);

    // Win and lose screens
    //PlayerVSwho: 1 - player, 0 - bots | playerWinVSbot: 1 - win, 0 - lose | playerWinVSplayer: 1 - fox win, 0 - hounds win
    void Pwin_loseCLI (int *win, int *lose, int *player);
