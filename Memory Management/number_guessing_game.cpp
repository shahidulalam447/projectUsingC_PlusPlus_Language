// #include<bits/stdc++.h>
// using namespace std;

// This program demonstrates a simple number guessing game to understand memory management and multithreading.
// It includes headers for necessary libraries and defines functions for generating a random number and guessing the target number.

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <cstdlib>
#include <ctime>
#include <memory>

// Function to generate a random number
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// Function to guess the number
void guessNumber(std::atomic<bool>& found, int target, int threadId) {
    // Loop until the number is found by any thread
    while (!found) {
        int guess = generateRandomNumber(100);
        // Check if the guess matches the target number
        if (guess == target) {
            found = true; // Set the atomic flag to true to signal other threads to stop
            std::cout << "Thread " << threadId << " guessed the number: " << guess << "\n";
        }
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate the target number
    int targetNumber = generateRandomNumber(100);
    // Atomic flag to indicate whether the target number is found
    std::atomic<bool> found(false);

    // Create a vector to store thread objects
    std::vector<std::thread> threads;
    // Spawn multiple threads to guess the number concurrently
    for (int i = 1; i <= 4; ++i) {
        threads.push_back(std::thread(guessNumber, std::ref(found), targetNumber, i));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    // Print the target number after the game ends
    std::cout << "Game Over! The target number was: " << targetNumber << "\n";
    return 0;
}
