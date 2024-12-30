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