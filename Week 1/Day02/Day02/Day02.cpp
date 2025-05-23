﻿#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    // size() - # of items in the vector
    // capacity() - length of the internal array
    // size() <= capacity()
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//pass by value:
//  creates a new variable
//  copies the value into that spot of memory
void Message(std::string msg)//passed by value (making a copy)
{
    //msg is a new variable.
    // it is initialized when it is called.
    //std::string msg = "Flash is faster than superman?";
    std::cout << msg;
}
//pass by reference
//  a reference variable is created
//  it "points" to the variable that was used when calling
//  the method.
//  think 'alias'
//  prevents a copy
void Message2(std::string& msgByReference)//pass by reference
{
    std::cout << msgByReference;
}

int main()
{
    //scope is the "visibility" of variables
    //{ } defines the scope
    std::string message = "Aquaman smells like fish.";
    Message(message);//msg = message;
    std::string notReference = message;//2 different variables
    notReference = "Superman is an ALIEN!";
    std::string& sameVariable = message;//1 variable, 2 names
    sameVariable = "Yep! definitely an alien!";
    Message2(message);
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            0) create a method above main
            1) pass it in by reference
            2) add 10 grades to the vector
            3) after calling the method, print the grades

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.GetGrades(grades);
    pg2.PrintGrades(grades);



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);//makes the capacity = 10 (internal array of length 10)
    printInfo(highScores);//size: 0  capacity: 0?? 10??
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    highScores.reserve(20);
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    //highScores.clear();
    //printInfo(highScores);//size: 0  capacity: 0? 20?
    //highScores.reserve(5);
    //printInfo(highScores);//size: 0  capacity: 0? 20?
    //highScores.shrink_to_fit();
    //printInfo(highScores);//size: 0  capacity: 0? 20?
    float avg = average(highScores);

    //write code to erase all scores < 2500
    //print the scores


    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500
    for (int i = 0; i < highScores.size(); i++)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
            i--;//move the index back
        }
    }
    //OR...    
    for (int i = 0; i < highScores.size(); )
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
        else
            i++;
    }
    //OR...
    for (int i = highScores.size() - 1; i >= 0; i--)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
    }
    //OR...
    for (auto iter = highScores.begin(); iter != highScores.end();)
    {
        if (*iter < 2500)
        {
            iter = highScores.erase(iter);
        }
        else
            iter++;
    }


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}