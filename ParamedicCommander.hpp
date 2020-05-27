#include "Paramedic.hpp"

namespace WarGame
{

    class ParamedicCommander : public WarGame::Paramedic
    {
    private:
        /* data */
    public:
        ParamedicCommander(uint team);
        ~ParamedicCommander();
        virtual void act(Soldier *target) override;
        virtual void heal() override;
        virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&,std::map<Soldier*,std::pair<int, int>>&) override;
    };

} // namespace WarGame