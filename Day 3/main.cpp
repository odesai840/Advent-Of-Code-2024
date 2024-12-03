#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

int main() {
    // read input file
    std::ifstream file("input.txt");
    
    /*
    // part 1
    std::string line;
    std::string corrupted;
    std::regex mulPattern("mul\\((\\d+),\\s*(\\d+)\\)");
    
    int sum = 0;
    bool enabled = true;

    while (std::getline(file, line)) {
        corrupted += line;
    }

    std::smatch match;
    std::string::const_iterator begin = corrupted.cbegin();

    while (std::regex_search(begin, corrupted.cend(), match, mulPattern)) {
        int num1 = std::stoi(match[1].str());
        int num2 = std::stoi(match[2].str());
            
        sum += num1 * num2;

        begin = match.suffix().first;
    }

    file.close();
    */

    // part 2
    std::string line;
    std::string corrupted;
    std::regex pattern("mul\\((\\d+),\\s*(\\d+)\\)|don't\\(()\\)|do\\(()\\)");

    int sum = 0;
    bool enabled = true;

    while (std::getline(file, line)) {
        corrupted += line;
    }

    std::smatch match;
    std::string::const_iterator begin = corrupted.cbegin();

    while (std::regex_search(begin, corrupted.cend(), match, pattern)) {
        if (match[0] == "do()") {
            enabled = true;
        }
        else if (match[0] == "don't()") {
            enabled = false;
        }
        else {
            if (enabled) {
                sum += std::stoi(match[1]) * std::stoi(match[2]);
            }
        }
        begin = match.suffix().first;
    }

    std::cout << sum << std::endl;
}
