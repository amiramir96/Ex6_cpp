#include "leag_scheduale.hpp"
#include <array>
#include <algorithm>
#include <cmath>

namespace im_tired_from_u_ex6
{

std::list<Round> round_robin_algo(TeamRefGroup all_teams)
{   
    /*
    * round-robin algorithm to scheduale round
    * https://en.wikipedia.org/wiki/Round-robin_tournament#Scheduling_algorithm
    */
    std::list<Round> res_rounds;
    std::vector<int> ordered_all_teams_via_curr_round(TEAM_SIZE);
    for (int num=0; num < TEAM_SIZE; num++)
    {
        ordered_all_teams_via_curr_round.at(num) = num;
    }

    for(int i = 0; i < TEAM_SIZE - 1; i++)
    {
        Round round;
        for(int j = 0; j < TEAM_SIZE/2; j++)
        {
            round.all_games.emplace_back(*(all_teams.at(ordered_all_teams_via_curr_round.at(j))),*(all_teams.at(ordered_all_teams_via_curr_round.at(TEAM_SIZE - 1- j))));
            round.all_games.emplace_back(*(all_teams.at(ordered_all_teams_via_curr_round.at(TEAM_SIZE - 1- j))),*(all_teams.at(ordered_all_teams_via_curr_round.at(j))));
        }

        int last = ordered_all_teams_via_curr_round.at(ordered_all_teams_via_curr_round.size() - 1);
        for(int j = ordered_all_teams_via_curr_round.size() - 1; j >= 2 ; j--)
        {
            ordered_all_teams_via_curr_round.at(j) = ordered_all_teams_via_curr_round.at(j-1);
        }
        ordered_all_teams_via_curr_round.at(1) = last;
        res_rounds.push_back(round);
    }

    return res_rounds;

}

void Schedule::update_scheduale(TeamRefGroup all_teams) 
{
    this->all_rounds_sorted = round_robin_algo(all_teams);
}

}