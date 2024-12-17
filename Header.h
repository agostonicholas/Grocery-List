#pragma once
#include <string>
#include <unordered_map>

class WordProcessor {
public:
    // constructor
    WordProcessor() = default;

    // reads file and counts the frequency
    void wordCounter(const std::string& filePath);

    // the count of words
    void displayIntCount() const;

    // histogram of word counts
    void displayHistCount() const;

    // word counts for input
    void displayUserInputCount() const;

    // menu options
    void menuOptions() const;
    
    // file writing
    void dataBackup(const std::string& outputFile);

private:
    // variable to store word counts
    std::unordered_map<std::string, int> wordCount;
};