#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<utility>

// taken from day 2
auto split(std::string& str, char c) -> std::pair<std::string, std::string> {
    // std::cout << str << '\n';

    std::string first;
    std::string second;
    for(int j = 0; j < str.size(); j++) {
        if(str[j] == c) {
            first = str.substr(0, j);
            second = str.substr(j+1, str.size());
            break;
        }
    }
    std::pair<std::string, std::string> p = {first, second};
    return p;
}

auto main() -> int {
    std::ifstream file("file.txt");
    std::string line{};
    std::vector<std::pair<int, int>> vec{};
    while(std::getline(file, line)) {
        if(line == "") {
            break;
        }
        else {
            auto nums = split(line, '-');
            vec.push_back({std::stoi(nums.first), std::stoi(nums.second)});
        }
    }
    // now we are going to check the ranges
    int total_count = 0;
    while(std::getline(file, line)) {
        int num = std::stoi(line);
        for(auto& i : vec) {
            if(num >= i.first and num <= i.second)
                total_count += 1;
        }
    }
    std::cout << total_count << "\n";

    return {};
}