#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to check if a word is a palindrome
bool isPalindrome(const string &str) {
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to check if two words are anagrams
bool areAnagrams(const string &str1, const string &str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    // Count frequency of characters in the first string
    for (char c : str1) {
        charCount[c]++;
    }

    // Decrease the frequency of characters in the second string
    for (char c : str2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false; // If count becomes negative, not an anagram
        }
    }

    return true;
}

int main() {
    // Arrays of words to check
    vector<string> palindromes = {"madam", "racecar", "lalalal"};
    vector<string> anagrams = {"silent", "listen", "vile", "evil", "live"};
    vector<string> validWords;  // To store valid words from the user

    // Display the available words in arrays for the user
    cout << "Available words to choose from:" << endl;
    cout << "Palindromes: ";
    for (const string &word : palindromes) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Anagrams: ";
    for (const string &word : anagrams) {
        cout << word << " ";
    }
    cout << endl;

    string userWord;
    cout << "\nEnter a word from the above lists to check if it's a palindrome or an anagram: ";
    getline(cin, userWord);

    // Check if the word is valid (exists in either palindromes or anagrams arrays)
    bool isValid = false;
    if (find(palindromes.begin(), palindromes.end(), userWord) != palindromes.end() || 
        find(anagrams.begin(), anagrams.end(), userWord) != anagrams.end()) {
        isValid = true;
    }

    // If the word is valid, check if it's a palindrome or an anagram
    if (isValid) {
        // Check for palindrome first
        if (find(palindromes.begin(), palindromes.end(), userWord) != palindromes.end()) {
            cout << userWord << " is a palindrome." << endl;
        }
        
        // Check for anagrams with words in the anagram list
        bool foundAnagram = false;
        if (find(anagrams.begin(), anagrams.end(), userWord) != anagrams.end()) {
            for (const string &word : anagrams) {
                if (word != userWord && areAnagrams(userWord, word)) {
                    cout << userWord << " and " << word << " are anagrams." << endl;
                    foundAnagram = true;
                }
            }
        }
        if (!foundAnagram && find(palindromes.begin(), palindromes.end(), userWord) == palindromes.end()) {
            cout << userWord << " does not have any anagrams in the list." << endl;
        }
    } else {
        // If the word is not valid, inform the user
        cout << "The word '" << userWord << "' is not in the list of available words." << endl;
    }

    return 0;
}
