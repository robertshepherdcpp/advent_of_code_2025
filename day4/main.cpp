#include<iostream>
#include<fstream>
#include<vector>

auto main() -> int {
    // inputs
    std::ifstream file("file.txt");
    std::vector<std::vector<char>> v{};
    std::string line{};
    while(file >> line) {
        std::vector<char> curr{};
        curr.reserve(line.size());
        for(auto i : line) {
            curr.emplace_back(i);
        }
        v.emplace_back(curr);
    }

    // now find how many
    int total = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            int count = (i < v.size()-1 ? (v[i+1][j] == '@') : 0) + 
                         (i > 0 ? (v[i-1][j] == '@') : 0) + 
                         (j < v[0].size()-1 ? (v[i][j+1] == '@'): 0) + 
                         (j > 0 ? (v[i][j-1] == '@') : 0) + 
                         ((i < v.size()-1 and j < v[0].size()-1) ? (v[i+1][j+1] == '@') : 0) + 
                         ((i < v.size()-1 and j > 0) ? (v[i+1][j-1] == '@') : 0) + 
                         ((i > 0 and j > 0) ? (v[i-1][j-1] == '@') : 0) + 
                         ((i > 0 and j < v[0].size()-1) ? (v[i-1][j+1] == '@') : 0);
            if(count < 4) {
                total += 1;
            }
        }
    }
    std::cout << "Total: " << total << "\n";

    return {};
}