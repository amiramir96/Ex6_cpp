#pragma once

#include <string>
#include <memory>
#include <vector>

namespace im_tired_from_u_ex6
{

class Team {
public:
    std::string team_name;
    double team_skill;

    Team(const std::string& name);
    ~Team(){};

    bool operator==(const Team &other) const;
    const std::string &getName() const
    {return team_name;}
};
using TeamRef = std::shared_ptr<Team>;
using TeamRefGroup = std::vector<TeamRef>;
}