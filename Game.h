#ifndef Game_h
#define Game_h

//
//  Game.h
//  p2-RPS-c
//
//  Created by Kyle Sun on 12/20/19.
//  Copyright © 2019 Kyle Sun. All rights reserved.
//

// Rules of the Game:
//
// Rock Paper Scissors: Modified is similar to a typical game of Rock Paper Scissors with a couple of twists.
// The game is a 2 player game, each with a normal score and two special scores, an Attack score and a Defense score.
// All scores start at 0. Each player will increase their score for each round won, and their Attack and Defense
// scores may increase depending on what moves are selected by each player. Both players will select a target score
// (between 0 and 10 inclusive) at the beginning of the game, and the first player to reach this score wins!
//
// There are 6 moves: Rock, Paper, Scissors, Hammer, Rope, and Knife
//
// Rock...
//
//  Beats:
//
//      Scissors
//
//      Knife
//
//      Hammer: If the player's Defense score is greater than or equal to the opponent's Attack score, the player wins
//              the round. If the opponent's Attack score is greater than the player's Defense score but not 2X or more,
//              the round is a draw. If the opponent's Attack score is at least 2X the opponent's Defense score, the
//              opponent wins the round.
//
//      Rope: If the player's Defense score is greater than the opponent's Defense score. If the player's Defense score
//            is less or equal than the opponent's Defense score, the opponent wins the round.
//
//  Ties:
//
//      Opposing Rock
//
//  Loses to:
//
//      Paper
//
//
//
//
// Paper...
//
//  Beats:
//
//      Rock
//
//  Ties:
//
//      Opposing Paper
//
//      Hammer
//
//  Loses to:
//
//      Scissors
//
//      Rope
//
//      Knife
//
//
//
//
// Scissors...
//
//  Beats:
//
//      Paper
//
//      Rope: If the opponent's Attack score is greater than the player's Defense score OR the oppenet's Defense score
//            is greater than the player's Defense score, the opponent wins the round. If the player's Defense score
//            is greater than or equal to the opponent's Attack score AND Defense score, the player wins the round.
//
//      Knife: If the player's Attack score is greater than the opponent's Attack score, then the player wins the round.
//             If the player's Attack score is equal to the opponent's Attack score, the round is a draw. If the player's
//             Attack score is less than the opponent's Attack score, the opponent wins the round.
//
//  Ties:
//
//      Opposing Scissors
//
//  Loses to:
//
//      Rock
//
//      Hammer
//
//
//
//
// Hammer...
//
//  Beats:
//
//      Scissors
//
//      Knife
//
//      Rock: If the player's Attack score is at least 2X the opponent's Defense score, the player wins the round. If
//            the player's Attack score is greater than the opponent's Defense score but not 2X or more, the round is
//            a draw. If the player's Attack score is less than or equal to the opponent's Defense score, the opponent
//            wins the round.
//
//      Opposing Hammer: If the player's Attack score is greater than the opponent's Defense score, the player wins
//                       the round. If the scores are tied, the round is a tie. If the opponent's Attack score is
//                       greater than the player's Attack score, the opponent wins the round.
//
//      Rope: If the player's Attack score is greater than the opponent's Defense score. If the opponent's Defense
//            score is greater than or equal to the player's Attack score, the opponent wins.
//
//  Ties: Paper
//
//
//
//
// Rope...
//
//  Beats:
//
//      Paper
//
//      Rock: If player's Defense score is greater than or equal to the opponent's Defense score, the player wins the
//            round. If the player's Defense score is less than the oppoenent's Defense score, the opponent wins the round.
//
//      Scissors: If the player's Attack score OR Defense score is greater than the opponent Defense score, the player
//                wins the round. If the player's Attack score AND Defense score are less than the opponent's Defense
//                score, the opponent wins the round.
//
//      Hammer: If the player's Defense score is greater than or equal to the opponent's Attack score, the player wins
//              the round. If the player's Defense score is less than the opponent's Attack score, the opponent wins the
//              round.
//
//      Opposing Rope: If the SUM of the player's Attack score and Defense score is greater than the SUM of the opponent's
//                     Attack score and Defense score, the player wins the round. If the SUM of the player's Attack score
//                     and Defense score is less than the SUM of the opponent's Attack score and Defense score, the opponent
//                     wins the round. If the SUM of the player's Attack score and Defense score is equal to the SUM of the
//                     opponent's Attack score and Defense score, the round is a draw.
//
//  Loses to:
//
//      Knife
//
//
//
//
// Knife...
//
//  Beats:
//
//      Rope
//
//      Paper
//
//      Scissors: If the player's Attack score is greater than the opponent's Attack score, then the player wins the round.
//                If the player's Attack score is equal to the opponent's Attack score, the round is a draw. If the player's
//                Attack score is less than the opponent's Attack score, the opponent wins the round.
//
//  Ties:
//
//      Opposing Knife
//
//  Loses to:
//
//      Rock
//
//      Hammer
//
//
// Incrementing Attack and Defense Scores:
//
//  If the winner of the round played ...
//
//      Rock
//
//      Paper
//
//      Scissors
//
//  ... their Defense score increases by 1
//
//
//  If the winner of the round played:
//
//      Scissors
//
//      Hammer
//
//      Knife
//
//  ... their Attack score increases by 1
//
//
// Enjoy playing Rock Paper Scissors Modified!
//

