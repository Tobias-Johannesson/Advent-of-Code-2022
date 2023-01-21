#include <iostream>
#include <fstream> 

using namespace std;

const int lengthOfMarker = 14;

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

bool isSequenceUnique(char inputSequence[lengthOfMarker]) {

    for (int i = 0; i < lengthOfMarker; i++) {
        for (int j = i+1; j < lengthOfMarker; j++) {
            if (inputSequence[i] == inputSequence[j]) {
                return false;
            }
        }
    }

    return true;
}

void rotateCharacters(char arr[lengthOfMarker]) {
    for (int i = 0; i < lengthOfMarker-1; i++) {
        arr[i] = arr[i+1];
    }
    return;
}

int findStartOfPacket(string inputMessage) {
    char c;
    int pointer = 0;
    char inputSequence[lengthOfMarker];

    for (int i = 0; i < inputMessage.length(); i++) {
        c = inputMessage[i];

        if (pointer < lengthOfMarker) {
            inputSequence[pointer] = c;
        }
        else{
            rotateCharacters(inputSequence);
            inputSequence[lengthOfMarker-1] = c;
            
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
