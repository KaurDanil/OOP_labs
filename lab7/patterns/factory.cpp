#include "factory.h"

std::shared_ptr<NPC> NPCFactory::factory(NpcType type, const Point<int> &position)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case NpcType::SlaveTraderType:
        result = std::make_shared<SlaveTrader>(position);
        break;
    case NpcType::WanderingKnightType:
        result = std::make_shared<WanderingKnight>(position);
        break;
    case NpcType::SquirrelType:
        result = std::make_shared<Squirrel>(position);
        break;
    default:
        throw std::invalid_argument("Invalid type");
        break;
    }
    if (result)
    {
        result->subscribe(ScreenObserver::get());
        // result->subscribe(FileObserver::get("log.txt"));
    }
    return result;
}
