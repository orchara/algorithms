#include <iostream> 
#include <vector> 
#include <algorithm> 
  
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
         int32_t mid = FindMid(v, beg, end), i = beg + 1, j = beg; 
         std::cout << mid << " " << v[mid] << std::endl;
         std::swap(v[beg], v[mid]); 
         while (i <= end) { 
                 if (v[beg] >= v[i]) { 
                         j++; 
                         std::swap(v[j], v[i]); 
                 } 
                 i++; 
         } 
         std::swap(v[beg], v[j]); 
         QuickSort(v, beg, j -1);
         QuickSort(v, j + 1, end);
  
         return; 
 } 
  
 int main() 
 { 
         //int32_t n, m; 
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
         for(auto v : beg){
         	std::cout << v << " ";
         }
         std::cout << std::endl;
         QuickSort(beg, 0, beg.size() - 1);
         for(auto v : beg){
         	std::cout << v << " ";
         }
  
 }