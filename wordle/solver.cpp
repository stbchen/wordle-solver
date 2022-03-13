#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

    // Take in the word list
    ifstream wordlist;
    wordlist.open("wordlist.txt");

    // Take in the gray letters
    string gray;
    cout << "Enter gray letters (0 = none): ";
    cin >> gray;
    int cnt = gray.length();

    string temp;
    string yellow;
    for (bool read = true; read;) {
        cout << "Enter yellow letter: ";
        cin >> temp;
        yellow += temp;
        cout << "Done? (y/n) ";
        cin >> temp;
        if (temp == "y") {
            read = false;
        } else {
            read = true;
        }
    }

    long unsigned int l = yellow.length() / 5;
    string positions[l];
    for (long unsigned int go = 0; go < l; go++) {
        positions[go] = yellow.substr(0, 5);
        yellow.erase(0, 5);
    }

    string green = "00000";
    cout << "Input green letters: ";
    cin >> temp;
    int amount = 0;
    for (int index = 0; index < 5; index++) {
        if (temp[index] != '0') {
            green[index] = temp[index];
            amount++;
        }
    }

    // Debug statements
    char let;
    cout << "green: " << green << endl;
    cout << "gray: " << gray << endl;
    cout << "yellow: ";
    for (unsigned long int c = 0; c < l; c++) {
        for (int i = 0; i < 5; i++) {
            if (positions[c][i] != '0') {
                let = positions[c][i];
                cout << let;
                break;
            }
        }
    }
    cout << endl;

    // Loops through each word and checks for green, yellow, and gray
    string word;
    for (; getline(wordlist, word);) {
        int correct = 0;
        bool in = true;
        long unsigned int yellownum = 0;

        // Loop through each letter
        for (int index = 0; index < 5; index++) {

            // Check if word has correct green letters
            if (word[index] == green[index]) {
                correct++;
            }

            // Loop through gray letters, check if in word
            for (int c = 0; c < cnt; c++) {
                if (gray[c] == word[index]) {
                    in = false;
                }
            }

            // Loop through the array of yellow letters
            for (unsigned long int c = 0; c < l; c++) {

                // Loop through each letter in each array element
                for (int i = 0; i < 5; i++) {

                    // Gets the yellow letter in array element
                    if (positions[c][i] != '0') {
                        let = positions[c][i];
                        break;
                    }
                }

                // Check if word has yellow letter
                if (word[index] == let) {

                    // Check if letter is in valid position
                    if (positions[c][index] == '0') {
                        yellownum++;
                        break;
                    }
                }
            }
        }

        // Prints out valid words
        if (correct == amount && in && yellownum >= l) {
            cout << "possible word: " << word << endl;
        }
    }

    // Close files and exit program
    wordlist.close();
    return 0;
}
