#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::ifstream inputFile ("calorie_counting_input.txt");
    std::string fileContentsLine;

    if ( inputFile.is_open() ) { // always check whether the file is open
        int currentElfsCalories = 0;
        int maximumElfCalories[] = {-1, -1, -1};

        while ( inputFile ) {
            std::getline (inputFile, fileContentsLine);
            // fileContentsLine.erase(std::remove(fileContentsLine.begin(), fileContentsLine.end(), '\n'), fileContentsLine.end());
            
            if (fileContentsLine == "") {
                
                if ( currentElfsCalories > maximumElfCalories[0] ) {
                    maximumElfCalories[2] = maximumElfCalories[1];
                    maximumElfCalories[1] = maximumElfCalories[0];
                    maximumElfCalories[0] = currentElfsCalories;
                }
                else if ( currentElfsCalories > maximumElfCalories[1] )
                {
                    maximumElfCalories[2] = maximumElfCalories[1];
                    maximumElfCalories[1] = currentElfsCalories;
                }
                else if ( currentElfsCalories > maximumElfCalories[2] ) {
                    maximumElfCalories[2] = currentElfsCalories;
                }

                currentElfsCalories = 0;
            }
            else {
                currentElfsCalories += std::stoi(fileContentsLine);
            }
        }

        int topElvesCaloriesTotal = maximumElfCalories[0] + maximumElfCalories[1] + maximumElfCalories[2];
        std::cout << topElvesCaloriesTotal << "\n";
    }

    inputFile.close();
}