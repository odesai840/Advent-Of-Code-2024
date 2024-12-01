#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    // read input file
    std::ifstream file("input.txt");
    
    /*
    // part 1
    std::vector<int> firstList;
    std::vector<int> secondList;
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
    
        if (iss >> num1 >> num2) {
            firstList.push_back(num1);
            secondList.push_back(num2);
        }
    }
    
    file.close();
    
    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());
    
    int distance = 0;
    for (int i = 0; i < firstList.size(); i++) {
        distance += abs(firstList[i] - secondList[i]);
    }
    
    std::cout << distance << std::endl;
    */

    // part 2
    std::vector<long> firstList;
    std::unordered_map<long, int> secondList;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        long num1, num2;

        if (iss >> num1 >> num2) {
            firstList.push_back(num1);
            secondList[num2]++;
        }
    }

    file.close();

    long similarityScore = 0;
    for (const auto& num : firstList) {
        if (secondList.find(num) != secondList.end()) {
            similarityScore += num * secondList[num];
        }
    }

    std::cout << similarityScore << std::endl;
}
