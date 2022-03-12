#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream wordlist;
  wordlist.open("wordlist.txt");

  char letter;
  char position;
  cout << "Position: ";
  for (bool read = true; letter = getchar();) {
    cout << "Position: ";
  }
  string word;
  for (int count = 0; getline(wordlist, word); count++) {
    if (word == "hello") {
      char first = word[0];
      cout << first << endl;
      break;
    }
  }
  return 0;
}
