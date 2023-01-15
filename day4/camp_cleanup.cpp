#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isTheRangeFullyContained(int elfRanges[4]) {
    int elfOneRangeStart = elfRanges[0]; 
    int elfOneRangeEnd =  elfRanges[1]; 
    int elfTwoRangeStart = elfRanges[2]; 
    int elfTwoRangeEnd =  elfRanges[3]; 

    if (elfOneRangeStart >= elfTwoRangeStart && elfOneRangeEnd <= elfTwoRangeEnd){
        return true;
    } 
    else if (elfTwoRangeStart >= elfOneRangeStart && elfTwoRangeEnd <= elfOneRangeEnd) {
        return true;
    }

    return false;
}

int* getElfRanges (string textLine) {
    int positionOfSplit = textLine.find(",");
    int elfOneRangeStart, elfOneRangeEnd, elfTwoRangeStart, elfTwoRangeEnd = 0;

    string elfOne = textLine.substr(0, positionOfSplit);
    string elfTwo = textLine.substr((positionOfSplit+1), (textLine.length() - positionOfSplit));

    // Function
    positionOfSplit = elfOne.find("-");
    elfOneRangeStart = stoi(elfOne.substr(0, positionOfSplit));
    elfOneRangeEnd = stoi(elfOne.substr((positionOfSplit + 1), (elfOne.length() - positionOfSplit)));

    // Function
    positionOfSplit = elfTwo.find("-");
    elfTwoRangeStart = stoi(elfTwo.substr(0, positionOfSplit));
    elfTwoRangeEnd = stoi(elfTwo.substr((positionOfSplit + 1), (elfTwo.length() - positionOfSplit)));

    int elfRanges[4] = {elfOneRangeStart, elfOneRangeEnd, elfTwoRangeStart, elfTwoRangeEnd};
    // cout << elfRanges[0] << "-" << elfRanges[1] << "," << elfRanges[2] << "-" << elfRanges[3] << "\n"; 
    return elfRanges;
}

int main(int argc, char const *argv[])
{   
    fstream inputFile;
    int pairsContainingFullRange = 0;

    inputFile.open("camp_cleanup_input.txt");  
    if(inputFile.is_open()) 
    {
        string textLine;
        while(getline(inputFile, textLine)){ 
            int* elfRanges = getElfRanges(textLine);

            if (isTheRangeFullyContained(elfRanges)) {
                pairsContainingFullRange += 1;
            } 
        }
    }
    
    inputFile.close();  

    cout << pairsContainingFullRange << "\n";
    
    return 0;
}