#include "Objects.h"

class Game {
public:
    
    // REQUIRES: p1_name and p2_name are valid strings
    // MODIFIES: None
    // EFFECTS: Creates game, sets round to 1, initializes two players p1 and p2
    //          and set names to p1_name and p2_name, adds p1 and p2 to Players
    //          array players[]
    
    Game(string p1_name, string p2_name); // Game Constructor
    
    // REQUIRES:
    // MODIFIES:
    // EFFECTS: Prints out prompt for user, checks user input.
    //          If valid, return input, otherwise prompts user again
    
    int get_prompt(Player &p_in);
    
    // Return -1 if input invalid; any positive integer otherwise
    
    // REQUIRES: input is an integer
    // MODIFIES: None
    // EFFECTS: Returns 0 input is between 1 and 6 inclusive, returns -1 otherwise
    
    int input_check(int input);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: plays a round of RPS, prints out the appropriate outcome,
    //          increments scores accordingly, and increments round
    
    void play_round(Player &p1, Player &p2);
    
    // REQUIRES: winner is either 1 or 2
    // MODIFIES: cout
    // EFFECTS: Prints out the winner of the game
    
    void print_end(int winner);
    
    // REQUIRES: move_1 and move_2 are valid (bewteen 1 and 6 inclusive)
    // MODIFIES: p1, p2
    // EFFECTS: calls the appropraite function based on move_1
    
    int winning_move(Player &p1, int move_1, Player &p2, int move_2);
    
    // REQUIRES: None
    // MODIFIES: cout
    // EFFECTS: prints out winner of the round, winning move and losing move
    
    void print_round_winner(Player &round_winner, int win_move, int lose_move);
    
    // REQUIRES: None
    // MODIFIES: cout
    // EFFECTS: Declares the round a draw and prints scores
    
    void print_draw();
    
    // REQUIRES: None
    // MODIFIES: cout
    // EFFECTS: Prints round number
    
    void print_round();
    
    // REQUIRES: None
    // MODIFIES: winner
    // EFFECTS: Calls appropriate functions to print round winner,
    //          increment winner score, print scores of both players,
    //          and increment round
    
    void winner(Player &winner, int win_move, int lose_move);
    
    // REQUIRES: None
    // MODIFIES: round
    // EFFECTS: Calls appropriate function to print draw and increment round
    
    void draw();
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on rock and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_rock(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on paper and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_paper(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on scissors and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_scissors(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on hammer and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_hammer(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on rope and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_rope(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: p1, p2
    // EFFECTS: calls appropriate functions based on knife and p2_move,
    //          calls appropriate functions to increment scores when
    //          necessary, and returns winner of the round
    
    int p1_knife(Player &p1, Player &p2, int p2_move);
    
    // REQUIRES: None
    // MODIFIES: cout
    // EFFECTS: Prints scores of each player
    
    void print_scores(Player &p1, Player &p2);
    
    // REQUIRES: move is between 1 and 6 inclusive
    // MODIFIES: None
    // EFFECTS: Returns string corresponding to move
    
    string print_helper(int move);
    
    // REQUIRES: None
    // MODIFIES: None
    // EFFECTS: Returns true if either player has reached win_score, returns false otherwise
    
    bool end_game(Player &p1, Player &p2, int win_score);
    
    // REQUIRES: player is either 1 or 2
    // MODIFIES: None
    // EFFECTS: Returns p1 or p2 based on player
    
    Player& get_player(int player);
    
    // REQUIRES: None
    // MODIFIES: cout
    // EFFECTS: Prints ending
    
    void print_end_2();
    
    // REQUIRES: p1 or p2 has a score of win_score
    // MODIFIES: None
    // EFFECTS: Returns 1 if p1 has a score of win_score, 2 if p2 has a score of win_score
    
    int find_winner(int win_score);
    
private:
    
    int round;
    
    Player players[2];
    
};

#endif
