#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <ios>

int64_t get_pos(const std::vector<int64_t>& numbers, int number, bool flag) {
    int64_t l = 0, r = numbers.size() - 1, mid = 0;
    while (l <= r)
    {
        mid = (l+r)/2;
        if (numbers[mid] == number) {
            if (flag) {
                while (mid+1 < numbers.size()) {
                    if (numbers[mid+1] == number) {
                        mid++;
                    } else {
                        break;
                    }
                }
                return mid + 1;
            } else {
                while (mid-1 >= 0) {
                    if (numbers[mid-1] == number) {
                        mid--;
                    } else {
                        break;
                    }
                }
                return mid;
            }
        }
        if (numbers[mid] > number) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(numbers[mid] > number){
        	return mid;
    }else{
    	return mid + 1;
    }
}

int64_t FindMid(std::vector<int64_t>& v, int64_t beg, int64_t end) { 
         int64_t ret, mid; 
         mid =  (beg + end)/2;
         ret = std::min(std::min(std::max(v[beg], v[end]), std::max(v[beg], v[mid])), std::max(v[mid], v[end])); 
         if (ret == v[beg]) { 
         	return beg; 
         } 
         if (ret == v[end]) { 
             return end; 
         } 
         if (ret == v[mid]) { 
              return mid; 
         } 
         return mid;
 } 
  
  
  
 void QuickSort(std::vector<int64_t>& v, int64_t beg, int64_t end) { 
	if(end - beg < 1){
	        return;
	}
         int64_t mid = FindMid(v, beg, end), i = beg + 1, j = beg, k = end +1; 
         //std::cout << mid << " " << v[mid] << std::endl;
         std::swap(v[beg], v[mid]); 
         while (i < k) { 
                 if (v[beg] > v[i]) { 
                         j++; 
                         std::swap(v[j], v[i]); 
                         i++;
                 }else if (v[beg] < v[i]){
                 	k--;
                 	std::swap(v[k], v[i]);
                 }  else if(v[beg] == v[i]){
                 	i++;
                 }
         } 
         std::swap(v[beg], v[j]); 
         QuickSort(v, beg, j -1);
         QuickSort(v, k, end);
  
         return; 
 } 
  
 int main() 
 { 
 		std::ios_base::sync_with_stdio(false);
         int64_t n, m; 
         std::vector<int64_t> beg, end; 
         std::cin >> n >> m; 
         for (int64_t i = 0; i < n; ++i) {
             int64_t temp;
             std::cin >> temp; 
             beg.push_back(temp); 
             std::cin >> temp; 
             end.push_back(temp);   
         } 
         QuickSort(beg, 0, beg.size() - 1);
         QuickSort(end, 0, beg.size() - 1);
         for (int64_t i = 0; i < m; ++i) {
             int64_t temp; 
             std::cin >> temp; 
             std::cout << get_pos(beg, temp, true) - get_pos(end, temp, false) << " ";
         }
 
 /*beg = { 1, 10, 7, 11, 2, 6 , 8, 9, 5 }; 
         for(auto v : beg){
         	std::cout << v << " ";
         }
         std::cout << std::endl;
         QuickSort(beg, 0, beg.size() - 1);
         for(auto v : beg){
         	std::cout << v << " ";
         }
         std::cout << std::endl;
         std::cout <<get_pos(beg, 3);
         std::cout << std::endl;
         std::cout <<get_pos(beg, 5)*/
         
         
  
 }