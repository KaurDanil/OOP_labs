#include "../include/Factory.hpp"
#include "../include/SlaveTrader.hpp"
#include "../include/Squirrel.hpp"
#include "../include/WanderingKnight.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::unique_ptr<NPC> Factory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "SlaveTrader") {
        return std::make_unique<SlaveTrader>(name, x, y);
    } else if (type == "Squirrel") {
        return std::make_unique<Squirrel>(name, x, y);
    } else if (type == "WanderingKnight") {
        return std::make_unique<WanderingKnight>(name, x, y);
    }
    return nullptr;
}

std::vector<std::unique_ptr<NPC>> Factory::loadNPCsFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<NPC>> npcList;
    std::ifstream infile(filename);
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::string type, name, xStr, yStr;
            if (iss >> type >> name >> xStr >> yStr) {
                int x = std::stoi(xStr);
                int y = std::stoi(yStr);
                auto npc = createNPC(type, name, x, y);
                if (npc) {
                    npcList.push_back(std::move(npc));
                }
            }
        }
        infile.close();
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
    return npcList;
}

void Factory::saveNPCsToFile(const std::vector<std::unique_ptr<NPC>>& npcList, const std::string& filename) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& npc : npcList) {
            outfile << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
        }
        outfile.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}