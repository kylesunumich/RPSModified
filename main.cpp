//
//  main.cpp
//  p2-RPS-c
//
//  Created by Kyle Sun on 12/20/19.
//  Copyright © 2019 Kyle Sun. All rights reserved.
//

#include "Game.h"

// REQUIRES: None
// MODIFIES: cout
// EFFECTS: Prints header to cout

void print_header() {
    
    cout << "-----------------------------" << endl <<
    "ROCK PAPER SCISSORS: MODIFIED" << endl <<
    "-----------------------------" << endl << endl;
    
}

void print_rules() {
    
    cout << "Rules of the Game:" << endl;
    
    cout << "Rock Paper Scissors: Modified is similar to a typical game of Rock Paper Scissors with a couple of twists."
    << endl << "The game is a 2 player game, each with a normal score and two special scores, an Attack score and a Defense score."
    << endl << "All scores start at 0. Each player will increase their score for each round won, and their Attack and Defense"
    << endl << "scores may increase depending on what moves are selected by each player. Both players will select a target score"
    << endl << "(between 0 and 10 inclusive) at the beginning of the game, and the first player to reach this score wins!"
    << endl << endl;
    
    cout << "There are 6 moves: Rock, Paper, Scissors, Hammer, Rope, and Knife" << endl << endl;
    
    cout << "  Rock..." << endl << endl;
    cout << "    Beats:" << endl << endl;
    cout << "        Scissors" << endl << endl
    << "        Knife" << endl << endl
    << "        Hammer: If the player's Defense score is greater than or equal to the opponent's Attack score, the player wins"
    << endl << endl
    << "            the round. If the opponent's Attack score is greater than the player's Defense score but not 2X or more,"
    << endl << endl
    << "            the round is a draw. If the opponent's Attack score is at least 2X the opponent's Defense score, the"
    << endl << endl
    << "            opponent wins the round." << endl
    << "        Rope: If the player's Defense score is greater than the opponent's Defense score. If the player's Defense score"
    << endl << endl
    << "            is less or equal than the opponent's Defense score, the opponent wins the round."
    << endl << endl;
    
    cout << "    Ties:" << endl << endl
    << "        Opposing Rock" << endl << endl;
    cout << "    Loses to:" << endl << endl
    << "        Paper" << endl << endl;
    
    cout << "  Paper..." << endl << endl;
    cout << "    Beats:" << endl << endl;
    cout << "        Rock" << endl << endl;
    
    cout << "    Ties:" << endl << endl;
    cout << "        Opposing Paper"
    << endl << endl
    << "        Hammer"
    << endl << endl;
    
    cout << "    Loses to:" << endl << endl;
    cout << "        Scissors"
    << endl << endl
    << "        Rope"
    << endl << endl
    << "        Knife"
    << endl << endl;
    
    
    
    
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
    
    
}

// REQUIRES: player_num is 1 or 2
// MODIFIES: cin, cout
// EFFECTS: returns string name and prints statement to cout

string get_player_name(int player_num) {
    
    cout << "Player " << player_num << ", please enter your name: ";
    
    string name;
    
    getline(cin, name);
    
    cout << endl;
    
    cout << "Player " << player_num << " is " << name << endl << endl;
    
    return name;
    
}

// REQUIRES: win_score is an integer
// MODIFIES: None
// EFFECTS: returns 0 if win_score is between 1 and 10 inclusive, -1 otherwise

int score_check(int win_score) {
    
    if (win_score >= 1 && win_score <= 10) {
        
        return 0;
        
    }
    
    else {
        
        cout << "Invalid score. Please try again." << endl << endl;
        
        return -1;
        
    }
    
}

// REQUIRES: None
// MODIFIES: cin, cout
// EFFECTS: prompts user to enter win_score. Checks if win_score is valid,
//          then returns win_score. If win_score is not valid, prompts the user again

int get_win_score() {
    
    cout << "Please enter a target score between 1 and 10: ";
    
    int win_score;
    
    cin >> win_score;
    
//    int check;
//    
//    check = score_check(win_score);
//
//    if (check == -1) {
//
//        check = get_win_score();
//
//    }
    
    // cout << "The first player to reach this score wins the Game!" << endl << endl;
    
    return win_score;
    
}

// Run Game

int main() {
    
    print_header();
    
    string name_1 = get_player_name(1);
    string name_2 = get_player_name(2);
    
    int win_score = get_win_score();
    
    while (score_check(win_score) == -1) {
        
        win_score = get_win_score();
        
    }
    
    cout << "The first player to reach this score wins the Game!" << endl << endl;
    
    Game RPS(name_1, name_2);
    
    while (RPS.end_game(RPS.get_player(1),
                        RPS.get_player(2), win_score) != true) {
        
        RPS.play_round(RPS.get_player(1), RPS.get_player(2));
        
    }
    
    RPS.print_end(RPS.find_winner(win_score));
    
    RPS.print_end_2();
 
    return 0;
    
}
