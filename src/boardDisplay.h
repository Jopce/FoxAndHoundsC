    // player: 0 for, 1 hound, 2 player, foxOrHoundsTurn: 0 fox, 1 hounds, wantUserInput, should be 1 if you want users to enter a number
    int displayBoard (int board[8][8], int player, int difficulty, int foxOrHoundsTurn, int wantUserInput);

    // determines who Won or lost the game
    void Pwin_loseCLI (int *win, int *lose, int *player, int points) //logic from StarcClans Pwin_lose()
