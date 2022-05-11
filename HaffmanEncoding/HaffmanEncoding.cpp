#include <iostream>
#include <vector>
#include <map>



typedef struct letter {
    char val;
    uint32_t rate;
}letter;
typedef std::vector<letter> Letters;
typedef struct node {
    letter val;
    uint8_t enc;
    struct node* chld0;
    struct node* chld1;
}node;

void NodeFill(std::string str, Letters* nodes);
bool InNodes(char c, Letters* nodes);
void TreeConstr(Letters nodes);

void NodeFill(std::string str, Letters* nodes){
    uint32_t strsize = str.size();    
    //nodes->push_back({ str[0], 1 });
    for (uint32_t i = 0; i < strsize; ++i) {        
        if (!InNodes(str[i], nodes)) {
            nodes->push_back({ str[i], 1});
        } 
    }
    return;
}

bool InNodes(char c, Letters* nodes) {
    for (auto& node : *nodes) {
        if (c == node.val) {
            ++node.rate;
            return true;
        }
    }
    return false;
}

letter ExtractMin(Letters* nodes) {
    int vsize = nodes->size();
    uint32_t min = 0;
    for (int i = 1; i < vsize; ++i ) {
        if ((*nodes)[min].rate > (*nodes)[i].rate) {
            min = i;
        }
    }

}

void TreeConstr(Letters nodes) {
    
    
}

int main()
{
    std::string str, hafstr;
    //std::cin >> str;
    str = "abacabad";
    hafstr = "";
    Letters nodes;
    
    
    std::map<int, letter> massiv;



    /*NodeFill(str, &nodes);
    std::cout << nodes.size() << " " << hafstr.size() << std::endl;
    for (auto node : nodes) {
        std::cout << node.val << ": " << node.rate << std::endl;
    }
    std::cout << hafstr << std::endl;*/

}

