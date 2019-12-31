//
//  Game.cpp
//  p2-RPS-c
//
//  Created by Kyle Sun on 12/20/19.
//  Copyright © 2019 Kyle Sun. All rights reserved.
//

#include "Game.h"

Game::Game(string p1_name, string p2_name) { 
    
    round = 1;
    
    Player p1;
    
    Player p2;
    
    p1.set_name(p1_name);
    
    p2.set_name(p2_name);
    
    players[0] = p1;
    
    players[1] = p2;
    
}

int Game::input_check(int input) {
    
    if (input >= 1 && input <= 6 ) {
        
        return 0;
        
    }
    
    else {
        
        cout << "Invalid input. Please try again." << endl << endl;
        
        return -1;
        
    }
    
}

int Game::get_prompt(Player &p_in) {

    cout << p_in.get_name() << ", your Attack score is: " <<
    p_in.get_a_score() << " and your Defense score is: " <<
    p_in.get_d_score() << endl << "Please enter a move:" << endl <<
    endl << "[1]: Rock" << endl << "[2]: Paper" <<
    endl << "[3]: Scissors" << endl << "[4]: Hammer" <<
    endl << "[5]: Rope" << endl << "[6]: Knife" << endl << "Move: ";
    
    int prompt;
    
    cin >> prompt;
    
    cout << endl;
    
    int check;
    
    check = input_check(prompt);
    
    if (check == -1) {
        
        prompt = get_prompt(p_in);
        
    }
    
    return prompt;
    
}

void Game::print_end(int winner) {
    
    cout << players[winner - 1].get_name() << " Wins! Thanks for playing!" << endl;
    
    return;
    
}

void Game::play_round(Player &p1, Player &p2) {
    
    print_round();
    
    int p1_move = get_prompt(p1);
    
    int p2_move = get_prompt(p2);
    
    winning_move(p1, p1_move, p2, p2_move);
    
}

int Game::winning_move(Player &p1, int move_1, Player &p2, int move_2) {
    
    if (move_1 == 1) {
        
        return p1_rock(p1, p2, move_2);
        
    }
    
    else if (move_1 == 2) {
        
        return p1_paper(p1, p2, move_2);
        
    }
    
    else if (move_1 == 3) {
        
        return p1_scissors(p1, p2, move_2);
        
    }
    
    else if (move_1 == 4) {
        
        return p1_hammer(p1, p2, move_2);
        
    }
    
    else if (move_1 == 5) {
        
        return p1_rope(p1, p2, move_2);
        
    }
    
    else { // move_1 == 6
        
        return p1_knife(p1, p2, move_2);
        
    }
    
}

int Game::p1_rock(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        draw();
        
        return 0;
        
    }
    
    else if (p2_move == 2) {
        
        winner(p2, p2_move, 1);
        
        p2.inc_d_score();
        
        return 2;
        
    }
    
    else if (p2_move == 3) {
        
        winner(p1, 1, p2_move);
        
        p1.inc_a_score();
        
        p1.inc_d_score();
        
        return 1;
        
    }
    
    else if (p2_move == 4) {
        
        if (p2.get_a_score() >= 2 * p1.get_d_score()) {
            
            winner(p2, p2_move, 1);
            
            p2.inc_a_score();
            
            return 2;
            
        }
        
        else if (p2.get_a_score() > p1.get_d_score()) {
            
            draw();
            
            return 0;
            
        }
        
        else { // p2 a score <= p1 d score
            
            winner(p1, 1, p2_move);
            
            p1.inc_d_score();
            
            return 1;
            
        }
        
    }
    
    else if (p2_move == 5) {
        
        if (p2.get_d_score() > p1.get_d_score()) {
            
            winner(p2, p2_move, 1);
            
            return 2;
            
        }
        
        else {
            
            winner(p1, 1, p2_move);
            
            p1.inc_d_score();
            
            return 1;
            
        }
        
    }
    
    else { // move_2 == 6
        
        winner(p1, 1, p2_move);
        
        p1.inc_d_score();
        
        return 1;
        
    }
    
}

int Game::p1_paper(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        winner(p1, 2, p2_move);
        
        p1.inc_d_score();
        
        return 1;
        
    }
    
    else if (p2_move == 2) {
        
        draw();
        
        return 0;
        
    }
    
    else if (p2_move == 3) {
        
        winner(p2, p2_move, 2);
        
        p2.inc_a_score();
        
        p2.inc_d_score();
        
        return 2;
        
    }
    
    else if (p2_move == 4) {
        
        draw();
        
        return 0;
        
    }
    
    else if (p2_move == 5) {
        
        winner(p2, p2_move, 2);
        
        return 2;
        
    }
    
    else { // p2_move == 6
        
        winner(p2, p2_move, 2);
        
        p2.inc_a_score();
        
        return 2;
        
    }
    
}

