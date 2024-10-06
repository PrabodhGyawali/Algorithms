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
    
    // Find the longest sentence
    int s1_len = 0;
    int s2_len = 0;
   
    char** s1_words = splitString(sentence1, &s1_len);
    char** s2_words = splitString(sentence2, &s2_len);

    if (s1_len > s2_len) {
        // Do an edge similarity check 
        for (int i = 0; i < s2_len; i++)
        {
            bool front = false;
            bool back = false;
            // Check front match
            if (strcmp(s1_words[i], s2_words[i]) == 0) {
                front = true;
            }
            // Check back match
            if (stcmp(s1_words[s1_len - 1], s1_words[s2_len -1]) == 0) {
                back = true;
            }
        }
        return true;
    }
    else if (s2_len > s1_len) {
        // Do an edge similarity check 
        for (int i = 0; i < s2_len; i++)
        {
            bool front = false;
            int front_count = 0;
            
            bool back = false;
            int back_count = 0;
            // Check front match
            if (strcmp(s1_words[i], s2_words[i]) == 0) {
                front = true;
                front_count++;
            }
            // Check back match
            if (stcmp(s1_words[s1_len - 1], s1_words[s2_len -1]) == 0) {
                back = true;
                back_count++;
            }
        }
        return true;
    }
    else {
        for (int i = 0; i < s1_len; i++)
        {
            if (strcmp(s1_words[i], s2_words[i]) != 0) {
                return false;
            }
        }
        return true;
    }


    return true;
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
