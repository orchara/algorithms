#include <iostream>
#include <ios>
#include <vector>

std::vector<int64_t> MergeSort(std::vector<int64_t> a, std::vector<int64_t> b, int64_t* count) {
    std::vector<int64_t> res;
    int64_t i = 0, j = 0, a_s = a.size(), b_s = b.size();
    while (i < a_s || j < b_s) {
        if (i == a_s) {
            res.push_back(b[j]);
            j++;
        } else
            if (j == b_s) {
                res.push_back(a[i]);
                i++;
            } else
                if (a[i] <= b[j]) {
                    res.push_back(a[i]);
                    i++;
                } else {
                    res.push_back(b[j]);
                    *count += a_s - i;
                    j++;
                }
    }
    return res;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int64_t n, count = 0;
    int64_t temp, max;
    std::cin >> n;
    std::vector<std::vector<int64_t>> mas, test;
    std::cin >> temp;
    mas.push_back({temp});
    max = mas[0][0];
    int64_t j = 0, k = 0;
    for (int64_t i = 1; i < n; ++i) {
        std::cin >> temp;
        if (max > temp) {
            j++;
            mas.push_back({});
        } 
        max = temp;
        (mas[j]).push_back(temp);
    }
    int64_t first = 0, sec = 1;
    while (mas.size() > 1) {
        test.push_back(MergeSort(mas[first], mas[sec], &count));
        first += 2;
        sec += 2;

        if (sec >= mas.size()) {
            if (first >= mas.size()) {
                mas = test;
                test = {};
                first = 0;
                sec = 1;
            } else {
                test.push_back(mas[first]);
                mas = test;
                test = {};
                first = 0;
                sec = 1;
            }
        }
    }
    std::cout << count;
    return 0;
}