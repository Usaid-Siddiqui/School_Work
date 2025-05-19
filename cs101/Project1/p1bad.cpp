#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <sstream>
#include <set>
using namespace std;

string lowerToUpper(const string& input) {
    string result = input;
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}

int main(int argc, char** argv) {
    ifstream sourceFile(argv[1]);

    vector<string> identifiers;
    set<string> unique_identifiers;
    map<string, int> from;
    map<string, int> to;

    string inputLine;
    while (getline(sourceFile, inputLine)) {
        stringstream ss(inputLine);
        string source, destination;
        int bandwidth;

        ss >> source >> destination >> bandwidth;

        destination = lowerToUpper(destination);
        source = lowerToUpper(source);

        if (unique_identifiers.find(source) == unique_identifiers.end()) {
            identifiers.push_back(source);
            unique_identifiers.insert(source);
        }
        if (unique_identifiers.find(destination) == unique_identifiers.end()) {
            identifiers.push_back(destination);
            unique_identifiers.insert(destination);
        }

        from[source] += bandwidth;
        to[source] += bandwidth;
    }
    
    sourceFile.close();
    ofstream destFile(argv[2]);

    for (const string& id : identifiers) {
        destFile << id << endl;
    }

    for (const string& id : identifiers) {
        if (from.find(id) != from.end() && to.find(id) != to.end()) {
            int f = from[id];
            int t = to[id];
            double ratio = static_cast<double>(t) / f;
            destFile << id << " " << f << " " << t << " " << fixed << setprecision(2) << ratio << endl;
        }
    }


    destFile.close();
    return 0;
}