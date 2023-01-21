#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <regex>
#include <sstream>

using namespace std;

void checkTopOfEachStack(list<string> supplyPositions[9]) {
    int numberOfStacks = 9;

    for (int i = 0; i < numberOfStacks; i++) {
        cout << supplyPositions[i].back();
    };

    cout << '\n';
}

int main(int argc, char const *argv[])
{   
    // Create an array of linked lists
    list<string> supplyPositions[9];  

    // Move into function or read from inputfile!
    /*
        [T]             [P]     [J]        
        [F]     [S]     [T]     [R]     [B]
        [V]     [M] [H] [S]     [F]     [R]
        [Z]     [P] [Q] [B]     [S] [W] [P]
        [C]     [Q] [R] [D] [Z] [N] [H] [Q]
        [W] [B] [T] [F] [L] [T] [M] [F] [T]
        [S] [R] [Z] [V] [G] [R] [Q] [N] [Z]
        [Q] [Q] [B] [D] [J] [W] [H] [R] [J]
         1   2   3   4   5   6   7   8   9 
    */
    supplyPositions[0].push_back("Q");
    supplyPositions[0].push_back("S");
    supplyPositions[0].push_back("W");
    supplyPositions[0].push_back("C");
    supplyPositions[0].push_back("Z");
    supplyPositions[0].push_back("V");
    supplyPositions[0].push_back("F");
    supplyPositions[0].push_back("T");

    supplyPositions[1].push_back("Q");
    supplyPositions[1].push_back("R");
    supplyPositions[1].push_back("B");

    supplyPositions[2].push_back("B");
    supplyPositions[2].push_back("Z");
    supplyPositions[2].push_back("T");
    supplyPositions[2].push_back("Q");
    supplyPositions[2].push_back("P");
    supplyPositions[2].push_back("M");
    supplyPositions[2].push_back("S");

    supplyPositions[3].push_back("D");
    supplyPositions[3].push_back("V");
    supplyPositions[3].push_back("F");
    supplyPositions[3].push_back("R");
    supplyPositions[3].push_back("Q");
    supplyPositions[3].push_back("H");

    supplyPositions[4].push_back("J");
    supplyPositions[4].push_back("G");
    supplyPositions[4].push_back("L");
    supplyPositions[4].push_back("D");
    supplyPositions[4].push_back("B");
    supplyPositions[4].push_back("S");
    supplyPositions[4].push_back("T");
    supplyPositions[4].push_back("P");

    supplyPositions[5].push_back("W");
    supplyPositions[5].push_back("R");
    supplyPositions[5].push_back("T");
    supplyPositions[5].push_back("Z");

    supplyPositions[6].push_back("H");
    supplyPositions[6].push_back("Q");
    supplyPositions[6].push_back("M");
    supplyPositions[6].push_back("N");
    supplyPositions[6].push_back("S");
    supplyPositions[6].push_back("F");
    supplyPositions[6].push_back("R");
    supplyPositions[6].push_back("J");

    supplyPositions[7].push_back("R");
    supplyPositions[7].push_back("N");
    supplyPositions[7].push_back("F");
    supplyPositions[7].push_back("H");
    supplyPositions[7].push_back("W");

    supplyPositions[8].push_back("J");
    supplyPositions[8].push_back("Z");
    supplyPositions[8].push_back("T");
    supplyPositions[8].push_back("Q");
    supplyPositions[8].push_back("P");
    supplyPositions[8].push_back("R");
    supplyPositions[8].push_back("B");
    
    // Run operations on these linked list line by line
    fstream inputFile;
    inputFile.open("supply_stacks_crane_operations.txt"); 

    if(inputFile.is_open()) 
    {
        string box;
        int i = 0;
        int craneInstruction[3];
        string stringNumber; 
        string craneInstructionLine;
        regex removeLettersPattern("[a-zA-z]+ ");

        while(getline(inputFile, craneInstructionLine)){ 
            // cout << craneInstruction << '\n';
            
            craneInstructionLine = regex_replace(craneInstructionLine, removeLettersPattern, "");
            i = 0;
            stringstream ssin(craneInstructionLine);
            while (ssin.good() && i < 3) {
                ssin >> stringNumber;
                craneInstruction[i] = stoi(stringNumber);
                ++i;
            }
            
            for (int i = craneInstruction[0]; i > 0; i--) {
                box = supplyPositions[craneInstruction[1] - 1].back();
                supplyPositions[craneInstruction[1] - 1].pop_back();

                supplyPositions[craneInstruction[2] - 1].push_back(box);
            };
        }
    }

    inputFile.close();  

    checkTopOfEachStack(supplyPositions);

    return 0;
}
