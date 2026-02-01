#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints a vector of plant (or flower) object pointers
void PrintVector(const vector<Plant*>& garden) {
    for (const auto& plantPtr : garden) {
        plantPtr->PrintInfo();
    }
}

int main() {
   // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant*> myGarden;

   // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
   //       colorOfFlowers, isAnnual
    string plantName, flowerName, colorOfFlowers;
    int plantCost, flowerCost;
    bool isAnnual;
    string input;
    unsigned int i;

    cin >> input;

    while(input != "-1") {
   // TODO: Check if input is a plant or flower
   //       Store as a plant object or flower object
   //       Add to the vector myGarden
        if (input == "plant") {
            Plant* plantPtr = new Plant();
            for(i = 0,; i < myGarden.size(); ++i) {
                cin >> plantName >> plantCost;
                plantPtr->SetPlantName(plantName);
                plantPtr->SetPlantCost(plantCost);
                myGarden.push_back(plantPtr);
            }
        } else if (input == "flower") {
            Flower* flowerPtr = new Flower();
            for(i = 0,; i < myGarden.size(); ++i) {
                cin >> flowerName >> flowerCost >> isAnnual >> colorOfFlowers;
                flowerPtr->SetPlantName(flowerName);
                flowerPtr->SetPlantCost(flowerCost);
                flowerPtr->SetPlantType(isAnnual);
                flowerPtr->SetColorOfFlowers(colorOfFlowers);
                myGarden.push_back(flowerPtr);
            }
        }
        cin >> input;
    }

   // TODO: Call the method PrintVector to print myGarden
    PrintVector(myGarden);

    for (size_t i = 0; i < myGarden.size(); ++i) {
        delete myGarden.at(i);
    }

    return 0;
}