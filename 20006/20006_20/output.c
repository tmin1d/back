#include <stdio.h>
#include "play.h"

void output(Save* save) {
    for (int i = 0; i <= save->part; i++) {
        if (save->storage[i][0] == 1) printf("Started!\n");
        else printf("Waiting!\n");

        for (int j = 0; j < save->element[i]; j++) {
            printf("%d %s\n", save->level[save->storage[i][j + 1]], save->name[save->storage[i][j + 1]]);
        }
    }
}
