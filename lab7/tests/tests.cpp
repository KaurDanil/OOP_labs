#include <gtest/gtest.h>
#include "../npc/npc.h"
#include "../npc/slaveTrader.h"
#include "../npc/squirrel.h"
#include "../npc/wanderingKnight.h"
#include "../patterns/visitor.h"
#include "../patterns/factory.h"
#include <memory>

TEST(NPCFactoryTest, CreateKnightAtMaxBounds)
{
    auto knight = NPCFactory::factory(WanderingKnightType, {100, 100});
    EXPECT_EQ(knight->get_type(), WanderingKnightType);
    EXPECT_EQ(knight->position.x_, 100);
    EXPECT_EQ(knight->position.y_, 100);
}

TEST(NPCMoveTest, KnightDiagonalMovement)
{
    auto knight = NPCFactory::factory(WanderingKnightType, {10, 10});
    knight->move(1, -1, 100, 100);
    EXPECT_EQ(knight->position.x_, 40);
    EXPECT_EQ(knight->position.y_, 0);
}

TEST(NPCMoveTest, TraderMoveWithinBounds)
{
    auto trader = NPCFactory::factory(SlaveTraderType, {10, 10});
    trader->move(3, 2, 50, 50);
    EXPECT_EQ(trader->position.x_, 40);
    EXPECT_EQ(trader->position.y_, 30);
}

TEST(NPCMoveTest, SquirrelStaysInBounds)
{
    auto squirrel = NPCFactory::factory(SquirrelType, {98, 98});
    squirrel->move(1, 1, 100, 100);
    EXPECT_EQ(squirrel->position.x_, 100);
    EXPECT_EQ(squirrel->position.y_, 100);
}

TEST(NPCInteractionTest, TraderFailsToKillKnightTooFar)
{
    auto knight = NPCFactory::factory(WanderingKnightType, {10, 10});
    auto trader = NPCFactory::factory(SlaveTraderType, {50, 50});
    FightVisitor visitor;
    EXPECT_FALSE(trader->accept(visitor, *knight));
}

TEST(NPCInteractionTest, SquirrelFailsToKillKnightTooFar)
{
    auto knight = NPCFactory::factory(WanderingKnightType, {10, 10});
    auto squirrel = NPCFactory::factory(SquirrelType, {50, 50});
    FightVisitor visitor;
    EXPECT_FALSE(knight->accept(visitor, *squirrel));
}

TEST(NPCInteractionTest, TwoTradersNoFight)
{
    auto trader1 = NPCFactory::factory(SlaveTraderType, {30, 30});
    auto trader2 = NPCFactory::factory(SlaveTraderType, {31, 30});
    FightVisitor visitor;
    EXPECT_FALSE(trader1->accept(visitor, *trader2));
    EXPECT_FALSE(trader2->accept(visitor, *trader1));
}

TEST(NPCInteractionTest, SquirrelKillsTraderInBounds)
{
    auto trader = NPCFactory::factory(SlaveTraderType, {20, 20});
    auto squirrel = NPCFactory::factory(SquirrelType, {20, 21});
    FightVisitor visitor;
    EXPECT_TRUE(trader->accept(visitor, *squirrel));
}

TEST(NPCInteractionTest, TraderFailsToKillSquirrelOutOfBounds)
{
    auto trader = NPCFactory::factory(SlaveTraderType, {90, 90});
    auto squirrel = NPCFactory::factory(SquirrelType, {10, 10});
    FightVisitor visitor;
    EXPECT_FALSE(squirrel->accept(visitor, *trader));
}

TEST(NPCMoveTest, MultipleNPCsMovingSimultaneously)
{
    auto knight = NPCFactory::factory(WanderingKnightType, {10, 10});
    auto trader = NPCFactory::factory(SlaveTraderType, {20, 20});
    auto squirrel = NPCFactory::factory(SquirrelType, {30, 30});
    knight->move(1, 1, 100, 100);
    trader->move(-1, -1, 100, 100);
    squirrel->move(0, 1, 100, 100);
    EXPECT_EQ(knight->position.x_, 40);
    EXPECT_EQ(knight->position.y_, 40);
    EXPECT_EQ(trader->position.x_, 10);
    EXPECT_EQ(trader->position.y_, 10);
    EXPECT_EQ(squirrel->position.x_, 30);
    EXPECT_EQ(squirrel->position.y_, 35);
}
