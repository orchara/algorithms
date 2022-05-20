#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int32_t>::iterator FindMid(std::vector<int32_t>& v, std::vector<int32_t>::iterator beg, std::vector<int32_t>::iterator end) {
	std::vector<int32_t>::iterator beg, end, mid;
	int32_t ret;
	mid = beg + (v.size());
	ret = std::min(std::max(*beg, *end), std::max(*beg, *mid));
	if (ret = *beg) {
		return beg;
	}
	if (ret = *end) {
		return end;
	}
	if (ret = *mid) {
		return mid;
	}
}



void QuickSort(std::vector<int32_t>& v, std::vector<int32_t>::iterator beg, std::vector<int32_t>::iterator end) {
	std::vector<int32_t>::iterator mid = FindMid(v, beg, end), i = beg + 1, j = beg;
	std::swap(*beg, *mid);
	while (i != end) {
		if (*beg <= *i) {
			j++;
			std::swap(*j, *i);
		}
		i++;
	}
	std::swap(*beg, *j);

	return;
}

int main()
{
	int32_t n, m;
	std::vector<int32_t> beg, end, dot;
	/*std::cin >> n >> m;
	for (size_t i = 0; i < n; ++i) {
		int32_t temp;
		std::cin >> temp;
		beg.push_back(temp);
		std::cin >> temp;
		end.push_back(temp);
	}
	for (size_t i = 0; i < m; ++i) {
		int32_t temp;
		std::cin >> temp;
		dot.push_back(temp);
	}*/
	beg = { 1, 3, 7, 4, 2, 6 , 8, 9, 5 };

}