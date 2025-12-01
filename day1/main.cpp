#include<iostream> // std::cout
#include<fstream> // std::fstream
#include<string> // std::string

auto main() -> int {
    std::ifstream file("file.txt");
    std::string s{};
    int zero_count = 0;
    int index = 50;
    while(file >> s) {
        std::cout << "Currently at index: " << index << "\n";
        int integer = std::stoi(s.substr(1));
        // std::cout << integer << "\n";
        // if(s[0] == 'L') {
        //     if(index-integer < 0) {
        //         index = 99 - (((index-integer) * -1) % 100) + 1;
        //     }
        //     else {
        //         index -= integer;
        //     }
        // } else { // s[0] == 'R'
        //     if(integer+index > 99) {
        //         index = (integer+index) % 100 - 1;
        //     }
        //     else {
        //         index += integer;
        //     }
        // }
        if (s[0] == 'L') {
            int count = ((index-integer)*-1 - (index+integer)%100) / 100;
            zero_count += count;
            index = (index - integer) % 100;
            if (index < 0) index += 100;
        } else { // R
            if(index + integer < 99)
            {
                index = (index + integer);
            }
            else {
                int count = ((index+integer) - (index+integer)%100) / 100;
                zero_count += count;

                index = (index + integer) % 100;
            }
        }
        if(index == 0) {
            zero_count += 1;
        }
    }

    std::cout << zero_count << "\n";

    return {};
}