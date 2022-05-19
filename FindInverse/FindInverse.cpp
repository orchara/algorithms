#include <iostream>
#include <ios>
#include <vector>

int get_pos(const std::vector<int>& numbers, int number) {
    int l = 0, r = numbers.size() - 1, count = 0;
    if (number >= numbers[r]) {
        return 0;
    }
    if (number < numbers[l]) {
        return numbers.size();
    }
    int mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (numbers[mid] == number) {
            count = numbers.size() - (mid + 1);
        }
        if (numbers[mid] > number) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (number < numbers[mid]) {
        mid--;
    }
    count = numbers.size() - (mid + 1);
    return count;
}


int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);
    uint32_t n, count = 0;
    int temp, max;
    std::cin >> n;
    std::vector<std::vector<int>> mas;
    std::cin >> temp;
    mas.push_back({temp});
    max = mas[0][0];
    uint32_t j = 0, k = 0;
    for (uint32_t i = 1; i < n; ++i) {        
        int32_t temp;
        std::cin >> temp;
        if (max > temp) {
            j++;
            mas.push_back({});
        } 
        max = temp;
        (mas[j]).push_back(temp);
        if (j > 0) {
            for (uint32_t l = j; l > 0; l--) {
                count += get_pos(mas[l - 1], temp);
            }
        }
    }
    std::cout << count;
    return 0;
}