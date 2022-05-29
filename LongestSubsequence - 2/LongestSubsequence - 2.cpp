#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0, max = 0, maxi;
    std::cin >> n;

    int64_t* mas = new int64_t[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }
    if (n == 1) {
        std::cout << 1 << "\n" << 1;
        return 0;
    }
    std::vector<std::vector<int64_t>> prev;
    std::vector<int64_t> F(n + 2, -10000000000);
    F[0] = 10000000000;
    for (int i = 0; i < n; ++i) {
        int left = 0, right = F.size() - 1, middle = 0;
        while (right - left > 1) {
            middle = left + ((right - left) / 2);
            if (F[middle] < mas[i]) {
                right = middle;
            } else {
                left = middle;
            }            
        }
        F[right] = mas[i];
        prev.push_back({ right, i, mas[i] });
        if (right > max) {
            max = right;
            maxi = i;
        }
        //for (auto x : F) {
        //    std::cout << x << " ";
        //}
        //std::cout << std::endl;
    }
    //for (auto f : prev) {
    //    std::cout << f[0] << " " << f[1] << " " << f[2] << std::endl;
    //}
    std::vector<std::vector<int64_t>> res(max, { -1, 0, -10000000000 });
    res[max - 1] = prev[maxi];
    for (int i = maxi - 1, j = max - 1; i >= 0; --i) {
        if (prev[i][0] == res[j][0] - 1 && prev[i][2] >= res[j][2]) {
            --j;
            res[j] = prev[i];
        }
    }
    std::cout << max << std::endl;
    for (auto pr : res) {
        std::cout << pr[1] + 1 << " ";
    }
    return 0;
}

