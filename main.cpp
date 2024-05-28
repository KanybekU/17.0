#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for encoding the stories using Run-Length Encoding
void performRunLengthEncoding(const string& input, ofstream& outputFile) {
    int length = input.size(); // Count how many letters we have.
    int i = 0; // Pointer showing which letter we're looking at.

    // Start looking at each letter one by one.
    while (i < length) {
        int count = 1; // Always have at least one of each letter.

        // Count how many times the current character repeats consecutively.
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++; // If the next letter is the same, increase the count.
            i++; // Move to the next letter.
        }
        // Write down the letter and how many times it's repeated.
        outputFile << input[i] << count;

        // Move to the next letter and start again until we reach the end.
        i++;
    }
}

// Function for decoding the stories using Run-Length Decoding
void performRunLengthDecoding(const string& input, ofstream& outputFile) {
    int length = input.size(); // Total length of the encoded message.
    int i = 0; // Pointer indicating which part of the encoded message we are currently decoding.

    // Start decoding the encoded message.
    while (i < length) {
        // Get the character: Each character in the encoded message represents a symbol.
        char character = input[i];

        // Get the integer: The next character after the symbol represents how many times the symbol should be repeated.
        int count = input[i + 1] - '0'; // Convert the character representing the count back to an integer.

        // Write the decoded symbol (character) to the output file the specified number of times (count).
        for (int j = 0; j < count; j++) {
            outputFile << character;
        }

        // Move to the next symbol and its corresponding count in the encoded message.
        i += 2;
    }
}

int main() {
    // Open the input file named "input.txt"
    ifstream inputFile("input.txt");
    // Open the output file named "output.txt"
    ofstream outputFile("output.txt");

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        // If the input file failed to open, display an error message
        cout << "Failed to open the input file." << endl;
        // Return 1 to indicate an error occurred
        return 1;
    }
    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        // If the output file failed to open, display an error message
        cout << "Failed to open the output file." << endl;
        // Return 1 to indicate an error occurred
        return 1;
    }

    // At this point, both input and output files have been successfully opened

    string line; // This is a special notebook where we write down each line of the story from the input file.
    char choice; // This is like a magical button we press to choose whether we want to encode or decode the stories.

    // Ask the magician (user) to choose whether they want to encode or decode the stories.
    cout << "Choose E for encoding and D for decoding: ";
    // The magician (user) makes their choice by pressing a magical button (typing a letter), and we store their choice in the variable 'choice'.
    cin >> choice;

    // Encoding
    if (choice == 'E' || choice == 'e') { // If the magician (user) chose to encode the stories...
        // Read each line of the story from the input file, until there are no more lines left.
        while (getline(inputFile, line)) {
            // Encode the story by using a special code and write the encoded story in a new magical notebook (output file).
            performRunLengthEncoding(line, outputFile);
            // Move to the next line in the magical notebook (output file) to write the next encoded story.
            outputFile << '\n';
        }
    }
    // Decoding
    else if (choice == 'D' || choice == 'd') { // If the magician (user) chose to decode the stories...
        // Read each line of the encoded story from the input file, until there are no more lines left.
        while (getline(inputFile, line)) {
            int lineLength = line.length(); // Count how many letters are in the encoded story.
            int i = 0; // Pointer pointing to each letter of the encoded story.
            // Decode the encoded story and write the original story in a new magical notebook (output file).
            while (i < lineLength) {
                // Get the symbol (letter) from the encoded story.
                char character = line[i];
                // Get the number of times the symbol (letter) is repeated from the encoded story.
                int count = line[i + 1] - '0'; // Convert the character representing the count back to an integer.
                // Write the symbol (letter) the specified number of times (count) in the magical
                    // Write the symbol (letter) the specified number of times (count) in the magical notebook (output file).
                for (int j = 0; j < count; j++) {
                    outputFile << character;
                }
                // Move to the next symbol (letter) and its count in the encoded story.
                i += 2;
            }
        }
    }
    // Invalid Choice
    else {
        // If the magician (user) presses any other button by mistake, the magical box gets confused and displays an error message.
        cout << "Invalid choice." << endl;
    }

    // Close the magical notebook where we read the stories from.
    inputFile.close();
    // Close the magical notebook where we wrote down the encoded or decoded stories.
    outputFile.close();

    // The magical box says goodbye and returns to its peaceful slumber.
    return 0;
}
