#include <iostream>
#include <vector>
#include <memory>
#include "include/Factory.hpp"
#include "include/CombatVisitor.hpp"
#include "include/FileLogger.hpp"
#include "include/ConsoleLogger.hpp"

int main() {
    std::vector<std::unique_ptr<NPC>> npcList;

    int choice;
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add NPC\n";
        std::cout << "2. Save NPCs to file\n";
        std::cout << "3. Load NPCs from file\n";
        std::cout << "4. List NPCs\n";
        std::cout << "5. Enter combat mode\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string type, name;
                int x, y;
                std::cout << "Enter NPC type (SlaveTrader, Squirrel, WanderingKnight): ";
                std::cin >> type;
                std::cout << "Enter NPC name: ";
                std::cin >> name;
                std::cout << "Enter coordinates x and y: ";
                std::cin >> x >> y;
                auto npc = Factory::createNPC(type, name, x, y);
                if (npc) {
                    npcList.push_back(std::move(npc));
                } else {
                    std::cout << "Invalid NPC type.\n";
                }
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                Factory::saveNPCsToFile(npcList, filename);
                break;
            }
            case 3: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                npcList = Factory::loadNPCsFromFile(filename);
                break;
            }
            case 4: {
                for (const auto& npc : npcList) {
                    std::cout << "Type: " << npc->getType() << ", Name: " << npc->getName()
                              << ", Coordinates: (" << npc->getX() << ", " << npc->getY() << ")\n";
                }
                break;
            }
            case 5: {
                int combatRange;
                std::cout << "Enter combat range: ";
                std::cin >> combatRange;
                CombatVisitor visitor(combatRange, npcList); // Pass both parameters

                FileLogger fileLogger;
                ConsoleLogger consoleLogger;
                visitor.attach(&fileLogger);
                visitor.attach(&consoleLogger);

                visitor.performCombat();

                visitor.detach(&fileLogger);
                visitor.detach(&consoleLogger);
                break;
            }
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}