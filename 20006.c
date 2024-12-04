#include <stdio.h>
#include <string.h>

char player_name[17], char_team[300][300][17], char_temp[17];

int main() {
    int player_num, team_num, player_level, int_team[300][300], team_cnt = 0, team_idx[300] = { 0, }, i, j, k, check = 0, int_temp;

    scanf_s("%d %d", &player_num, &team_num);

    for (i = 0; i < player_num; i++) {
        scanf_s("%d %s", &player_level, player_name, 17);

        if (i == 0) {
            int_team[0][0] = player_level;
            strncpy_s(char_team[0][0], sizeof(char_team[0][0]), player_name, 17);  
            team_cnt++;
            team_idx[0]++;
        }
        else {
            check = 0; 
            for (j = 0; j < team_cnt; j++) {
                int level_gap = int_team[j][0] - player_level;
                if ((level_gap >= -10 && level_gap <= 10) && team_idx[j] < team_num) {
                    int_team[j][team_idx[j]] = player_level;
                    strncpy_s(char_team[j][team_idx[j]], sizeof(char_team[j][team_idx[j]]), player_name, 17);  
                    team_idx[j]++;
                    check = 1;  
                    break;
                }
            }

            if (check == 0) {
                int_team[team_cnt][0] = player_level;
                strncpy_s(char_team[team_cnt][0], sizeof(char_team[team_cnt][0]), player_name, 17); 
                team_idx[team_cnt]++;
                team_cnt++;
            }
        }
    }

    for (i = 0; i < team_cnt; i++) {
        for (j = 0; j < team_idx[i]; j++) {
            for (k = j; k < team_idx[i] - 1; k++) {
                if (strcmp(char_team[i][j], char_team[i][k + 1]) > 0) {
                    strncpy_s(char_temp, sizeof(char_temp), char_team[i][j], 17);  
                    strncpy_s(char_team[i][j], sizeof(char_team[i][j]), char_team[i][k + 1], 17); 
                    strncpy_s(char_team[i][k + 1], sizeof(char_team[i][k + 1]), char_temp, 17);  

                    int_temp = int_team[i][j];
                    int_team[i][j] = int_team[i][k + 1];
                    int_team[i][k + 1] = int_temp;
                }
            }
        }
    }

    for (i = 0; i < team_cnt; i++) {
        if (team_idx[i] == team_num)
            printf("Started!\n");
        else
            printf("Waiting!\n");

        for (j = 0; j < team_idx[i]; j++)
            printf("%d %s\n", int_team[i][j], char_team[i][j]);
    }

    return 0;
}
