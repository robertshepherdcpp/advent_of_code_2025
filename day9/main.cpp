/*
First of all, what i need to do:
- for each 2 points in the input we need to find the ones with the largest area between them
- there is obviously the brute force way of doing things
- this would be o(^2) time
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<utility>
#include<cmath>

auto seperate_by(std::string& line, char sep) -> std::vector<int> {
    std::vector<int> res{};
    std::string curr{};
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == sep) {
            res.emplace_back(std::stoi(curr));
            curr = {};
        }
        else {
            curr += line[i];
        }
    }
    res.emplace_back(std::stoi(curr));
    return res;
}

template<typename T>
auto max(T a, T b) -> T {
    return a < b ? b : a;
}

auto main() -> int {
    std::ifstream i("file.txt");
    std::string line{};
    std::vector<std::pair<int, int>> points{};
    while(std::getline(i, line)) {
        auto res = seperate_by(line, ',');
        points.push_back({res[0], res[1]});
    }

    // here we just do the brute force.
    int max_area = 0;
    for(int i = 0; i < points.size(); i++) {
        for(int j = i+1; j < points.size(); j++)
        {
            max_area = max(max_area, (abs(points[i].first - points[j].first) * abs(points[i].second - points[j].second)));
        }
    }
    std::cout << max_area << "\n";

    return {};
}