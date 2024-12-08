#include <stdio.h>
#include <string.h>

typedef struct save {
    int part;
    int element[301];
    int check;
} Save;

void sortStrings(char arr[][17], Save *save, int storage[][302]) {
    int temp;

    for (int i = 0; i <= save-> part; i++) {
        for (int j = 0; j < save-> element[i]; j++) {
            for (int k = 0; k < save->element[i]; k++) {

                if (strcmp(arr[storage[i][j+1]], arr[storage[i][k+1]]) < 0) {
                    temp = storage[i][j+1];
                    storage[i][j+1] = storage[i][k+ 1];
                    storage[i][k+1] = temp;
                }
            }
        }
    }
}

int main() {
    int max;
    int num;
    int level[301];
    char name[301][17];
    int storage[301][302] = { 0 };

    Save save = { .part = 0, .element = {0}, .check = 0 };

    scanf("%d %d", &num, &max);

    for (int i = 0; i < num; i++) {
        scanf("%d %s", &level[i], name[i]);

        for (int j = 0; j <= save.part; j++) {
            if (save.element[j] != max) {
                if (level[i] >= level[storage[j][1]] - 10 && level[i] <= level[storage[j][1]] + 10) {
                    storage[j][save.element[j] + 1] = i;
                    save.element[j]++;
                    save.check = 1;
                    break;
                }
            }
        }
        if (save.check == 0) {
            save.part++;
            storage[save.part][1] = i;
            save.element[save.part]++;
        }
        save.check = 0;
    }
    
    for (int j = 0; j <= save.part; j++) {
        if (save.element[j] == max) storage[j][0] = 1;
    }
    
    sortStrings(name, &save, storage);

    for (int i = 0; i <= save.part; i++) {
        if (storage[i][0] == 1)
            printf("Started!\n");
        else
            printf("Waiting!\n");

        for (int j = 0; j < save.element[i]; j++) {
            printf("%d %s\n", level[storage[i][j + 1]], name[storage[i][j + 1]]);
        }
    }
    return 0;
}
