#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> // For std::pair

int main() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, int >> data; // Vector of pairs
    std::string line;
    
    // Skip the first line (header)
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        std::string category = line.substr(0, commaPos);
        std::string numberPart = line.substr(commaPos + 1);
        int expense = std::stoi(numberPart);
        data.push_back(std::make_pair(category, expense));
    }

    file.close();

    // Visualizing the data
    for (const auto& entry : data) {
        std::cout << entry.first << ": "; // Print the category name
        for (int j = 0; j < entry.second / 10; ++j) { // Print the asterisks
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
