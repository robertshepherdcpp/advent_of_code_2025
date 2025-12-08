#include<iostream>
#include<vector>
#include<string>
#include<fstream>

auto split_line(std::string& line) -> std::vector<std::string> {
    std::vector<std::string> res{};
    std::string curr{};
    for(int i = 0; i < line.size(); i++) {
        if(line[i] != ' ') {
            curr += line[i];
        }
        else {
            if(curr != "") {
                res.emplace_back(curr);
                curr = {};
            }
        }
    }
    return res;
}

auto times(std::vector<int>& vec) -> int {
    int curr = 1;
    for(auto i : vec) {
        curr *= i;
    }
    return curr;
}
auto plus(std::vector<int>& vec) -> int {
    int curr = 0;
    for(auto i : vec) {
        curr += i;
    }
    return curr;
}

auto main() -> int {
    std::ifstream file("file.txt");
    std::vector<std::vector<std::string>> arr{};
    std::string line{};
    while(std::getline(file, line)) {
        arr.emplace_back(split_line(line));
    }
    // now we have the array of vectors.
    int total = 0;
    for(int i = 0; i < arr[0].size(); i++) {
        std::string operand = arr[int(arr.size()-1)][i];
        std::vector<int> col{};
        for(int j = 0; j < arr.size()-1; i++) {
            col.emplace_back(std::stoi(arr[j][i]));
        }
        if(operand == "+") {total += plus(col);}
        if(operand == "*") {total += times(col);}
    }
    std::cout << total << "\n";

    return {};
}