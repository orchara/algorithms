#include <iostream>
#include <vector>
#include <algorithm>


void ShiftUp(std::vector<long long>* heap, size_t i) {
    while (i > 0) {
        if ((*heap)[i] > (*heap)[(i - 1) / 2]) {
            std::swap((*heap)[i], (*heap)[(i - 1) / 2]);
            i = (i - 1) / 2;
        } else {
            return;
        }
    }
    return;
}

void ShiftDown(std::vector<long long>* heap, size_t i) {
    size_t size = heap->size();
    while (2 * i + 1 < size) {
        if (2 * (i + 1) < size) {
            if ((*heap)[i] > (*heap)[2 * i + 1] && (*heap)[i] > (*heap)[2 * (i + 1)]) {
                return;
            }
            if ((*heap)[2 * i + 1] < (*heap)[2 * (i + 1)]) {
                std::swap((*heap)[i], (*heap)[2 * (i + 1)]);
                i = 2 * (i + 1);
                continue;
            } else {
                std::swap((*heap)[i], (*heap)[2 * i + 1]);
                i = 2 * i + 1;
                continue;
            }
        } 
        if ((*heap)[i] < (*heap)[2 * i + 1]) {
            std::swap((*heap)[i], (*heap)[2 * i + 1]);
            i = 2 * i + 1;
        }
        break;
    }
}

void Insert(long long val, std::vector<long long>* heap) {
    heap->push_back(val);
    size_t i = heap->size() - 1;
    ShiftUp(heap, i);
    return;
}

long long Remove(std::vector<long long>* heap, size_t i) {
    std::swap((*heap)[i], (*heap)[(heap->size()) - 1]);
    long long pop = heap->back();
    heap->pop_back();
    if (i != 0) {
        if ((*heap)[i] > (*heap)[(i - 1) / 2]) {
            ShiftUp(heap, i);
            return pop;
        }
    }
    ShiftDown(heap, i);
    return pop;
}

long long ExtractMax(std::vector<long long>* heap) {
    return Remove(heap, 0);
}

int main()
{
    std::vector<long long> heap;
    long long count, val;
    std::string str;
    std::cin >> count;
    while (count > 0 ) {
        std::cin >> str;
        if (str.compare("Insert") == 0) {
            std::cin >> val;
            Insert(val, &heap);
        }
        if (str.compare("ExtractMax") == 0 && heap.size() > 0) {
            std::cout << ExtractMax(&heap) << std::endl;
        }
        count--;
    }
    return 0;
}

