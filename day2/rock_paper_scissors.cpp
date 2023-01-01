#include <iostream>
#include <fstream>
#include <string>
#include <map>

typedef std::map<std::string, int> Map;


int playerMoveScore(Map moveValues, std::string playerMove) {
    // Handle potential errors
    return moveValues[playerMove];
}

int roundResultsScore(std::string opponentMove, std::string playerMove) {
    // Clean this up
    if ( playerMove == "X" ) {
        if ( opponentMove == "A" ) {
            return 3;
        }
        else if ( opponentMove == "B" ) {
            return 0;
        }
        else if ( opponentMove == "C" ) {
            return 6;
        }
    }
    else if ( playerMove == "Y" ) {
        if ( opponentMove == "A" ) {
            return 6;
        }
        else if ( opponentMove == "B" ) {
            return 3;
        }
        else if ( opponentMove == "C" ) {
            return 0;
        }
    }
    else if ( playerMove == "Z" ) {
        if ( opponentMove == "A" ) {
            return 0;
        }
        else if ( opponentMove == "B" ) {
            return 6;
        }
        else if ( opponentMove == "C" ) {
            return 3;
        }
    }

    return 0; // Error
}

int main() {
    // Map moveValues = { {"X", 1}, {"Y", 2}, {"Z", 3} }; // Make const?
    Map moveValues;
    moveValues["X"] = 1;
    moveValues["Y"] = 2;
    moveValues["Z"] = 3;

    int roundScore = 0;
    int totalScore = 0;
    std::string opponentMove = "";
    std::string playerMove = "";

    std::string line;
    std::ifstream file;
    file.open("rock_paper_scissors_input.txt");

    while (file) {
        std::getline (file, line);

        if ( line.length() > 2 ) {
            opponentMove = line[0];
            playerMove = line[2]; 
            
            roundScore = playerMoveScore(moveValues, playerMove) + roundResultsScore(opponentMove, playerMove);
            totalScore += roundScore;
        }
    }   

    std::cout << totalScore << "\n";
    file.close();
}