#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Given a string s1 and its anagram s2, return the smallest number of
// chararcter swaps in s1 required to match s2.

int anagram_least_swap_count (string s1, string s2) {
  int swapcount = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      char found = 'n';
      for (int j = i; j < s1.length(); j++) {
        char temp = s1[i];
        s2[i] == s1[j] && found == 'n' ? s1[i] = s1[j], s1[j] = temp, swapcount++, found = 'y' : temp = 0; 
      }
    } 
  } return swapcount;
}

int main() {
  string string1 = "repesadfasdfeat"; 
  string string2 = "epater";
  cout << anagram_least_swap_count(string1, string2);
}


