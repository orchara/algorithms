#include <iostream>
#include <vector>

typedef std::pair<int16_t, int32_t> step;
int32_t mymax(int32_t a, int32_t b) {
	return a > b ? a : b;
}

int main()
{
	int16_t n;
	std::cin >> n;
	std::vector<step> steps(n + 1, { 0, 0 });
	for (size_t i = 1; i <= n; ++i) {
		std::cin >> steps[i].first;
	}
	steps[1].second = steps[1].first;
	for (size_t i = 2; i <= n; ++i) {
		steps[i].second = mymax((steps[i - 1].second + steps[i].first), 
								(steps[i - 2].second + steps[i].first));
	}
	std::cout << steps[n].second;
}

