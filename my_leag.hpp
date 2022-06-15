#pragma once
#include "Team.hpp"
#include "leag_scheduale.hpp"
namespace im_tired_from_u_ex6
{
    class Leauge
    {
    public:
        TeamRefGroup lig_teams;
        Schedule schedule;

        Leauge(TeamRefGroup);
        ~Leauge(){};

        void run_season();

        void print_teams_via_winlose(){};
        void print_teams_via_points(){};

        TeamRefGroup get_teams() {return lig_teams;}
        Schedule get_schedule() {return schedule;}
    };
}