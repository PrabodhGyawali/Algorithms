#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** splitString(char* sentence, int* wordCount) {
    char** words = NULL;
    char* token;
    int count = 0;

    // Coun t the number of words
    char* tempSentence = strdup(sentence);
    token = strtok(tempSentence, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    free(tempSentence);
    
    words = (char**)malloc(count*sizeof(char*));
    if (words == NULL) {
        *wordCount = 0;
        return NULL;
    }
    
    count = 0;
    token = strtok(sentence, " ");
    while (token != NULL)
    {
        words[count] = strdup(token); 
        count++;
        token = strtok(NULL, " ");
    }

    *wordCount = count;
    
    return words;

}

bool areSentenceSimilar(char* sentence1, char* sentence2) {
    if (strcmp(sentence1, sentence2) == 0) 
        return true;
    
    // Find the longest sentence
    int s1_len = 0, s2_len = 0;
   
    char** s1_words = splitString(sentence1, &s1_len);
    char** s2_words = splitString(sentence2, &s2_len);

    int s1si = 0, s1ei = s1_len - 1;
    int s2si = 0, s2ei = s2_len - 1;
    
    // Front match increment
    while (s1si <= s1ei && s2si <= s2ei && strcmp(s1_words[s1si], s2_words[s2si]) == 0) {
        s1si++;
        s2si++;
    }

    // Back match decrement
    while (s1si <= s1ei && s2si <= s2ei && strcmp(s1_words[s1ei], s2_words[s2ei]) == 0) {
        s1ei--;
        s1ei--;
    }

    for (int i = 0; i < s1_len; i++)
    {
        free(s1_words[i]);
    }
    for (int i = 0; i < s2_len; i++)
    {
        free(s2_words[i]);
    }
    free(s1_words);
    free(s2_words);
    
    
    // shortest sentence's end index is less than its start index
    return s1ei < s1si || s2ei < s2si;
}

int main() {
    char sentence1[] = "hello world";
    char sentence2[] = "hello";
    
    bool similar = areSentenceSimilar(sentence1, sentence2);

    printf("Similar: %d\n", similar);

    return 1;
}

// TEST
/*
Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

    Output: true

    sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Input: sentence1 = "of", sentence2 = "A lot of words"

    Output: false

    No single sentence can be inserted inside one of the sentences to make it equal to the other.

Input: sentence1 = "Eating right now", sentence2 = "Eating"

    Output: true

    sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.
*/
