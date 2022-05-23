#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	long n = 0;
	long count = 1;
	std::vector<long> terms;
	std::cin >> n;
	while (n - count > count)
	{
		n -= count;
		terms.push_back(count);
		count++;
	}
	terms.push_back(n);

	std::cout << count << std::endl;

	for (long term : terms)
	{
		std::cout << term << ' ';
	}

}