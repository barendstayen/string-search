#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {
    std::string filename = "input.txt";

    // load file in to string
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(in)),
                      std::istreambuf_iterator<char>());


    // pattern list
    std::vector<std::string> patterns = {"test", "example"};

    std::cout << "loaded text size: " << text.size() << "\n";
    std::cout << "patterns count: " << patterns.size() << "\n";

    return 0;
}

