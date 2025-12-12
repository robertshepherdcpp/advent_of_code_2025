#include<iostream>
#include<vector>
#include<fstream>
#include<string>

auto in(std::string s, char c) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::ifstream file("file.txt");
    std::string line{};
    std::vector<std::vector<char>> v{};
    bool first_part = true;
    while(std::getline(file, line)) {
        // check if were on the next part
        if(in(line, ':') != -1 and in(line, 'x') != -1) {
            first_part = false;
        }
    }
}