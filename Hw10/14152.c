#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main() {
    struct Contestant contestants[105];
    int num;
    scanf("%d", &num);
    getContestants(contestants, num);

    int idx = 0;
    while (1) {
        if (contestants[idx].health <= 0) {
            idx = (idx + 1) % num;
            continue;
        }

        int targetIndex = findTarget(contestants, idx, num);
        if (targetIndex == idx) {
            break;
        }

        contestants[idx].attackType(&contestants[idx], &contestants[targetIndex]);
        idx = (idx + 1) % num;
    }

    printf("%s wins the tournament\n", contestants[idx].name);

    return 0;
}
