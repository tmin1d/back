#include "play.h"


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
