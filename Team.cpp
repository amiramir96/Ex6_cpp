#include "Team.hpp"


namespace im_tired_from_u_ex6
{
Team::Team(const std::string& name) : team_name{name} {
    if(this->team_name.empty())
    {
        throw std::runtime_error("must be something..");
    }
}

bool Team::operator==(const Team &other) const
{
    bool name_param = this->team_name == other.team_name;
    return  name_param;
}

}