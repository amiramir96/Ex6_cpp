#pragma once
#include "Team.hpp"
namespace im_tired_from_u_ex6
{
    class Game
    {
    public:
        Team& home_team;
        Team& guest_team;
        Team* winner_team;
        int home_score;
        int guest_score;
        bool game_completed;

        Game(Team& a, Team& b) : home_team{a}, guest_team{b} , winner_team{nullptr}, game_completed{false} {};
        ~Game() = default;

        void play();
        Team & winner() const;
    };
}