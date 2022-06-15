#pragma once
#include <list>
#include "specific_game.hpp"

#define TEAM_SIZE 20

namespace im_tired_from_u_ex6
{
class Round
{
    public:
        Round(){};
        ~Round(){};
        std::list<Game> all_games;
        std::list<Game>::iterator begin(){return all_games.begin();}
        std::list<Game>::iterator end(){return all_games.end();}
};

class Schedule
{
public:
    std::list<Round> all_rounds_sorted;

    Schedule(){};
    ~Schedule(){};

    void update_scheduale(TeamRefGroup);
    std::list<Round>::iterator begin(){return all_rounds_sorted.begin();}
    std::list<Round>::iterator end(){return all_rounds_sorted.end();}
};
}