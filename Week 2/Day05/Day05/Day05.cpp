// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//contains? bool. 
//search: where it is in the collection? index.

const int NOT_FOUND = -1;

/// <summary>
/// Will search a vector of ints for a specific number.
/// </summary>
/// <param name="nummies">The vector to search.</param>
/// <param name="searchNumber">The number to look for.</param>
/// <returns>-1 if not found. The index if found.</returns>
int LinearSearch(const std::vector<int>& nummies, int searchNumber)
{
    int index = NOT_FOUND;//-1 means not found
    for (int i = 0; i < nummies.size(); i++)
    {
        if (searchNumber == nummies[i])
        {
            index = i;
            break;
        }
    }
    return index;
}


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 0;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found.\n";
    }
    else
    {
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map <std::string, float> menu;
    menu["Baconator"] = 7.69F;//added a key-value pair to the map
    menu["Hot Hoagie"] = 7.69F;//added a key-value pair to the map
    menu["Avocado Burger"] = 11.99F;//added a key-value pair to the map
    menu["Avocado Burger"] = 14.99F;//added a key-value pair to the map. OVERWRITES!
    
    //insert a pair object into the map
    //pairs have 2 parts: first and second
    std::pair<std::string, float> insertObj = std::make_pair("Cheez Pizza", 4.99f);
    auto wasInsertedOrNot = menu.insert(insertObj);//will NOT overwrite if the key already exists in the map
    if (not wasInsertedOrNot.second)
    {
        std::cout << insertObj.first << " was not inserted. Do you want to overwrite?\n";
    }


    //iterator loop
    std::cout << "\n\nIterator loop:\n";
    for (auto menuIterator = menu.begin(); menuIterator != menu.end(); menuIterator++)
    {
        std::cout << std::setw(15) << std::left << menuIterator->first;
        std::cout << std::setw(7) << std::right << menuIterator->second << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\nRange-Based For loop:\n";
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << std::setw(15) << std::left << itemName;
        std::cout << std::setw(7) << std::right << itemPrice << "\n";
    }

    std::string itemToFind = "Cheez Pizza";
    auto menuIter = menu.find(itemToFind);
    if (menuIter == menu.end()) //not found
        std::cout << itemToFind << " was not on the menu. Try McDonald's!\n\n";
    else
    {
        float oldPrice = menuIter->second;
        //menuIter->first = "Cheese Pizza";
        menuIter->second = oldPrice * 1.10;
        std::cout << itemToFind << " used to costs " << oldPrice << "\n";
        std::cout << "Now it costs " << menuIter->second << ". Thanks PUTIN!\n\n";
    }

    //loop over the map
    //      print the student name
    //      if grade < 59.5, set color to red
    // 
    //      print the student grade with a specific color


    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */

    std::vector<std::string> students = {
        "Anthony", "Edwin", "Eric", "Israel", "Jennifer", "Joseph", "Justin", "Saidai", "Garrett",
"Calvin","Renee","Hazael","Elias","Misael","Gavin","Punam","Marcellus","Aaron","Abigail","Angel","Abram" };

    srand(time(NULL));//seeds rand
    std::map<std::string, double> grades;
    for (auto& studentName : students)
    {
        grades[studentName] = rand() % 10001 / 100.0;
        //OR...
        //auto studentInserted = grades.insert(std::make_pair(studentName, rand() % 10001 / 100.0));
        //if (not studentInserted.second)
        //{
        //    //ask to overwrite
        //}
    }

    std::cout << "\n\nIterator loop:\n";
    for (auto gradeIter = grades.begin(); gradeIter != grades.end(); gradeIter++)
    {
        //first is the key
        //second is the value for the key
        std::cout << std::setw(15) << std::left << gradeIter->first;
        std::cout << std::setw(7) << std::right << gradeIter->second << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\nRange-Based For loop:\n";
    for (auto& [studentName, studentGrade] : grades)
    {
        std::cout << std::setw(15) << std::left << studentName;
        Console::SetForegroundColor(
            //ternary operator
            (studentGrade < 59.5) ? ConsoleColor::Red : 
            (studentGrade < 69.5) ? ConsoleColor::Yellow :
            (studentGrade < 79.5) ? ConsoleColor::Magenta :
            (studentGrade < 89.5) ? ConsoleColor::Blue :
            ConsoleColor::Green
        );
        std::cout << std::setw(7) << std::right << studentGrade << "\n";
        Console::Reset();
    }
    std::cout << "\n\n";






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an existing value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}