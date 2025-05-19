#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct SortRule {
    string column;          //name of column that is being sorted by
    bool ascending;         //0 for ascending order, 1 for descending
    string type;            //type of data (int,double,float, etc.)
};

class CSVTable {
    vector<vector<string>> data;        //vector of vectors that contains each row of strings
    vector<string> headers;             //first row headers vector
    map<string, int> col_index;         //index number for each column in order of header appearance
    
public:
    void load(const string& filename) {
        ifstream file(filename);
        string line;
        
        // Read headers
        getline(file, line);
        stringstream ss(line);
        string header;
        while (getline(ss, header, ',')) {
            headers.push_back(header);
            col_index[header] = headers.size() - 1;
        }

        // Read data
        while (getline(file, line)) {
            vector<string> row;             //temporary vector to store each row vector before it is pushed back into main data double vector
            stringstream ss(line);
            string value;                   //string conataining data, still in string form
            while (getline(ss, value, ',')) {
                row.push_back(value);
            }
            data.push_back(row);
        }
    }

    void save(const string& filename) {
        ofstream file(filename);
        
        // Write headers
        for (size_t i = 0; i < headers.size(); i++) {
            file << headers[i] << (i < headers.size()-1 ? "," : "\n");          //headers rewritten onto output file
        }

        // Write data
        for (auto& row : data) {                                                //auto& keyword used to generalize it to all data types
            for (size_t i = 0; i < row.size(); i++) {
                file << row[i] << (i < row.size()-1 ? "," : "\n");              //data rewritten onto output file
            }
        }
    }

    void sort(const vector<SortRule>& rules) {
        auto compare = [&](const vector<string>& a, const vector<string>& b) {  //actual comparison logic contained here inside lambda function
            for (auto& rule : rules) {                                          //goes through sorting rules in order. first one is the primary key
                int i = col_index[rule.column];
                if (rule.type == "int") {
                    int a_val = stoi(a[i]), b_val = stoi(b[i]);                 //convert strings to ints and compare
                    if (a_val != b_val) return rule.ascending ? a_val < b_val : a_val > b_val;
                }
                else if (rule.type == "float") {
                    float a_val = stof(a[i]), b_val = stof(b[i]);               //converts strings to floats and compares
                    if (a_val != b_val) return rule.ascending ? a_val < b_val : a_val > b_val;
                }
                else if (a[i] != b[i]) {                                        //for all other data types compare directly
                    return rule.ascending ? a[i] < b[i] : a[i] > b[i];
                }
            }
            return false;
        };
        stable_sort(data.begin(), data.end(), compare);                         //stable sort necessary to preserve order of equal values. Uses compare lambda defined above
    }
};

vector<SortRule> readRules(const string& filename) {                            //read sort rules and create key in order
    vector<SortRule> rules;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string col, dir, type;
        getline(ss, col, ',');
        getline(ss, dir, ',');
        getline(ss, type, ',');
        rules.push_back({col, dir == "ascend", type});
    }
    return rules;
}

int main(int argc, char* argv[]) {
    CSVTable table;
    table.load(argv[1]);                        //read table
    auto rules = readRules(argv[2]);            //read rules
    table.sort(rules);                          //sort table
    table.save(argv[3]);                        //output table
    return 0;
}