int Game::p1_scissors(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        winner(p2, p2_move, 3);
        
        p1.inc_d_score();
        
        return 1;
        
    }
    
    else if (p2_move == 2) {
        
        winner (p1, 3, p2_move);
        
        p1.inc_a_score();
        
        p1.inc_d_score();
        
        return 1;
        
    }
    
    else if (p2_move == 3) {
        
        draw();
        
        return 0;
        
    }
    
    else if (p2_move == 4) {
        
        winner(p2, p2_move, 3);
        
        p2.inc_a_score();
        
        return 2;
        
    }
    
    else if (p2_move == 5) {
        
        if ((p2.get_a_score() > p1.get_d_score()) ||
            (p2.get_d_score() > p1.get_d_score())) {
            
            winner(p2, p2_move, 3);
            
            return 2;
            
        }
        
        else {
            
            winner(p1, 3, p2_move);
            
            p1.inc_a_score();
            
            p1.inc_d_score();
            
            return 1;
            
        }
        
    }
    
    else { // p2_move == 6
        
        if (p2.get_a_score() > p1.get_a_score()) {
            
            winner(p2, p2_move, 3);
            
            return 2;
            
        }
        
        else if (p2.get_a_score() == p1.get_a_score()) {
            
            draw();
            
            return 0;
            
        }
        
        else {
            
            winner(p1, 3, p2_move);
            
            return 1;
            
        }
        
    }
    
}

int Game::p1_hammer(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        if (p1.get_a_score() >= 2 * p2.get_d_score()) {
            
            winner(p1, 4, p2_move);
            
            p1.inc_a_score();
            
            return 1;
            
        }
        
        else if (p1.get_a_score() > p2.get_d_score()) {
            
            draw();
            
            return 0;
            
        }
        
        else { // p1 a_score <= p2 d_score
            
            winner(p2, p2_move, 4);
            
            p2.inc_d_score();
            
            return 2;
            
        }
        
    }
    
    else if (p2_move == 2) {
        
        draw();
        
        return 0;
        
    }
    
    else if (p2_move == 3) {
        
        winner(p1, 4, p2_move);
        
        p1.inc_a_score();
        
        return 1;
        
    }
    
    else if (p2_move == 4) {
        
        if (p1.get_a_score() > p2.get_d_score()) {
            
            winner(p1, 4, p2_move);
            
            p1.inc_a_score();
            
            return 1;
            
        }
        
        else { // p1 a_score <= p2 d_score
            
            winner(p2, p2_move, 4);
            
            p2.inc_a_score();
            
            return 2;
            
        }
        
    }
    
    else if (p2_move == 5) {
        
        if (p1.get_a_score() > p2.get_d_score()) {
            
            winner(p1, 4, p2_move);
            
            p1.inc_a_score();
            
            return 1;
            
        }
        
        else { // p1 a_score <= p2 d_score
            
            winner(p2, p2_move, 4);
            
            return 2;
            
        }
        
    }
    
    else { // p2_move == 6
        
        winner(p1, 4, p2_move);
        
        p1.inc_a_score();
        
        return 1;
        
    }
}

int Game::p1_rope(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        if (p1.get_d_score() > p2.get_d_score()) {
            
            winner(p1, 5, p2_move);
            
            return 1;
            
        }
        
        else { // p1 d_score <= p2 d_score
            
            winner(p2, p2_move, 5);
            
            p2.inc_d_score();
            
            return 2;
            
        }
        
    }
    
    else if (p2_move == 2) {
        
        winner(p1, 5, p2_move);
        
        return 1;
        
    }
    
    else if (p2_move == 3) {
        
        if ((p1.get_a_score() > p2.get_d_score()) ||
            (p1.get_d_score() > p2.get_d_score())) {
            
            winner(p1, 5, p2_move);
            
            return 1;
            
        }
        
        else {
            
            winner(p2, p2_move, 5);
            
            p2.inc_a_score();
            
            p2.inc_d_score();
            
            return 2;

        }
        
    }
    
    else if (p2_move == 4) {
        
        if (p1.get_d_score() >= p2.get_a_score()) {
            
            winner(p1, 5, p2_move);
            
            return 1;
            
        }
        
        else {
            
            winner(p2, p2_move, 5);
            
            p2.inc_a_score();
            
            return 2;
            
        }
        
    }
    
    else if (p2_move == 5) {
        
        if ((p1.get_a_score() + p2.get_d_score()) > (p2.get_a_score() + p2.get_d_score())) {
            
            winner(p1, 5, p2_move);
            
            return 1;
            
        }
        
        else if ((p1.get_a_score() + p2.get_d_score()) < (p2.get_a_score() + p2.get_d_score())) {
            
            winner(p2, p2_move, 5);
            
            return 2;
            
        }
        
        else { // tie
            
            draw();
            
            return 0;
            
        }
        
    }
    
    else { // p2_move == 6
        
        winner(p2, p2_move, 5);
        
        p2.inc_a_score();
        
        return 2;
        
    }
    
}

