#include <iostream>
#include <string>
#include <vector>

int diff(char A, char B) {
	int res = 0;
	if (A == B) {
		res = 0;
	} else {
		res = 1;
	}
	return res;
}

int my_min(int a, int b, int c) {
	int min = a;
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	return min;
}

int main()
{
	std::string str1, str2;
	int n = 0, m = 0;
	std::cin >> str1 >> str2;
	n = str1.length();
	m = str2.length();
	std::vector<std::vector<int>> D(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i) {
		D[i][0] = i;
	}
	for (int j = 0; j <= m; ++j) {
		D[0][j] = j;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int c = diff(str1[i - 1], str2[j - 1]);
			D[i][j] = my_min((D[i - 1][j] + 1), (D[i][j - 1] + 1), (D[i - 1][j - 1] + c));
		}
	}
	std::cout << D[n][m];
	return 0;
}

