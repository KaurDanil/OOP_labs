#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>
#include <vector>
#include <memory>
#include "NPC.hpp"

class Factory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y);
    static std::vector<std::unique_ptr<NPC>> loadNPCsFromFile(const std::string& filename);
    static void saveNPCsToFile(const std::vector<std::unique_ptr<NPC>>& npcList, const std::string& filename);
};

#endif