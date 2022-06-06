#include <iostream>
#include <algorithm>

int32_t CountOpTD(int32_t n, int32_t m) {
    if (n == 1) {
        return m;
    }
    int64_t x3 = 100000000000, x2 = 100000000000, x1 = 100000000000, _min = 0;
    if (n % 3 == 0) {
        x3 = CountOpTD(n / 3, m + 1);
    }    
    if (n % 2 == 0) {
        x2 = CountOpTD(n / 2, m + 1);
    }
    x1 = CountOpTD(n - 1, m + 1);    
    _min = std::min(x1, std::min(x2, x3));
    return _min;
}

int main()
{
    int32_t n = 0, m = 1;
    std::cin >> n;
    CountOpTD(n, m);
    std::cout << m;
}

