#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int part1(std::vector<std::string>& grid) {
    int count = 0;
    std::vector<std::pair<int, int>> dirs{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}
    };

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'X') {
                for (const auto& dir : dirs) {
                    bool match = true;

                    for (int k = 1; k < 4; k++) {
                        int ni = i + k * dir.first;
                        int nj = j + k * dir.second;

                        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[i].size() || grid[ni][nj] != "XMAS"[k]) {
                            match = false;
                            break;
                        }
                    }

                    if (match) count++;
                }
            }
        }
    }
    return count;
}

int part2(std::vector<std::string>& grid) {
    int count = 0;
    std::vector<std::pair<int, int>> dirs{
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1}
    };

    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[i].size() - 1; j++) {
            if (grid[i][j] == 'A') {
                // top left to bottom right
                bool tl_br = (grid[i + dirs[1].first][j + dirs[1].second] == 'M' &&
                    grid[i + dirs[0].first][j + dirs[0].second] == 'S') ||
                    (grid[i + dirs[1].first][j + dirs[1].second] == 'S' &&
                    grid[i + dirs[0].first][j + dirs[0].second] == 'M');

                // top right to bottom left
                bool tr_bl = (grid[i + dirs[3].first][j + dirs[3].second] == 'M' &&
                    grid[i + dirs[2].first][j + dirs[2].second] == 'S') ||
                    (grid[i + dirs[3].first][j + dirs[3].second] == 'S' &&
                    grid[i + dirs[2].first][j + dirs[2].second] == 'M');

                if (tl_br && tr_bl) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    // read input file
    std::ifstream file("input.txt");
    
    std::string line;
    std::vector<std::string> grid;

    while (std::getline(file, line)) {
        grid.push_back(line);
    }
    file.close();

    // part 1
    //std::cout << part1(grid) << std::endl;

    // part 2
    std::cout << part2(grid) << std::endl;
}
