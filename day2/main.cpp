// https://godbolt.org/z/bdYoj81bK

#include<print>
#include<vector>
#include<string>
#include<iostream>
#include<cmath>
#include<ranges>
#include<algorithm>

namespace shep {
    template<typename T>
    auto print_vector(std::vector<T>& vec) {
        for(auto& i : vec) {
            std::println("{}", i);
        }
    }
    template<typename A, typename B>
    auto print_pair(std::vector<std::pair<A, B>>& vec) {
        for(auto& i : vec) {
            std::cout << "[" << i.first << ":" << i.second << "]\n";
        }
    }

    auto string_times(std::string s, int times) {
        std::string res{s};
        res.reserve(times * s.size());
        for(int i = 0; i < times-1; i++) {
            res += s;
        }
        return res;
    }
    auto string_times(char s, int times) {
        std::string res{s};
        res.reserve(times);
        for(int i = 0; i < times-1; i++) {
            res += s;
        }
        return res;
    }

    auto divide(std::string& s, int num) -> std::vector<std::string> {
        int interval = s.size() / num;
        std::vector<std::string> result{};
        for(int i = 0; i < s.size()+1; i++) {
            if(i % interval == 0 and i != 0) {
                result.emplace_back(s.substr(i-interval, interval));
            }
        }
        return result;
    }
} // namespace shep

auto split(std::string& str) -> std::pair<std::string, std::string> {
    // std::cout << str << '\n';

    std::string first;
    std::string second;
    for(int j = 0; j < str.size(); j++) {
        if(str[j] == '-') {
            first = str.substr(0, j);
            second = str.substr(j+1, str.size());
            break;
        }
    }
    std::pair<std::string, std::string> p = {first, second};
    return p;
}

auto main() -> int {
    //std::string rs = "16100064-16192119,2117697596-2117933551,1-21,9999936269-10000072423,1770-2452,389429-427594,46633-66991,877764826-877930156,880869-991984,18943-26512,7216-9427,825-1162,581490-647864,2736-3909,39327886-39455605,430759-454012,1178-1741,219779-244138,77641-97923,1975994465-1976192503,3486612-3602532,277-378,418-690,74704280-74781349,3915-5717,665312-740273,69386294-69487574,2176846-2268755,26-45,372340114-372408052,7996502103-7996658803,7762107-7787125,48-64,4432420-4462711,130854-178173,87-115,244511-360206,69-86";
    std::string rs = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";
    // now we need to split them.
    std::vector<std::pair<std::string, std::string>> irs{};
    int last_idx{};
    for(int i = 0; i < rs.size(); i++) {
        if(rs[i] == ',') {
            std::string str = rs.substr(last_idx, i-last_idx);
            irs.emplace_back(split(str));
            last_idx = i+1;
        }
    }
    // the last one
    auto last_one = rs.substr(last_idx);
    irs.emplace_back(split(last_one));

    shep::print_vector(irs);

    // now that we have split the ranges, we need to find the double numbers
    int total_count = 0;
    for(auto& i : irs) {
        std::string start = i.first;
        std::string end = i.second;
        if(not (i.first.size() % 2 == 0)) {
            // the the start of the range needs to be at the next power of 10
            start = "1" + shep::string_times('0', i.first.size());
        }
        if(not (i.second.size() % 2 == 0)) {
            // the end of the range needs to be the first one upper power of 10 - 1
            end = shep::string_times('9', i.first.size());
        }
        if(start == end) {
            total_count += 1;
        }
        int start_val = std::stoi(shep::divide(start, 2)[0])+1;
        int less_than = std::stoi(shep::divide(end, 2)[0]);

        // std::string reversed;
        // reversed.resize(start.size());

        
        // for(int i = start_val; i < less_than; i++) {
        //     std::string reversed_ = std::to_string(i);
        //     std::reverse_copy(reversed_.begin(), reversed_.end(), std::back_inserter(reversed));
        //     if(reversed_ == reversed) {
        //         total_count += 1;
        //     }
        // }

        total_count += (less_than - start_val);
    }

    std::cout << "Total count: " << total_count << "\n";

    return {};
}
