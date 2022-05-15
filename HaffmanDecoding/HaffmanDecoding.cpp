#include <iostream>
#include <map>

typedef std::map<std::string, std::string> enc_map;

std::string Decoding(std::string str, enc_map m) {
    std::string temp, res;
    for (int i = 0; i < str.size(); ++i) {
        temp.append(str.substr(i, 1));
        if (m.find(temp) != m.end()) {
            res.append(m[temp]);
            temp = "";
        }
    }
    return res;
}

int main()
{
    uint32_t k, l;
    enc_map d_map;
    std::string str;
    std::cin >> k >> l;
    while (k > 0) {
        std::string key, val;
        std::cin >> val >> key;
        d_map[key] = val.substr(0,1);
        --k;
    }
    std::cin >> str;
    std::cout << Decoding(str, d_map);
}

