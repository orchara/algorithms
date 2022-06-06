#include <iostream>
#include <vector>


int main()
{
	int32_t W = 0, n = 0, * g;
	std::cin >> W >> n;
	std::vector<std::vector<int32_t>> D(W + 1, std::vector<int>(n + 1, 0));
	g = new int32_t[n];
	for (int32_t i = 0; i < n; ++i) {
		std::cin >> g[i];
	}
	for (int32_t i = 1; i <= n; ++i) {
		for (int32_t w = 1; w <= W; ++w) {
			D[w][i] = D[w][i - 1];
			if (g[i - 1] <= w) {
				if (D[w][i] < D[w - g[i - 1]][i - 1] + g[i-1]) {
					D[w][i] = D[w - g[i - 1]][i - 1] + g[i-1];
				}
			}
		}
	}
	std::cout << D[W][n];
	return 0;
}

