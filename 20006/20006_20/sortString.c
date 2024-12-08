#include "play.h"


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
