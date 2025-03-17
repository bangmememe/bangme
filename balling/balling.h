#ifndef BALLING_H
#define BALLING_H

#include <mysql.h>

#define MAX_PLAYERS 2
#define MAX_FRAMES 10

typedef struct {
    char name[20];
    int scores[MAX_FRAMES][3];  // 3번째 값은 10프레임의 3번째 투구 점수
    int frame_scores[MAX_FRAMES];
    int total_score;
} Player;

MYSQL* connect_to_database();
void create_tables(MYSQL* conn);
void save_score(MYSQL* conn, const char* username, int score);
void update_player_stats(MYSQL* conn, const char* username);
void initialize_game(Player players[]);
int roll_ball(int pins);
int is_strike(Player* player, int frame);
int is_spare(Player* player, int frame);
void calculate_frame_score(Player* player, int frame);
void play_frame(Player* player, int frame_index);
void play_game(Player players[], MYSQL* conn);

#endif