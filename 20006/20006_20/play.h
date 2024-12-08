#pragma once

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
