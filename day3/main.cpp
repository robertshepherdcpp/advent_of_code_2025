#include<iostream> // std::cout
#include<fstream> // std::fstream
#include<string> // std::string

auto find_largest(std::string s) -> std::pair<char, int> {
    std::pair<char, int> smallest{};
    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] > smallest.first) {
            smallest = {s[i], i};
        }
    }
    return smallest;
}

auto main() -> int {
    std::ifstream file("file.txt");
    std::string line{};
    int total_count = 0;
    while (file >> line) {
        // line by line
        auto largest = find_largest(line);
        auto next_largest = find_largest(line.substr(largest.second+1));
        total_count += (largest.first - '0') * 10 + (next_largest.first - '0');
    }

    std::cout << total_count << "\n";

    return {};
}