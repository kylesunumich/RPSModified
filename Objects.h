#ifndef Objects_h
#define Objects_h

//
//  Objects.h
//  p2-RPS-c
//
//  Created by Kyle Sun on 12/20/19.
//  Copyright © 2019 Kyle Sun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    
    Player();
    
    void inc_a_score();
    
    void inc_d_score();
    
    void clear_scores();
    
    string get_name();
    
    void set_name(string name_in);
    
    void inc_score();
    
    int get_a_score();
    
    int get_d_score();
    
    int get_score();
    
private:
    
    int a_score;
    int d_score;
    
    string name;
    int score;
    
};

#endif /* Objects_hpp */
