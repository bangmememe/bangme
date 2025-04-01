#ifndef BALLING_H
#define BALLING_H

#include <mysql.h>

#define MAX_FRAMES 10
#define MAX_PLAYERS 2
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_FRAMES][3];
    int frameScores[MAX_FRAMES];
    int totalScore;
} Player;

MYSQL *connect_to_database();
void create_tables(MYSQL *conn);
void initialize_game(Player players[]);
void play_game(Player players[]);
void calculate_score(Player *player);
void display_scorecard(Player players[]);
void save_score(MYSQL *conn, const char *username, int score);
void update_user_monthly_stats(MYSQL *conn, const char *username, int year, int month);
void save_game_result(MYSQL *conn, Player players[]);

#endif