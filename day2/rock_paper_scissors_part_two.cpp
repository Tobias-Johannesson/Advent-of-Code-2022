#include <iostream>
#include <fstream>
#include <string>
#include <map>

typedef std::map<std::string, int> Map;


int roundResultsScore(Map roundResultsValues, std::string roundResult) {
    // Handle potential errors
    return roundResultsValues[roundResult];
}

int getPlayerMoveValue(std::string opponentMove, std::string roundResult) {
    if ( roundResult == "X" ) {
        if ( opponentMove == "A" ) {
            return 3;
        }
        else if ( opponentMove == "B" ) {
            return 1;
        }
        else if ( opponentMove == "C" ) {
            return 2;
        }
    }
    else if ( roundResult == "Y" ) {
        if ( opponentMove == "A" ) {
            return 1;
        }
        else if ( opponentMove == "B" ) {
            return 2;
        }
        else if ( opponentMove == "C" ) {
            return 3;
        }
    }
    else if ( roundResult == "Z" ) {
        if ( opponentMove == "A" ) {
            return 2;
        }
        else if ( opponentMove == "B" ) {
            return 3;
        }
        else if ( opponentMove == "C" ) {
            return 1;
        }
    }

    return 0; //Error
}

int main() {
    Map roundResultsValues;
    roundResultsValues["X"] = 0;
    roundResultsValues["Y"] = 3;
    roundResultsValues["Z"] = 6;

    int roundScore = 0;
    int totalScore = 0;
    std::string opponentMove = "";
    std::string playerMove = "";
    std::string roundResult = "";

    std::string line;
    std::ifstream file;
    file.open("rock_paper_scissors_input.txt");

    while (file) {
        std::getline (file, line);

        if ( line.length() > 2 ) {
            opponentMove = line[0];
            roundResult = line[2]; 

            roundScore = roundResultsScore(roundResultsValues, roundResult) + getPlayerMoveValue(opponentMove, roundResult);
            totalScore += roundScore;
        }
    }   

    std::cout << totalScore << "\n";
    file.close();
}