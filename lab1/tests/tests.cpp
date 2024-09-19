#include <gtest/gtest.h>
#include "../src/ReplaceNthOccurrence.cpp"

TEST(TestSet, basic_example)
{
    std::string input = "Vader said: No, I am your father!";
    int n = 2;
    char old_value = 'a';
    char new_value = 'o';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "Vader soid: No, I am your fother!");
}

TEST(TestSet, empty_strin)
{
    std::string input = "";
    int n = 2;
    char old_value = 'a';
    char new_value = 'o';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "");
}

TEST(TestSet, only_a)
{
    std::string input = "aaaaaaaaaaaaaaa";
    int n = 2;
    char old_value = 'a';
    char new_value = 'o';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "aoaoaoaoaoaoaoa");
}

TEST(TestSet, n_more_input)
{
    std::string input = "qwerty";
    int n = 10;
    char old_value = 'w';
    char new_value = 'r';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "qwerty");
}

TEST(TestSet, n_negative)
{
    std::string input = "qwerty";
    int n = -10;
    char old_value = 'w';
    char new_value = 'r';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "qwerty");
}

TEST(TestSet, without_a)
{
    std::string input = "qwertyuiopsdfghjklzxcvbnm";
    int n = 2;
    char old_value = ' ';
    char new_value = 'o';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "qwertyuiopsdfghjklzxcvbnm");
}

TEST(TestSet, equival_replacement)
{
    std::string input = "ooooo";
    int n = 2;
    char old_value = 'o';
    char new_value = 'o';
    std::string result = ReplaceNthOccurrence(input, n, old_value, new_value);
    ASSERT_TRUE(result == "ooooo");
}
