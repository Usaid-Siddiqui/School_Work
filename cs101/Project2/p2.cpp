#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

// Convert a word to lowercase for consistency
string toLower(string word) {
    for (char &c : word) c = tolower(c);
    return word;
}

// Check if a word matches a pattern where '?' can replace exactly one letter
bool matchesPattern(const string &word, const string &pattern) {
    if (word.size() != pattern.size()) return false; // Must be the same length
    
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (pattern[i] != '?' && pattern[i] != word[i]) {
            return false; // Mismatch found
        }
    }
    return true; // Passed all checks
}

int main(int argc, char* argv[]) {
    // Ensure correct usage
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Open file
    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    vector<string> words;          // Stores words in order of appearance
    vector<string> distinctWords;  // Unique words
    vector<int> wordCounts;        // Count of each distinct word

    string word;
    
    // Read words from the file
    while (file >> word) {
        string cleanWord;
        for (char c : word) {
            if (isalpha(c)) {
                cleanWord += tolower(c);
            } else if (!cleanWord.empty()) {
                words.push_back(cleanWord);

                // Check if it's already in distinctWords
                bool found = false;
                for (size_t i = 0; i < distinctWords.size(); ++i) {
                    if (distinctWords[i] == cleanWord) {
                        wordCounts[i]++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    distinctWords.push_back(cleanWord);
                    wordCounts.push_back(1);
                }

                cleanWord.clear();
            }
        }
        if (!cleanWord.empty()) {
            words.push_back(cleanWord);
            bool found = false;
            for (size_t i = 0; i < distinctWords.size(); ++i) {
                if (distinctWords[i] == cleanWord) {
                    wordCounts[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                distinctWords.push_back(cleanWord);
                wordCounts.push_back(1);
            }
        }
    }

    cout << "The number of words found was " << words.size() << endl;
    cout << "The number of distinct words was " << distinctWords.size() << endl;

    // Query processing
    string query;
    while (true) {
        cout << "\nEnter a word: ";
        cin >> query;
        if (query == "STOP") break; // Exit condition

        bool matchFound = false;
        for (size_t i = 0; i < distinctWords.size(); ++i) {
            if (matchesPattern(distinctWords[i], query)) {
                cout << "The word " << distinctWords[i] << " appears " << wordCounts[i] << " times" << endl;
                matchFound = true;
            }
        }

        if (!matchFound) {
            cout << "The word " << query << " appears 0 times" << endl;
        }
    }

    return 0;
}
