#include <iostream>
#include <map>



typedef struct letter {
    char val = '\0';
    uint32_t rate = 0;
    struct letter* chld0 = nullptr;
    struct letter* chld1 = nullptr;
}letter;

typedef struct mypage {
    letter _letter;
    struct mypage* next = nullptr;
    struct mypage* prev = nullptr;
}mypage;

typedef struct mylist {
    mypage* head = nullptr;
    mypage* tail = nullptr;
    uint32_t __size = 0;

    int size() {
        return __size;
    }
}mylist;

typedef std::map<char, std::string> enc_map;



void NodeFill(std::string str, mylist* nodes);
bool InNodes(char c, mylist* nodes);
letter* TreeConstr(mylist nodes);
void PrintList(mylist lst);
void PushBack(letter val, mylist* lst);
letter PopMin(mylist* mlst);

letter PopMin(mylist* mlst) {
    mypage* lst = mlst->head;
    if (lst == nullptr) {
        return { '\0', 0 };
    }
    mypage* minlst = lst;
    for (mypage* head = lst; head != nullptr; head = head->next) {
        if (minlst->_letter.rate > head->_letter.rate) {            
            minlst = head;
        }
    }

    if (minlst->next != nullptr) {
        (minlst->next)->prev = minlst->prev;
    }
    else {
        mlst->tail = minlst->prev;
    }
    if (minlst->prev != nullptr) {
        (minlst->prev)->next = minlst->next;
    }
    else {
        mlst->head = minlst->next;
    }
    letter result = minlst->_letter;
    delete minlst;
    mlst->__size -= 1;
    return result;
}

void PushBack(letter val, mylist* lst) {
    if (lst->head == nullptr) {
        lst->head = new mypage;
        (lst->head)->_letter = val;
        lst->__size += 1;
        (lst->head)->prev = nullptr;
        (lst->head)->next = nullptr;
        lst->tail = lst->head;
    }
    else {
        (lst->tail)->next = new mypage;
        ((lst->tail)->next)->_letter = val;
        lst->__size += 1;
        ((lst->tail)->next)->prev = lst->tail;
        ((lst->tail)->next)->next = nullptr;
        lst->tail = (lst->tail)->next;
    }
    return;
}

void PrintList(mylist lst) {
    for (lst.head; lst.head != nullptr; lst.head = (lst.head)->next) {
        std::cout << ((lst.head)->_letter).val << ": " << (((lst.head)->_letter).rate) << std::endl;
    }
}

void NodeFill(std::string str, mylist* nodes){
    uint32_t strsize = str.size();    
    //nodes->push_back({ str[0], 1 });
    for (uint32_t i = 0; i < strsize; ++i) {        
        if (!InNodes(str[i], nodes)) {
            letter l;
            l.val = std::tolower(str[i]);
            l.rate = 1;
            PushBack(l, nodes);
        } 
    }
    return;
}

bool InNodes(char c, mylist* nodes) {
    if (nodes->head == nullptr) {
        return false;
    }
    for (mypage* head = nodes->head; head != nullptr; head = head->next) {
        if (c == head->_letter.val) {
            head->_letter.rate += 1;
            return true;
        }
    }
    return false;
}

letter* P_PopMin(mylist *mlst) {
    letter* res = new letter;
    *res = PopMin(mlst);
    return res;
}

letter* TreeConstr(mylist nodes) {
    letter* res = new letter;
    if (nodes.size() == 1) {
        *res = nodes.head->_letter;
        return res;
    }
    while (nodes.size() > 1) {
        letter newnode;
        newnode.chld0 = P_PopMin(&nodes);
        newnode.chld1 = P_PopMin(&nodes);
        newnode.rate = newnode.chld0->rate + newnode.chld1->rate;
        PushBack(newnode, &nodes);
    }    
    *res = nodes.head->_letter;
    return res;
}

void EncLetter(letter* top, std::string enc, std::string app, enc_map* m) {
    enc.append(app);
    if (top->val != '\0') {
        (*m)[top->val] = enc;
        //std::cout << top->val << ": " << enc << std::endl;        
        return;
    }
    EncLetter(top->chld0, enc, "0", m);
    EncLetter(top->chld1, enc, "1", m);
}

std::string Encoding(std::string str, enc_map m) {
    std::string res = "";
    for (size_t i = 0; i < str.length(); ++i) {
        res.append(m[str[i]]);
    }
    return res;
}

int main()
{
    enc_map e_map;
    std::string str, hafstr = "";
    //std::cin >> str;
    str = "ffffffffff";
    mylist nodes;
    NodeFill(str, &nodes);
    if (nodes.size() == 1) {
        e_map[str[0]] = "0";
    }else{
        letter* tree = TreeConstr(nodes);
        EncLetter(tree, "", "", &e_map);
    }
    hafstr = Encoding(str, e_map);
    std::cout << e_map.size() << " " << hafstr.size() << std::endl;
    for (enc_map::iterator it = e_map.begin(); it != e_map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    //PrintList(nodes);
    std::cout << hafstr << std::endl;

}

