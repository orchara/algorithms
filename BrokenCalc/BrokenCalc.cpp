#include <iostream>
#include <vector>
#define INF 100000

int32_t _min = INF;
std::vector<int32_t> seq;

int64_t mymin(int64_t a, int64_t b, int64_t c){
	int64_t _m = a;
	if(_m > b){
		_m = b;
	}
	if(_m > c){
		_m = c;
	}
	return _m;
}

int32_t CountOpTD(int32_t n, int32_t m) {
	   if(_min <= m ){
	    	return INF;
	    }
     if (n == 1) {
        _min = m;
        //std::cout << m << std::endl;
//        std::cout << n << " ";
		seq.clear();
		seq.push_back(n);
        return m;
    }
    int64_t x3 = INF, x2 = INF, x1 = INF, res = 0;
    
    if (n % 3 == 0) {
        x3 = CountOpTD(n / 3, m + 1);
    }    
    if (n % 2 == 0) {
        x2 = CountOpTD(n / 2, m + 1);
    }
    
  	  x1 = CountOpTD(n - 1, m + 1);    
    
    res = mymin(x1, x2, x3);
    if(x1 < INF || x2 < INF || x3 < INF){
    //std::cout << x1 << " " << x2 << " " << x3 << " " << n << "\n";
    //std::cout << n << " ";
    seq.push_back(n);
    }
    return res;
}

int main()
{
    int32_t n = 0, m = 0;
    std::cin >> n;
    m = CountOpTD(n, m);
    std::cout << m << std::endl;
    for(auto f : seq){
    	std::cout << f << " ";
    }
}

