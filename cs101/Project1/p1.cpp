#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

string toUpper(const string& str) {
    string result = str;
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    vector<string> identifiers;
    set<string> uniqueIdentifiers;
    map<string, int> bandwidthFrom;
    map<string, int> bandwidthTo;

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string source, destination;
        int bandwidth;

        ss >> source >> destination >> bandwidth;

        source = toUpper(source);
        destination = toUpper(destination);

        if (uniqueIdentifiers.find(source) == uniqueIdentifiers.end()) {
            identifiers.push_back(source);
            uniqueIdentifiers.insert(source);
        }
        if (uniqueIdentifiers.find(destination) == uniqueIdentifiers.end()) {
            identifiers.push_back(destination);
            uniqueIdentifiers.insert(destination);
        }

        bandwidthFrom[source] += bandwidth;
        bandwidthTo[destination] += bandwidth;
    }
    inFile.close();

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    for (const string& id : identifiers) {
        outFile << id << endl;
    }

    outFile << endl;

    for (const string& id : identifiers) {
        if (bandwidthFrom.find(id) != bandwidthFrom.end() && bandwidthTo.find(id) != bandwidthTo.end()) {
            int from = bandwidthFrom[id];
            int to = bandwidthTo[id];
            double ratio = static_cast<double>(to) / from;
            outFile << id << " " << from << " " << to << " " << fixed << setprecision(2) << ratio << endl;
        }
    }

    outFile.close();
    return 0;
}