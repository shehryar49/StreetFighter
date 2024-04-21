#include "utils.h"

std::vector<std::string> split(const std::string& s,char x)
{
    std::vector<std::string> parts;
    size_t len = s.length();
    size_t start = 0;
    for(size_t i = 0;i<len;i++)
    {
        if(s[i] == x)
        {
            parts.push_back(s.substr(start,i - start));
            start = i+1;
        }
    }
    parts.push_back(s.substr(start,len - start));
    return parts;
}
void strip(std::string& word)
{
    while(word.length()>1 && word[0] == ' ')
        word.erase(word.begin());
    while(word.length()>1 && word.back() == ' ')
        word.pop_back();
}