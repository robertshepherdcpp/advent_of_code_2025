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
#include<cmath>

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
    std::vector<std::pair<triple<int, int, int>, triple<int, int, int>>> already_seen{};
    for(int x = 0; x < 1000; x++) {
        std::pair<triple<int, int, int>, triple<int, int, int>> shortest_p;
        double shortest_v{};
        for(int i = 0; i < coordinates.size(); i++) {
            for(int j = i+1; j < coordinates.size()-1; j++) {
                double distance = sqrt(pow(abs(coordinates[i].a - coordinates[j].a), 2) + pow(abs(coordinates[i].b - coordinates[j].b), 2) + pow(abs(coordinates[i].c - coordinates[j].c), 2));
                if(distance < shortest_v and {coordinates[i], coordinates[j]} not in already_seen) {
                    shortest_v = distance;
                    shortest_p = {coordinates[i], coordinates[j]};
                }
            }
        }
        already_seen.push_back(shortest_p);
    }
}