#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

// Answers: 441, 861

int main()
{

    std::cout << "=========================================\n";
    std::cout << "\nAdvent of Code - Day 4\n\n";
    std::cout << "=========================================\n";

    // Read file content into stack
    std::ifstream input("input4");
    std::string line;
    uint16_t n_full_overlaps = 0;
    uint16_t n_overlaps = 0;
    while (std::getline(input, line)) {
        std::cout << line << "\n";

        uint16_t num = 0;
        std::vector<uint16_t> assignments{};
        for (auto const ch: line) {
            if (ch >= '0' && ch <= '9') {
                num *= 10;
                num += ch - '0';
            } else {
                if (num) {
                    assignments.push_back(num);
                }
                num = 0;
            }
        }
        assert(assignments.size() == 4);

        if ((assignments[0] >= assignments[2] && assignments[1] <= assignments[3]) ||
                (assignments[0] <= assignments[2] && assignments[1] >= assignments[3]))
        {
            n_full_overlaps++;
        }

        if ((assignments[1] >= assignments[2] && assignments[0] <= assignments[3]) ||
        (assignments[2] >= assignments[1] && assignments[3] <= assignments[0]))
        {
            n_overlaps++;
        }




    }
    std::cout << "Full overlaps:" << n_full_overlaps << "\n";
    std::cout << "Overlaps:" << n_overlaps << "\n";
}

