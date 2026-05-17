#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void addWord(std::map<std::string, int>& frequencies, std::string& word) {
    if (!word.empty()) {
        ++frequencies[word];
        word.clear();
    }
}

int main(int argc, char* argv[]) {
    std::string filePath;
    if (argc > 1) {
        filePath = argv[1];
    } else {
        std::cout << "Введіть шлях до текстового файлу: ";
        std::getline(std::cin, filePath);
    }

    std::ifstream input(filePath);
    if (!input) {
        std::cerr << "Помилка: не вдалося відкрити файл " << filePath << "\n";
        return 1;
    }

    std::map<std::string, int> frequencies;
    std::string word;
    char character = '\0';
    while (input.get(character)) {
        const auto byte = static_cast<unsigned char>(character);
        if (std::isalnum(byte)) {
            word += static_cast<char>(std::tolower(byte));
        } else {
            addWord(frequencies, word);
        }
    }
    addWord(frequencies, word);

    if (frequencies.empty()) {
        std::cout << "У файлі немає слів.\n";
        return 0;
    }

    std::cout << "Частота слів:\n";
    for (const auto& [currentWord, count] : frequencies) {
        std::cout << currentWord << ": " << count << '\n';
    }
    return 0;
}
