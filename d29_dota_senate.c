#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* predictPartyVictory(char* senate) {
    int radiantCount = 0, direCount = 0;
    int radiantBan = 0, direBan = 0;
    int n = strlen(senate);
    bool hasRadiant, hasDire;

    while (true) {
        hasRadiant = false;
        hasDire = false;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                if (radiantBan > 0) {
                    radiantBan--;
                    senate[i] = 'B';  // Ban Radiant senator
                } else {
                    hasRadiant = true;
                    direBan++;  // Ban one Dire senator in the next round
                }
            } else if (senate[i] == 'D') {
                if (direBan > 0) {
                    direBan--;
                    senate[i] = 'B';  // Ban Dire senator
                } else {
                    hasDire = true;
                    radiantBan++;  // Ban one Radiant senator in the next round
                }
            }
        }
        
        if (!hasRadiant) {
            return "Dire";
        } else if (!hasDire) {
            return "Radiant";
        }
    }
}
