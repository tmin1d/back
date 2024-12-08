#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "play.h"


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
