// first just my intuition:
/*
Brute force:
- o(n^2)
- checks each point to see minimum distance, finds min distance using pythag
- and then for each point do a kind of breadth/depth first search, this can be done by keeping a list of the different connections
- we count up the number of different circuits
- and then we times together all of their sizes
*/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

template<typename A, typename B, typename C>
struct triple {
    A a;
    B b;
    C c;
};

auto seperate_by(std::string& line, char sep) {
    std::vector<std::string> res{};
    std::string curr{};
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == sep) {
            res.emplace_back(curr);
            curr = {};
        }
        else {
            curr += line[i];
        }
    }
    res.emplace_back(curr);
    return res;
}


auto main() -> auto {
    std::vector<triple<int, int, int>> coordinates{};
    std::ifstream file("file.txt");
    std::string line{};
    while(std::getline(file, line)) {
        auto vec = seperate_by(line, ',');
        std::vector<int> n_vec{};
        n_vec.reserve(vec.size());
        for(auto i : vec) {
            n_vec.push_back(std::stoi(i));
        }
        coordinates.emplace_back(n_vec);
    }
    // now we have the inputs.
}