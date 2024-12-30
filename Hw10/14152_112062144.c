#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contestant;
typedef void (*Attack)(struct Contestant*, struct Contestant*);

struct Contestant {
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

int main()
{
    struct Contestant contestants[105];
    int num;

    scanf("%d", &num);
    getContestants(contestants, num);

    int idx = 0;
    int temp = 0;
    while(1) {
        if(contestants[idx].health <= 0) {
            idx = (idx + 1) % num;
            continue;
        }

        int targetIndex = findTarget(contestants, idx, num);
        // printf("%d find target %d\n", idx, targetIndex);
        if(targetIndex == idx) {
            break;
        }

        contestants[idx].attackType(&contestants[idx], &contestants[targetIndex]);
        idx = (idx + 1) % num;
    }

    printf("%s wins the tournament\n", contestants[idx].name);

    return 0;
}

void magicalAttack(struct Contestant* self, struct Contestant* target) {
    // printf("%s attack %s, health: %d → ", self->name, target->name, target->health);
    target->health -= ((self->magic > target->resistance) ? (self->magic - target->resistance) : 0);
    // printf("%d\n", target->health);
}

void physicalAttack(struct Contestant* self, struct Contestant* target) {
    // printf("%s attack %s, health: %d → ", self->name, target->name, target->health);
    target->health -= ((self->strength > target->defense) ? (self->strength - target->defense) : 0);
    // printf("%d\n", target->health);
}

void getContestants(struct Contestant* contestants, int len) {
    char c;
    char tmp[10];
    for (int i=0; i<len; i++) {
        scanf("%s %d %d %d %d %d %c", contestants[i].name, &contestants[i].health, &contestants[i].strength, &contestants[i].magic, &contestants[i].defense, &contestants[i].resistance, &c);
        fgets(tmp, 10, stdin);
        contestants[i].attackType = ((c == 'p') ? &physicalAttack : &magicalAttack);
    }
}

int findTarget(struct Contestant* contestants, int idx, int len) {
    int tmp = (idx + 1) % len;
    while(1) {
        if (tmp == idx) return idx;
        if(contestants[tmp].health <= 0) {
            tmp = (tmp + 1) % len;
            continue;
        }
        return tmp;
    }
}