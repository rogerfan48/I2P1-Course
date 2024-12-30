#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contestant;
typedef void (*Attack)(struct Contestant*, struct Contestant*);

struct Contestant
{
    char name[100];
    int health;
    int strength;
    int magic;
    int defense;
    int resistance;
    Attack attackType;
};

void magicalAttack(struct Contestant* self, struct Contestant* target);
void physicalAttack(struct Contestant* self, struct Contestant* target);
void getContestants(struct Contestant* contestants, int len);
int findTarget(struct Contestant* contestants, int idx, int len);

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

void magicalAttack(struct Contestant* self, struct Contestant* target) {
    target->health -= (self->magic > target->resistance) ? (self->magic - target->resistance) : 0;
}
void physicalAttack(struct Contestant* self, struct Contestant* target) {
    target->health -= (self->strength > target->defense) ? (self->strength - target->defense) : 0;

}
void getContestants(struct Contestant* contestants, int len) {
    char c;
    char tmp[10];
    for (int i=0; i<len; i++) {
        scanf("%s %d %d %d %d %d %c", contestants[i].name, &contestants[i].health, &contestants[i].strength, &contestants[i].magic, &contestants[i].defense, &contestants[i].resistance, &c);
        scanf("%s", tmp);
        contestants[i].attackType = (c=='p') ? &physicalAttack : &magicalAttack;
    }
}
int findTarget(struct Contestant* contestants, int idx, int len) {
    int tIdx = (idx+1) % len;
    while (tIdx != idx) {
        if (contestants[tIdx].health <= 0) {
            tIdx = (tIdx+1) % len;
            continue;
        }
        return tIdx;
    }
    return idx;
}