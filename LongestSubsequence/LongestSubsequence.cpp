#include <iostream>

int main()
{
    int n = 0, max = 0;
    std::cin >> n;
    long *mas = new long[n];
    long* prev = new long[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }
    for (int i = 0; i < n; ++i) {
        prev[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (mas[i] % mas[j] == 0 && prev[j] + 1 > prev[i]) {
                prev[i] = prev[j] + 1;
            }
        }
        if (prev[i] > max) {
            max = prev[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << prev[i] << " ";
    }
    std::cout << std::endl;
    std::cout << max;

    return 0;
}

