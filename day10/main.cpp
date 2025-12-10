#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<queue>

auto seperate_by(std::string& line, char sep) -> std::vector<std::string> {
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

auto times(int a, char b) -> std::vector<char> {
    std::vector<char> res;
    res.reserve(a);
    for(int i = 0; i < a; i++) {
        res.push_back(b);
    }
    return res;
}

auto perform_action(std::vector<int>& moves, std::vector<char> state) -> std::vector<char> {
    for(auto i : moves) {
        state[i] = '#' ? state[i] == '.' : '.';
    }
    return state;
}

auto main() -> int {
    std::ifstream file("file.txt");
    std::string line{};
    int total_count = 0;
    while(std::getline(file, line)) {
        std::vector<std::string> parts{seperate_by(line, ' ')};

        std::string target = parts[0].substr(1, parts[0].size()-1);
        std::vector<char> target_v{};
        target_v.reserve(target.size()-2);
        for(int i = 1; i < target.size()-1; i++) {
            target_v.push_back(target[i]);
        }

        std::vector<std::string> buttons_s{};
        buttons_s.reserve(parts.size()-2);
        for(int i = 1; i < parts.size()-1; i++) {
            buttons_s.push_back(parts[i]);
        }
        std::vector<std::vector<int>> buttons{};
        for(std::string& s : buttons_s) {
            int start = 1;
            std::vector<int> curr{};
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == ',') {
                    curr.push_back(std::stoi(s.substr(start, i-start)));
                    start = i + 1;
                }
            }
            curr.push_back(std::stoi(s.substr(start, s.size()-start-1)));
            buttons.push_back(curr);
        }
        // now we can do a breadth first search sort of thing, however this is the brute force approach.
        std::queue<std::pair<std::vector<char>, int>> q{}; // the vector is of the state of the lights and the int is the amount of moves taken to get there
        q.push({times(target.size(), '.'), 0});
        while(q.size() != 0) {
            auto state = q.front();
            q.pop();
            if(state.first == target_v) {
                total_count += state.second;
            }
            for(auto m : buttons) {
                q.push({perform_action(m, state.first), state.second+1});
            }
        }
    }

    std::cout << "Total count: " << total_count << "\n";

    return {};
}