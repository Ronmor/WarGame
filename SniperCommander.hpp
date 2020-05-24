#include "Sniper.hpp"

namespace WarGame
{

    class SniperCommander : public WarGame::Sniper
    {
    private:
        /* data */
    public:
        SniperCommander(uint team);
        ~SniperCommander();
        virtual void act(Soldier *target) override;
        virtual void heal() override;
        virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&) override;
    };

} // namespace WarGame