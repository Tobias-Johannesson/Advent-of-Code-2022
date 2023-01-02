#include <iostream>
#include <fstream>
#include <string>
#include <map>


std::string findCommonItem( std::string rucksackOne, std::string rucksackTwo ) {
    std::string rucksackOneItem;
    std::string rucksackTwoItem;

    int numberOfItems = rucksackOne.length();

    for ( int i = 0; i < numberOfItems; i++ ) {
        rucksackOneItem = rucksackOne[i];

        for ( int j = 0; j < numberOfItems; j++ ) {
            rucksackTwoItem = rucksackTwo[j];

            if ( rucksackOneItem == rucksackTwoItem ) {
                return rucksackOneItem;
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
        int currentPriority = 0;
        int lineLength = 0;
        std::string rucksackOne = "";
        std::string rucksackTwo = "";
        std::string commonItem = "";
        int itemPriorityValue = 0;

        while (file) {  
            std::getline (file, line);

            if (line != "") {
                lineLength = line.length();
                rucksackOne = line.substr(0, lineLength/2);
                rucksackTwo = line.substr(lineLength/2, lineLength);

                commonItem = findCommonItem(rucksackOne, rucksackTwo); 
                itemPriorityValue = getItemPriorityValue(commonItem);

                totalItemPriorityValues += itemPriorityValue;
            }
        }
    }

    std::cout << totalItemPriorityValues << "\n";
}