//
//  Objects.cpp
//  p2-RPS-c
//
//  Created by Kyle Sun on 12/20/19.
//  Copyright © 2019 Kyle Sun. All rights reserved.
//

#include "Objects.h"

Player::Player() {
    
    a_score = 0;
    
    d_score = 0;
    
    score = 0;
    
}

void Player::inc_a_score() {
    
    a_score++;
    
    cout << name << "'s Attack score increased by 1! New Attack Score: "
    << a_score << endl << endl;
    
}

void Player::inc_d_score() {
    
    d_score++;
    
    cout << name << "'s Defense score increased by 1! New Defense Score: "
    << d_score << endl << endl;
    
}

void Player::clear_scores() {
    
    a_score = 0;
    
    d_score = 0;
    
}

string Player::get_name() {
    
    return name;
    
}

void Player::set_name(string name_in) {
    
    name = name_in;
    
}

void Player::inc_score() {
    
    cout << name << " scored a point!" << endl << endl;
    
    score++;
    
}

int Player::get_a_score() {
    
    return a_score;
    
}

int Player::get_d_score() {
    
    return d_score;
    
}

int Player::get_score() {
    
    return score;
    
}
