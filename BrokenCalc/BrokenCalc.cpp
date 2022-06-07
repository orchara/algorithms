#include <iostream>
#include <vector>
#define INF 100000

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

int32_t CountOpTD(int32_t n, int32_t m, std::vector<int32_t>* seq, int32_t* _min) {
	   if(*_min < m ){
	    	return INF;
	    }
     if (n == 1) {
        *_min = m;
		(*seq).clear();
        (*seq).push_back(n);
        return m;
    }
    int64_t x3 = INF, x2 = INF, x1 = INF;    
    if (n % 3 == 0) {
        x3 = CountOpTD(n / 3, m + 1, seq, _min);
    }    
    if (n % 2 == 0) {
        x2 = CountOpTD(n / 2, m + 1, seq, _min);
    }    
  	x1 = CountOpTD(n - 1, m + 1, seq, _min);    
    if(x1 < INF || x2 < INF || x3 < INF){
        (*seq).push_back(n);
    }
    return mymin(x1, x2, x3);
}

int main()
{
    std::vector<int32_t> seq;
    int32_t n = 0, m = 0, _min = INF;
    std::cin >> n;
    m = CountOpTD(n, m, &seq, &_min);
    std::cout << m << std::endl;
    for(auto f : seq){
    	std::cout << f << " ";
    }
}

