#include <stdio.h>
#include <stdbool.h>

#define N 3

// Function to check if woman w prefers man m over her current partner m1
bool prefers(int preferences[N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (preferences[w][i] == m1)
            return true;
        if (preferences[w][i] == m)
            return false;
    }
    return false;
}

// Function to perform the stable marriage algorithm
void stableMarriage(int preferences[N][N]) {
    int womenPartner[N];
    bool menFree[N];
    
    // Initialize all women as free and all men as free
    for (int i = 0; i < N; i++) {
        womenPartner[i] = -1;
        menFree[i] = true;
    }
    
    int freeCount = N; // Number of free men
    
    // While there are free men
    while (freeCount > 0) {
        int m;
        // Find the first free man
        for (m = 0; m < N; m++) {
            if (menFree[m])
                break;
        }
        
        // For each woman in man's preference list
        for (int i = 0; i < N && menFree[m]; i++) {
            int w = preferences[m][i]; // Woman w is the ith preference of man m
            
            // If woman w is free
            if (womenPartner[w] == -1) {
                womenPartner[w] = m; // Pair m and w
                menFree[m] = false;  // Man m is no longer free
                freeCount--;         // Decrease the number of free men
            } else {
                // If woman w is not free, find her current partner
                int m1 = womenPartner[w];
                
                // If woman w prefers man m over her current partner m1
                if (prefers(preferences, w, m, m1) == false) {
                    womenPartner[w] = m; // Woman w pairs with man m
                    menFree[m] = false;  // Man m is no longer free
                    menFree[m1] = true;  // Man m1 is now free
                }
            }
        }
    }
    
    // Print the stable matches
    printf("Stable matches:\n");
    for (int i = 0; i < N; i++) {
        printf("Woman %d - Man %d\n", i, womenPartner[i]);
    }
}

int main() {
    // Preference lists for men and women
    int preferences[N][N] = {
        {0, 1, 2}, // Preferences of Man 0
        {1, 0, 2}, // Preferences of Man 1
        {0, 1, 2}, // Preferences of Man 2
    };
    
    stableMarriage(preferences); // Find and print stable matches
    return 0;
}