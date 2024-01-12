#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

   
    if (sLen != tLen) {
        return false;
    }

    // Initialize an array to count the occurrences of each character
    int count[26] = {0}; 


    for (int i = 0; i < sLen; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < tLen; i++) {
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

