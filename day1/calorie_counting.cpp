#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::ifstream inputFile ("calorie_counting_input.txt");
    std::string fileContentsLine;

    if ( inputFile.is_open() ) { // always check whether the file is open
        int currentElfsCalories = 0;
        int maximumElfCalories = -1;

        while ( inputFile ) {
            std::getline (inputFile, fileContentsLine);
            // fileContentsLine.erase(std::remove(fileContentsLine.begin(), fileContentsLine.end(), '\n'), fileContentsLine.end());
            
            if (fileContentsLine == "") {
                // std::cout << currentElfsCalories << "\n"; 
                if ( currentElfsCalories > maximumElfCalories ) {
                    maximumElfCalories = currentElfsCalories;
                }
                
                currentElfsCalories = 0;
            }
            else {
                currentElfsCalories += std::stoi(fileContentsLine);
            }
        }

        std::cout << maximumElfCalories << "\n";
    }

    inputFile.close();
}