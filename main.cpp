#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <list>
#include <map>

using namespace std;

int main(int argc, const char *argv[]) {
    ifstream inputFile;
    ofstream outputFile;
    stringstream argToStr;
    string fileName = "";
    string fileSet = "";
    string fileList = "";
    string fileMap = "";
    map<string, string> wordMap;
    set<string> wordSet;
    list<string> wordList;
    string alphaTest = "";
    string last = "";
    
    //Error handling: argv[]
    if (argc > 1) {
        argToStr << argv[1];
        fileName = argToStr.str();
        
        fileSet = fileName + "_set.txt";
        fileList = fileName + "_list.txt";
        fileMap = fileName + "_1_1.txt";
    }
    else {
        cout << "Not enough arguments\n\n";
        return -1;
    }
    
    inputFile.open("1nephi.txt");
    if  (!inputFile.is_open()) {
        cout << "Error opening file.\n\n";
    }
    else {
        cout << "File open. Now cleaning...\n\n";
        
        while (!inputFile.eof()) {
            inputFile >> alphaTest;
            
            
            for (int i = 0; i < alphaTest.length(); i++) {
                if (!isalpha(alphaTest.at(i))) {
                    alphaTest.erase(i);
                }
            }
            
            wordSet.insert(alphaTest);
            wordList.push_back(alphaTest);
        }
        
        for (list<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            wordMap[last] = *it;
            last = *it;
        }
       
        
        outputFile.open(fileSet.c_str());
        for (set<string>::iterator it = wordSet.begin(); it != wordSet.end(); ++it) {
            outputFile << *it << endl;
            cout << *it << endl;
        }
        outputFile.close();
        
        outputFile.open(fileList.c_str());
        for (list<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            outputFile << *it << endl;
        }
        outputFile.close();
        
        outputFile.open(fileMap.c_str());
        for (map<string, string>::iterator it = wordMap.begin(); it != wordMap.end(); ++it) {
            outputFile << it->first << ", " << it->second << endl;
        }
        outputFile.close();
    }
    
    return 0;
}