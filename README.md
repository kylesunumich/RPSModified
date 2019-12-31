# RPSModified

This project creates a two-player game of modified Rock Paper Scissors. 
5 files: Objects.h, Objects.cpp, Game.h, Game.cpp, main.cpp
This projects utilizes: functions, classes, recursion, basic input/output

All code is original and written by Kyle Sun

cell: 248-758-0062
email: kylesun@umich.edu
LinkedIn: https://www.linkedin.com/in/kyle-sun-62b407197/

Rules of the Game: (Also found in Game.h)

 Rules of the Game:

 Rock Paper Scissors: Modified is similar to a typical game of Rock Paper Scissors with a couple of twists.
 The game is a 2 player game, each with a normal score and two special scores, an Attack score and a Defense score.
 All scores start at 0. Each player will increase their score for each round won, and their Attack and Defense
 scores may increase depending on what moves are selected by each player. Both players will select a target score
 (between 0 and 10 inclusive) at the beginning of the game, and the first player to reach this score wins!

 There are 6 moves: Rock, Paper, Scissors, Hammer, Rope, and Knife

 Rock...

  Beats:

      Scissors

      Knife

      Hammer: If the player's Defense score is greater than or equal to the opponent's Attack score, the player wins
              the round. If the opponent's Attack score is greater than the player's Defense score but not 2X or more,
              the round is a draw. If the opponent's Attack score is at least 2X the opponent's Defense score, the
              opponent wins the round.

      Rope: If the player's Defense score is greater than the opponent's Defense score. If the player's Defense score
            is less or equal than the opponent's Defense score, the opponent wins the round.

  Ties:

      Opposing Rock

  Loses to:

      Paper




 Paper...

  Beats:

      Rock

  Ties:

      Opposing Paper

      Hammer

  Loses to:

      Scissors

      Rope

      Knife




 Scissors...

  Beats:

      Paper

      Rope: If the opponent's Attack score is greater than the player's Defense score OR the oppenet's Defense score
            is greater than the player's Defense score, the opponent wins the round. If the player's Defense score
            is greater than or equal to the opponent's Attack score AND Defense score, the player wins the round.

      Knife: If the player's Attack score is greater than the opponent's Attack score, then the player wins the round.
             If the player's Attack score is equal to the opponent's Attack score, the round is a draw. If the player's
             Attack score is less than the opponent's Attack score, the opponent wins the round.

  Ties:

      Opposing Scissors

  Loses to:

      Rock

      Hammer




 Hammer...

  Beats:

      Scissors

      Knife

      Rock: If the player's Attack score is at least 2X the opponent's Defense score, the player wins the round. If
            the player's Attack score is greater than the opponent's Defense score but not 2X or more, the round is
            a draw. If the player's Attack score is less than or equal to the opponent's Defense score, the opponent
            wins the round.

      Opposing Hammer: If the player's Attack score is greater than the opponent's Defense score, the player wins
                       the round. If the scores are tied, the round is a tie. If the opponent's Attack score is
                       greater than the player's Attack score, the opponent wins the round.

      Rope: If the player's Attack score is greater than the opponent's Defense score. If the opponent's Defense
            score is greater than or equal to the player's Attack score, the opponent wins.

  Ties: Paper




 Rope...

  Beats:

      Paper

      Rock: If player's Defense score is greater than or equal to the opponent's Defense score, the player wins the
            round. If the player's Defense score is less than the oppoenent's Defense score, the opponent wins the round.

      Scissors: If the player's Attack score OR Defense score is greater than the opponent Defense score, the player
                wins the round. If the player's Attack score AND Defense score are less than the opponent's Defense
                score, the opponent wins the round.

      Hammer: If the player's Defense score is greater than or equal to the opponent's Attack score, the player wins
              the round. If the player's Defense score is less than the opponent's Attack score, the opponent wins the
              round.

      Opposing Rope: If the SUM of the player's Attack score and Defense score is greater than the SUM of the opponent's
                     Attack score and Defense score, the player wins the round. If the SUM of the player's Attack score
                     and Defense score is less than the SUM of the opponent's Attack score and Defense score, the opponent
                     wins the round. If the SUM of the player's Attack score and Defense score is equal to the SUM of the
                     opponent's Attack score and Defense score, the round is a draw.

  Loses to:

      Knife




 Knife...

  Beats:

      Rope

      Paper

      Scissors: If the player's Attack score is greater than the opponent's Attack score, then the player wins the round.
                If the player's Attack score is equal to the opponent's Attack score, the round is a draw. If the player's
                Attack score is less than the opponent's Attack score, the opponent wins the round.

  Ties:

      Opposing Knife

  Loses to:

      Rock

      Hammer


 Incrementing Attack and Defense Scores:

  If the winner of the round played ...

      Rock

      Paper

      Scissors

  ... their Defense score increases by 1


  If the winner of the round played:

      Scissors

      Hammer

      Knife

  ... their Attack score increases by 1


 Enjoy playing Rock Paper Scissors Modified!


