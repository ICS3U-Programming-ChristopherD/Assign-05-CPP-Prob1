// Copyright (c) 2022 Chris Di Bert All rights reserved.
// .
// Created by: Chris Di Bert
// Date : Dec 9, 2022
// This program calculates the average acceleration of
// an object

#include <iostream>
#include <string>

    float
    AverageAccelerationCalculator(float velocityInitial, float velocityFinal, float time) {
    float averageAcceleration = (velocityFinal - velocityInitial) / time;
    return averageAcceleration;
}

float ErrorChecker(std::string propertyStr) {
    // Tries casting the user's inputs to float
    try {
        float propertyFloat = std::stof(propertyStr);
        return propertyFloat;
        // Returns -1 if casting was unsuccesful
    } catch (...) {
        return -1;
    }
}

int SpecialCases(float velocityInitial, float velocityFinal, float time) {
    // If the user entered a negative time
    if (time < 0) {
        return -2;

        // If time is set to 0 but final velocity is a positive number
    } else if (time == 0 && velocityInitial > 0) {
        return -3;

        // If the time is set to 0 but final velocity is a positive number
    } else if (time == 0 && velocityFinal > 0) {
        return -4;

        // If the user entered 0 for all inputs
    } else if (time == 0 && velocityInitial == 0 && velocityFinal == 0) {
        return -5;
    }
}

int main() {
    std::string restart = "";

    do {
        // Declaring variables
        std::string userVeloInitStr = "", userVeloFinalStr = "",
        userTimeStr = "", units = "", wait;
        float userVeloInitF, userVeloFinalF, userTimeF, averageAcceleration;
        int specialCase;

        // Gets the object's properties from the user
        std::cout << "\n\n\n\n\n\n";
        std::cout << "Enter your units (cm, m, etc): ";
        std::cin >> units;
        std::cout << "Enter the object's initial velocity (" << units << "): ";
        std::cin >> userVeloInitStr;
        std::cout << "Enter the object's final velocity (" << units << "): ";
        std::cin >> userVeloFinalStr;
        std::cout << "Enter the elapsed time (seconds): ";
        std::cin >> userTimeStr;

        // Casts the inputs to float
        userVeloInitF = ErrorChecker(userVeloInitStr);
        userVeloFinalF = ErrorChecker(userVeloFinalStr);
        userTimeF = ErrorChecker(userTimeStr);

        // Body code triggered if any inputs are not numbers
        if (userVeloInitF == -1 || userVeloFinalF == -1 || userTimeF == -1) {
            std::cout << "You must enter numbers for each input.";
            std::cout << "Enter any character to restart: ";
            std::cin >> wait;
            continue;
        }

        // Passes properties to check if the inputs match a special case
        specialCase = SpecialCases(userVeloInitF, userVeloFinalF, userTimeF);

        // Prints potential special cases
        switch (specialCase) {
            // If the user entered a negative time
            case -2:
                std::cout << "Elapsed time cannot be negative.\n";
                std::cout << "Enter any character to restart: ";
                std::cin >> wait;
                continue;

            // If time is set to 0 but final velocity is a positive number
            case -3:
                std::cout << "The average velocity of the object" <<
                " is negative infinity.\n";
                std::cout << "Enter any character to restart: ";
                std::cin >> wait;
                continue;

            // If the time is set to 0 but final velocity is a positive number
            case -4:
                std::cout << "The average velocity of the object"<<
                " is infinite.\n";
                std::cout << "Enter any character to restart: ";
                std::cin >> wait;
                continue;

                // If the user entered 0 for all inputs
            case -5:
                std::cout << "The object is not in motion.\n";
                std::cout << "Enter any character to restart: ";
                std::cin >> wait;
                continue;
        }

        // Gets the average acceleration of the object

        averageAcceleration = AverageAccelerationCalculator(userVeloInitF,
         userVeloFinalF, userTimeF);

        // Displays the average acceleration of the object to the user

        std::cout << "The average acceleration of the object is equal to ";
        std::cout << averageAcceleration << " " << units << "/s^2\n";

        // Asks the user if they would like to restart
        std::cout << "Enter 'q' to quit. Enter anything else to restart.\n >> ";
        std::cin >> restart;
    } while (restart != "q");
}
