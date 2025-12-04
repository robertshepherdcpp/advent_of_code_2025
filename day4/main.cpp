#include<iostream>
#include<fstream>
#include<vector>

int main() {
    // inputs
    std::ifstream file("file.txt");
    std::vector<std::vector<char>> v{};
    std::string line{};
    while(file >> line) {
        std::vector<char> curr{};
        curr.reserve(line.size());
        for(auto i : line) {
            curr.push_back(i);
        }
        v.emplace_back(v);
    }

    // now find how many
    int total = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i > 0 and i < v.size()-1 and j > 0 and j < v[0].size()-1) {
                if(v[i+1][j] == '@', v[i-1][j] == '@')
            }
        }
    }
}