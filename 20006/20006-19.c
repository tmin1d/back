#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct save {
    int part;
    int element[301];
    int check;
    int storage[301][302];
    int num;
    int max;
    int level[301];
    char name[301][17];
} Save;

void play_enter(Save* save);
void sortStrings(Save* save);
void output(Save* save);

int main() {
    Save save = { .part = 0, .element = {0}, .check = 0, .storage = {0} };

    scanf("%d %d", &save.num, &save.max);

    for (int i = 0; i < save.num; i++) {
        scanf("%d %s", &save.level[i], save.name[i]);
    }

    play_enter(&save);
    sortStrings(&save);
    output(&save);

    return 0;
}

void play_enter(Save* save) {
    for (int i = 0; i < save->num; i++) {
        int assigned = 0;
        for (int j = 0; j <= save->part; j++) {
            if (save->element[j] != save->max) {
                int ref_level = save->level[save->storage[j][1]];
                if (save->level[i] >= ref_level - 10 && save->level[i] <= ref_level + 10) {
                    save->storage[j][save->element[j] + 1] = i;
                    save->element[j]++;
                    assigned = 1;
                    break;
                }
            }
        }
        if (!assigned) {
            save->part++;
            save->storage[save->part][1] = i;
            save->element[save->part]++;
        }
    }

    for (int j = 0; j <= save->part; j++) {
        if (save->element[j] == save->max) save->storage[j][0] = 1;
    }
}

void sortStrings(Save* save) {
    int temp;

    for (int i = 0; i <= save->part; i++) {
        for (int j = 0; j < save->element[i] - 1; j++) {
            for (int k = j + 1; k < save->element[i]; k++) {
                if (strcmp(save->name[save->storage[i][j + 1]], save->name[save->storage[i][k + 1]]) > 0) {
                    temp = save->storage[i][j + 1];
                    save->storage[i][j + 1] = save->storage[i][k + 1];
                    save->storage[i][k + 1] = temp;
                }
            }
        }
    }
}

void output(Save* save) {
    for (int i = 0; i <= save->part; i++) {
        if (save->storage[i][0] == 1)
            printf("Started!\n");
        else
            printf("Waiting!\n");

        for (int j = 0; j < save->element[i]; j++) {
            printf("%d %s\n", save->level[save->storage[i][j + 1]], save->name[save->storage[i][j + 1]]);
        }
    }
}
