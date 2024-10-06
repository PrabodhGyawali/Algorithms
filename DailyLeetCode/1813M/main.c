#include <stdio.h>
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
    
    words = (char**)malloc(count*sizeof(char));
    if (words = NULL) {
        *wordCount = 0;
        return NULL;
    }
    
    count = 0;
    token = strtok(sentence, " ");
    while (token != NULL)
    {
        words[count] = strdup(token); 
        count++;
        strtok(NULL, " ");
    }

    *wordCount = count;
    return words;

}

bool areSentenceSimilar(char* sentence1, char* sentence2) {
    // Find the longest sentence
    int s1_len = 0;
    int s2_len = 0;
    
    while (*(sentence1 + s1_len) != '\0')
    {
        s1_len++;
    }
    while (*(sentence2 + s2_len) != '\0') {
        s2_len++;
    } 

    if (s1_len > s2_len) {
        // Break s1 and s2 into words
        
        // Check if single sentence can be inserted to make long sentence
        // Do an edge check 
        


    }


    return true;
}

int main(void) {
    char* sentence1 = "hello";
    char* sentence2 = "world";
    bool similar = areSentenceSimilar(sentence1, sentence2);
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
