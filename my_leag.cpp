#include "my_leag.hpp"
#include <algorithm>
#include <iostream>

namespace im_tired_from_u_ex6{

Leauge::Leauge(TeamRefGroup teams) : lig_teams{teams}, schedule{} {
    if(teams.size() > 20)
    {
        throw "to many teams";
    }
    while (this->lig_teams.size() < TEAM_SIZE) {
        int serial_num = lig_teams.size();
        bool available = false;
        while (available == false) {
            available = true;
            for (auto &team : this->lig_teams)
            {
                std::string temp = std::to_string(serial_num);
                if(team.get()->getName() == "Team" + temp)
                {
                    available = false;
                }
            }
        }
        this->lig_teams.push_back(std::make_shared<Team>("Team" + std::to_string(serial_num)));
    }
    schedule.update_scheduale(lig_teams);
}

void Leauge::run_season() {
    for (Round &round_of_games: this->schedule) {
        for (Game &specific_game: round_of_games) {
            specific_game.play();
        }
    }
}
}