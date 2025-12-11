#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ranges>
#include<algorithm>
#include<unordered_set>
#include<memory>
#include<unordered_map>
#include<queue>

auto seperate_by(std::string& line, char sep) -> std::vector<std::string> const {
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

template<typename T>
auto vector_print(std::vector<T>& v) {
    for(T& t : v) {
        std::cout << t << ", ";
    }
    std::cout << "\n";
}

template<typename T>
auto pl(T t) {
    std::cout << t << "\n";
}

// this is just to make substrings in c++ nicer: // maybe change the args to reference
// it now works!
auto sub_s(std::string s, std::string command) -> std::string {
    if(command == "::-1") {std::string temp = s; std::reverse(temp.begin(), temp.end()); return temp;}
    // auto parts = seperate_by(command, ':');
    std::vector<std::string> parts{};
    for(int i = 0; i < command.size(); i++) {
        if(command[i] == ':') {
            parts.push_back(command.substr(0, i));
            parts.push_back(command.substr(i+1, s.size()-i+1));
        }
    }

    vector_print(parts);

    int starting_index = 0;
    if(parts[0] != "") {
        if(parts[0][0] == '-') {starting_index = (s.size() - std::stoi(parts[0].substr(1, parts[0].size()-1)));}
        else                   {starting_index = std::stoi(parts[0]);}
    }
    int ending_index = s.size();
    if(parts[1] != "" and parts[1] != " ") {
        if(parts[1][0] == '-') {ending_index = (s.size() - std::stoi(parts[1].substr(1, parts[1].size()-1)));}
        else                   {ending_index = std::stoi(parts[1]);}
    }
    std::cout << "starting index:" << starting_index << '\n';
    std::cout << "ending index: " << ending_index << '\n';
    return s.substr(starting_index, ending_index - starting_index-1);
}

struct Node {
    std::string val{};
    std::vector<std::shared_ptr<Node>> connecting{};

    Node(std::string p_val, std::vector<std::shared_ptr<Node>> p_connecting = {}) {val = p_val; connecting = p_connecting;}

    auto operator=(Node n) -> void {val = n.val; connecting = n.connecting;}
};

int main() {
    // just testing out the sub_s function p.s. it now works!
    // pl(sub_s("hello there", "0:-1"));
    // pl(sub_s("lil bro", "0:-3"));
    // pl(sub_s("hello", "::-1"));
    // pl(sub_s("hello", "1:"));

    // first get the input
    std::string line{};
    std::ifstream file("file.txt");
    // std::unordered_set<std::string> s{};
    // Node root{"null"};
    // this could be dangerous when the vector is resized.
    // std::vector<Node> nodes{};
    std::unordered_map<std::string, std::shared_ptr<Node>> graph{};
    while(std::getline(file, line)) {
        auto parts = seperate_by(line, ':');
        parts[1] = sub_s(parts[1], "1:");

        auto node = parts[0];
        auto connecting = seperate_by(parts[1], ' ');

        std::vector<std::shared_ptr<Node>> connects{};
        if(!graph.count(node) > 0) {
            graph[node] = std::make_shared<Node>(node);
        }
        for(auto& i : connecting) {
            if(!graph.count(i) > 0) {
                graph[i] = std::make_shared<Node>(i);
            }
            connects.push_back(graph[i]);
        }
        // std::vector<std::shared_ptr<Node>> connected_ptrs{};
        // if(root.val == "null") {
        //     root = {node};
        //     s.insert(node);
        //     for(auto i : connecting) {
        //         if(s.count(i)) {
        //             // there is already one in the tree
        //             // so we need to find it
        //             std::shared_ptr p = find_in_tree(root, i);
        //             connected_ptrs.push_back(p);
        //         }
        //         else {
        //             nodes.push_back(Node{i});
        //             s.insert(i);
        //             std::shared_ptr p = std::make_shared(&nodes[node.size()-1]);
        //         }
        //     }
        //     root = Node(node);
        // }
    }

    // now we need to find where the node first is. simply do this by doing graph[you]
    std::shared_ptr<Node> n = graph["you"];
    // now do a breadth first search and count the number of ways to get to a place.

    // need a better way of checking if this path has already been taken
    // std::vector<std::vector<std::string>> paths{};

    std::queue<std::shared_ptr<Node>> q;
    int paths_count = 0;
    q.push(n);
    while(q.size() > 0) {
        auto node_ = q.front();
        if(node_->val == "out") {
            paths_count += 1;
        }
        q.pop();
        for(auto& i : node_->connecting) {
            q.push(i);
        }
    }

    std::cout << paths_count << "\n";

    return {};
}