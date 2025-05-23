﻿// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    //Car myRide(1969, "Plymouth", "Hemi Cuda");
    Car myRide("1969,Plymouth,Hemi Cuda", ',');
    std::string fileName = "myGarage.csv";
    std::ofstream outFile(fileName);
    char delimiter = '$';
    if (outFile.is_open())
    {
        //serialize my car
        myRide.Serialize(outFile, delimiter);
    }
    else
        std::cout << fileName << " could not be opened.\n";

    outFile.close();

    std::ifstream inFile(fileName);
    if (inFile.is_open())
    {
        //deserialize my car
        std::string line;
        std::getline(inFile, line);
        Car todaysRide(line, delimiter);
        std::cout << "DESERIALIZED CAR\n";
        todaysRide.Serialize(std::cout, '\t');
        std::cout << "\n";
    }
    else
        std::cout << fileName << " could not be opened.\n";

    inFile.close();


    myRide.Serialize(std::cout, '\t');

    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    fileName = "jaysGarage.csv";
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        int index = 0;
        for (auto& jaysCar : garage)
        {
            jaysCar.Serialize(outputFile, delimiter);
            if(index < garage.size()-1)
                outputFile << "\n";
            index++;
        }
    }
    else
        std::cout << fileName << " could not be opened.\n";

    outputFile.close();

    std::vector<Car> loadedCars;
    std::ifstream inputFile(fileName);
    if (inputFile.is_open())
    {
        while (not inputFile.eof())
        {
            std::string carLine;
            std::getline(inputFile, carLine);
            if (carLine.empty()) continue;
            Car nextCar(carLine, delimiter);
            loadedCars.push_back(nextCar);
        }
    }
    else
        std::cout << fileName << " could not be opened.\n";

    inputFile.close();

    std::cout << "\n\nLoaded Cars\n";
    for (auto& loaded : loadedCars)
    {
        loaded.Serialize(std::cout, '\t');
        std::cout << "\n";
    }


    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
}