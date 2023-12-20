    // isPlayer: 1 if playing VS another player, else 0, foxOrHoundsTurn: 1 if fox, else 0
    void displayBoard (int board[8][8], int isPlayer, int difficulty, int sidePannelOn, int foxOrHoundsTurn);

    //text[]: text what will be displayed
    void infoBox (char text[]);

    // Win and lose screens
    void BOTwinScreen(int points);
    void BOTloseScreen(int points);
    void PlayerOneWinScreen(int points);
    void PlayerTwoWinScreen(int points);
