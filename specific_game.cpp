#include "specific_game.hpp"
#include <random>

#include <iostream>

namespace im_tired_from_u_ex6
{
void Game::play()
{
    if(this->game_completed == false)
    {
        this->home_score = std::rand()/(RAND_MAX / 46) + 55;
        this->guest_score = std::rand()/(RAND_MAX / 51) + 50;
        
        if(this->home_score <= this->guest_score)
        {
            this->winner_team = &this->guest_team;
        }   
        else
        {
            this->winner_team = &this->home_team;
        }
    }
    this->game_completed = true;
}

Team & Game::winner() const {
    if(this->game_completed)
    {
        return *(this->winner_team);
    }
    throw std::runtime_error("the game not completed yet");
}   
}