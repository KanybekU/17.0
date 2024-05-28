#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Run-Length Encoding
void performRunLengthEncoding(const string& input, ofstream& outputFile) {
    int length = input.size();
    int i = 0;
    while (i < length) {
        int count = 1;
        // // Count how many times the current character repeats consecutively
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        // Write the character and its count to the output file
        outputFile << input[i] << count;
        i++;
    }
}

//Run-Length Decoding
void performRunLengthDecoding(const string& input, ofstream& outputFile) {
    int length = input.size();
    int i = 0;
    while (i < length) {
        // Get the character
        char character = input[i];
        // Get the integer
        int count = input[i + 1] - '0';
        // the output file
        for (int j = 0; j < count; j++) {
            outputFile << character;
        }
        i += 2;
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    // Check if input file is opened successfully
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }
    // Check if output file is opened successfully
    if (!outputFile.is_open()) {
        cout << "Failed to open the output file." << endl;
        return 1;
    }

    string line;
    char choice;
    cout << "Choose E for encoding and D for decoding: ";
    cin >> choice;

    // Encoding
    if (choice == 'E' || choice == 'e') {
        
        while (getline(inputFile, line)) {
            performRunLengthEncoding(line, outputFile);
            outputFile << '\n';
        }
    }
    // Decoding
    else if (choice == 'D' || choice == 'd') {
        while (getline(inputFile, line)) {
            int lineLength = line.length();
            int i = 0;
            while (i < lineLength) {
                // Get the character
                char character = line[i];
                // Get the  integer
                int count = line[i + 1] - '0';
                //the output file
                for (int j = 0; j < count; j++) {
                    outputFile << character;
                }
                i += 2;
            }
        }
    }
    else {
        cout << "Invalid choice." << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
