
#include <iostream>
#include <string>

std::string ReplaceNthOccurrence(const std::string &text, int n, char old_value, char new_value)
{
    if (n <= 0)
    {
        return text;
    }

    std::string result = text;
    int occurrence_count = 0;

    for (size_t i = 0; i < result.length(); ++i)
    {
        if (result[i] == old_value)
        {
            ++occurrence_count;
            if (occurrence_count == n)
            {
                result[i] = new_value;
                occurrence_count = 0;
            }
        }
    }

    return result;
}