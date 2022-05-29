#include <iostream>

int main()
{
    int n = 0, max = 0, maxi = 0;
    std::cin >> n;
    long* mas = new long[n];
    long* length = new long[n];
    long* prev = new long[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
    }
    for (int i = 0; i < n; ++i) {
        length[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (mas[i] <= mas[j] && length[j] + 1 > length[i]) {
                length[i] = length[j] + 1;
                prev[i] = j;
            }
        }
        if (length[i] > max) {
            max = length[i];
            maxi = i;
        }
    }    
    int* ind = new int[max];
    ind[max - 1] = maxi + 1;
    for (int i = max - 2, j = maxi ; i >= 0; --i) {
        ind[i] = prev[j] + 1;
        j = prev[j];
    }
    std::cout << max << std::endl;
    for (int i = 0; i < max; i++) {
        std::cout << ind[i] << " ";
    }
    
    

    return 0;
}

