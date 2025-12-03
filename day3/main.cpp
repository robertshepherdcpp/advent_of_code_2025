#include<iostream> // std::cout
#include<fstream> // std::fstream
#include<string> // std::string

auto main() -> int {
    std::ifstream file("file.txt");
    std::string s{};
    int total_count = 0;
    while (file >> s) {
        // line by line
    }

    std::cout << total_count << "\n";

    return {};
}