int Game::p1_knife(Player &p1, Player &p2, int p2_move) {
    
    if (p2_move == 1) {
        
        winner(p2, p2_move, 6);
        
        p2.inc_d_score();
        
        return 2;
        
    }
    
    else if (p2_move == 2) {
        
        winner(p1, 6, p2_move);
        
        p1.inc_a_score();
        
        return 1;
        
    }
    
    else if (p2_move == 3) {
        
        if (p1.get_a_score() > p2.get_a_score()) {
            
            winner(p1, 6, p2_move);
            
            p1.inc_a_score();
            
            return 1;
            
        }
        
        else  if (p1.get_a_score() == p2.get_a_score()) {
            
            draw();
            
            return 0;
            
        }
        
        else { // p1 a_score < p2 d_score
            
            winner(p2, p2_move, 6);
            
            p2.inc_a_score();
            
            p2.inc_d_score();
            
            return 2;
            
        }
        
    }
    
    else if (p2_move == 4) {
        
        winner(p2, p2_move, 6);
        
        p2.inc_a_score();
        
        return 2;
        
    }
    
    else if (p2_move == 5) {
        
        winner(p1, 6, p2_move);
        
        p1.inc_a_score();
        
        return 1;
        
    }
    
    else { // p2_move == 6
        
        draw();
        
        return 0;
        
    }
    
}

void Game::winner(Player &winner, int win_move, int lose_move) {
    
    print_round_winner(winner, win_move, lose_move);
    
    winner.inc_score();
    
    print_scores(players[0], players[1]);
    
    round++;
    
}

void Game::draw() {
    
    print_draw();
    
    round++;
    
}

void Game::print_draw() {
    
    cout << "Round " << round << " is a draw!" << endl;
    
    print_scores(players[0], players[1]);
    
}

void Game::print_round_winner(Player &round_winner, int win_move, int lose_move) {
    
    cout << print_helper(win_move) << " beats " <<
    print_helper(lose_move) << "!" << endl << round_winner.get_name()
    << " wins Round " << round << "!" << endl;
    
}

void Game::print_round() {
    
    cout << "Round " << round << endl << endl;
    
}

void Game::print_scores(Player &p1, Player &p2) {
    
    cout << "Score: " << p1.get_name() << ": "
    << p1.get_score() << ", " << p2.get_name()
    << ": " << p2.get_score() << endl << endl;
    
}

string Game::print_helper(int move) {
    
    // move between 1 and 6 (inclusive)
    
    if (move == 1) {
        
        return "Rock";
        
    }
    
    else if (move == 2) {
        
        return "Paper";
        
    }
    
    else if (move == 3) {
        
        return "Scissors";
        
    }
    
    else if (move == 4) {
        
        return "Hammer";
        
    }
    
    else if (move == 5) {
        
        return "Rope";
        
    }
    
    else { // move == 6
        
        return "Knife";
        
    }
    
}

bool Game::end_game(Player &p1, Player &p2, int win_score) {
    
    if ((p1.get_score() == win_score) || (p2.get_score() == win_score)) {
        
        return true;
        
    }
    
    else {
        
        return false;
        
    }
    
}

void Game::print_end_2() {
    
    cout << "---------------------" << endl <<
    "      GAME OVER" << endl <<
    "---------------------" << endl << endl <<
    "Game created by Kyle Sun" << endl
    << endl << "Email : kylesun@umich.edu" << endl <<
    "linkedIn URL: https://www.linkedin.com/in/kyle-sun-62b407197/" << endl << "GitHub: kylesunumich" << endl << endl;
    
}

// Returns player by reference,
// Issues for passing by value?

Player& Game::get_player(int player) { // player either 1 of 2
    
    return players[player - 1];
    
}

int Game::find_winner(int win_score) {
    
    if (players[0].get_score() == win_score) {
        
        return 1;
        
    }
    
    else {
        
        return 2;
        
    }
    
}

