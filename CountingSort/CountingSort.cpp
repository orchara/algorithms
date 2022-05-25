#include <iostream>
#include <algorithm>

#define NUMSIZE 11

int main()
{
    int n = 0, sample[NUMSIZE] = { 0 };
    std::cin >> n;
    int* mas = new int[n];
    int* res = new int[n];
    
    for (int i = 0; i < n; ++i) {
        std::cin >> mas[i];
        sample[mas[i]] += 1;
    }
    for (int i = 1, j = 0; i < NUMSIZE; ++i) {
        if (sample[i] != 0) {
            sample[i] += sample[j];
            j = i;
        } 
    }

    for (int i = n - 1; i >= 0; --i) {        
        res[sample[mas[i]] - 1] = mas[i];
        sample[mas[i]]--;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << " ";
    }
    return 0;
}

