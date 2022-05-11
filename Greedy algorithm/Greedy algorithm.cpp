#include <iostream>
#include <utility>
#include <vector>
#include<algorithm>

using Segment = std::pair<int, int>;

std::vector <int> get_covering_set(std::vector <Segment> segments)
{
    std::vector <int> result;
    auto Comp = [](Segment s1, Segment s2) {
        return s1.second < s2.second ? true : false;
    };
    std::sort(segments.begin(), segments.end(),Comp);
    int temp;
    // fix this function
    for (auto s : segments)
    {
        if (result.size() == 0)
        {
            result.push_back(s.second);
        }
        else
        {
            if (*(result.end() - 1) <= s.second && *(result.end() - 1) >= s.first)
            {
                continue;
            }
            result.push_back(s.second);
        }
    }

    return result;
}

int main(void)
{
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (auto& s : segments)
    {
        std::cin >> s.first >> s.second;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point : points)
    {
        std::cout << point << " ";
    }
    std::cout << std::endl;
}