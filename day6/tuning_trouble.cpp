#include <iostream>
#include <fstream> 

using namespace std;

string getInputMessage(string fileName) {
    string inputMessage;
    ifstream inputFile;

    inputFile.open(fileName);
    if(!inputFile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    getline(inputFile, inputMessage);

    return inputMessage;
}

bool isSequenceUnique(char inputSequence[4]) {

    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (inputSequence[i] == inputSequence[j]) {
                return false;
            }
        }
    }

    return true;
}

void rotateCharacters(char arr[4]) {
    for (int i = 0; i < 3; i++) {
        arr[i] = arr[i+1];
    }
    return;
}

int findStartOfPacket(string inputMessage) {
    char c;
    int pointer = 0;
    char inputSequence[4];

    for (int i = 0; i < inputMessage.length(); i++) {
        c = inputMessage[i];

        if (pointer < 4) {
            inputSequence[pointer] = c;
        }
        else{
            rotateCharacters(inputSequence);
            inputSequence[3] = c;
            
            if (isSequenceUnique(inputSequence)) {
                return pointer+1;
            }
        }
        pointer++;
    }
        
    return -1;
}

int main(int argc, char const *argv[])
{   
    string fileName = "tuning_trouble_input.txt";
    string inputMessage = getInputMessage(fileName);

    int startOfPacket = findStartOfPacket(inputMessage);

    cout << startOfPacket << '\n';
    
    return 0;
}
