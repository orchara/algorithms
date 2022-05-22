#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <ios>

int32_t get_pos(const std::vector<int32_t>& numbers, int number) {
    int32_t l = 0, r = numbers.size() - 1, mid;
    while (l <= r)
    {
        mid = (l+r)/2;
        if (numbers[mid] == number) {
            return mid;
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

int32_t FindMid(std::vector<int32_t>& v, int32_t beg, int32_t end) { 
         int32_t ret, mid; 
         mid =  static_cast<int64_t>(beg + end)/2; 
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
  
  
  
 void QuickSort(std::vector<int32_t>& v, int32_t beg, int32_t end) { 
	if(end - beg < 1){
	        return;
	}
         int32_t mid = FindMid(v, beg, end), i = beg + 1, j = beg, k = end +1; 
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
         int32_t n, m; 
         std::vector<int32_t> beg, end; 
         std::cin >> n >> m; 
         for (size_t i = 0; i < n; ++i) { 
                 int32_t temp; 
                 std::cin >> temp; 
                 beg.push_back(temp); 
                 std::cin >> temp; 
                 end.push_back(temp); 
         } 
         QuickSort(beg, 0, beg.size() - 1);
         QuickSort(end, 0, beg.size() - 1);
         for (size_t i = 0; i < m; ++i) { 
                 int32_t temp; 
                 std::cin >> temp; 
                 std::cout << (get_pos(beg, temp) - 1) - (get_pos(end, temp) + 1) << " ";
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