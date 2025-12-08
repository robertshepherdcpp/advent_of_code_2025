// fair to say an interesting puzzle today

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<utility>
#include<queue>

auto main() -> int {
    std::ifstream file("file.txt");
    std::string line{};
    std::vector<std::vector<char>> vec{};
    while(std::getline(file, line)) {
        std::vector<char> temp{};
        temp.reserve(line.size());
        for(auto c : line) {
            temp.push_back(c);
        }
        vec.push_back(temp);
    }
    // now we have the vector.
    // for now we are just going to do while(true) but we need to change that!
    std::pair<int, int> first{};
    for(int i = 0; i < vec[0].size(); i++) {
        if(vec[0][i] == 'S') {
            first = {1, i};
        }
    }
    std::queue<std::pair<int, int>> q{};
    int splits = 0;
    while(true) {
        std::pair<int, int> val = q.pop();
        if(val.first == vec.size()-1) {
            break;
        }
        if(vec[val.first+1][val.second] == '^') {
            splits += 1;
            q.push({val.first+1, val.second-1});
            q.push({val.first+1, val.second+1});
        }
    }

    std::cout << splits << "\n";

    return {};
}