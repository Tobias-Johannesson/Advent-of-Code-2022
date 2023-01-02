#include <iostream>
#include <fstream>
#include <string>
// #include <map>


std::string findCommonItem( std::string rucksacks[] ) {
    std::string rucksackOneItem;
    std::string rucksackTwoItem;
    std::string rucksackThreeItem;
    std::string commonItemsBetweenFirstTwo [rucksacks[0].length()];
    std::string potentialCommonItem;

    int numberOfItemsFound = 0;

    for ( int i = 0; i < rucksacks[0].length(); i++ ) {
        rucksackOneItem = rucksacks[0][i];

        for ( int j = 0; j < rucksacks[1].length(); j++ ) {
            rucksackTwoItem = rucksacks[1][j];

            for ( int k = 0; k < numberOfItemsFound; k++) {
                if ( rucksackOneItem == commonItemsBetweenFirstTwo[k] ) {
                    break;
                }
            }

            if ( rucksackOneItem.compare(rucksackTwoItem) == 0 ) {
                commonItemsBetweenFirstTwo[numberOfItemsFound] = rucksackOneItem;
                numberOfItemsFound += 1;
                break;
            }
        }
    }

    for ( int i = 0; i < numberOfItemsFound; i++ ) {
        potentialCommonItem = commonItemsBetweenFirstTwo[i];

        for ( int j = 0; j < rucksacks[2].length(); j++ ) {
            rucksackThreeItem = rucksacks[2][j];

            if ( potentialCommonItem == rucksackThreeItem ) {
                return potentialCommonItem;
            }
        }
    }

    return "";
}

// Or try a dictionary
int getItemPriorityValue( std::string commonItem ) {
    const char *cstr = commonItem.c_str();
    int itemPriorityValue = (int) cstr[0];

    if ( itemPriorityValue >= 97 && itemPriorityValue <= 122 ) {
        itemPriorityValue -= 96;
    }
    else {
        itemPriorityValue -= 38;
    }

    return itemPriorityValue;
}

int main() {
    std::ifstream file ("rucksack_reorganization_input.txt");
    std::string line;

    int totalItemPriorityValues = 0;

    if ( file.is_open() ) {
        std::string elvesRucksacks[3];
        std::string commonItem = "";

        int itemPriorityValue = 0;

        while (file) {  

            for ( int elf = 0; elf < 3; elf++ ) {
                // Handle potential error
                std::getline (file, line);

                if (line != "") {
                    elvesRucksacks[elf] = line;
                }
            }

            if (line != "") {

                commonItem = findCommonItem(elvesRucksacks); 
                itemPriorityValue = getItemPriorityValue(commonItem);

                totalItemPriorityValues += itemPriorityValue;
            }
        }
    }

    std::cout << totalItemPriorityValues << "\n";
}