#include <gtest/gtest.h>
#include "../include/FixedBlockMemoryResource.h"
#include "../include/PmrList.h"
#include <string>

TEST(PmrListTest, PushBackAndIterate)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(PmrListTest, PopFront)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_front();
    EXPECT_EQ(*list.begin(), 20);
    list.pop_front();
    EXPECT_EQ(*list.begin(), 30);
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(PmrListTest, ClearList)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.begin(), list.end());
}

TEST(PmrListTest, EmptyListCheck)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    EXPECT_TRUE(list.empty());
    list.push_back(10);
    EXPECT_FALSE(list.empty());
}

TEST(PmrListTest, AddMultipleAndCheckOrder)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    for (int i = 0; i < 10; ++i)
    {
        list.push_back(i);
    }

    int expected = 0;
    for (const auto &val : list)
    {
        EXPECT_EQ(val, expected++);
    }
}

TEST(PmrListTest, ModifyElements)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    for (auto &val : list)
    {
        val *= 2;
    }

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 30);
}

TEST(PmrListTest, PushBackStrings)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<std::string> list(&memory_resource);

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    auto it = list.begin();
    EXPECT_EQ(*it, "Apple");
    ++it;
    EXPECT_EQ(*it, "Banana");
    ++it;
    EXPECT_EQ(*it, "Cherry");
}

TEST(PmrListTest, LargeNumberOfElements)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    for (int i = 0; i < 1000; ++i)
    {
        list.push_back(i);
    }

    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        EXPECT_EQ(*it, count++);
    }
    EXPECT_EQ(count, 1000);
}

TEST(PmrListTest, AddAndRemoveRepeatedly)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(100);
    EXPECT_EQ(*list.begin(), 100);

    list.pop_front();
    EXPECT_TRUE(list.empty());

    list.push_back(200);
    list.push_back(300);
    EXPECT_EQ(*list.begin(), 200);

    list.pop_front();
    EXPECT_EQ(*list.begin(), 300);
}

TEST(PmrListTest, AddRemoveAndClear)
{
    FixedBlockMemoryResource memory_resource(1024, 10240);
    PmrList<int> list(&memory_resource);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(*list.begin(), 1);

    list.pop_front();
    list.push_back(4);
    EXPECT_EQ(*list.begin(), 2);

    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.begin(), list.end());
}
