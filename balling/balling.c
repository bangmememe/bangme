#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mysql.h>
#include "balling.h"

const char* HOST = "localhost";
const char* USER = "bangme";
const char* PASSWORD = "djwls123"; 
const char* DATABASE = "bowling_game";
#define MAX_QUERY_SIZE 512

MYSQL* connect_to_database() 
{
    MYSQL* conn = mysql_init(NULL);
    
    if (conn == NULL) 
    {
        fprintf(stderr, "mysql_init() failed\n");
        return NULL;
    }
    
    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }
    
    printf("MySQL 데이터베이스에 성공적으로 연결되었습니다.\n");
    return conn;
}

void create_tables(MYSQL* conn) 
{
    const char* create_scores_table = 
        "CREATE TABLE IF NOT EXISTS scores ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "username VARCHAR(50) NOT NULL, "
        "score INT NOT NULL, "
        "date DATETIME NOT NULL)";
    
    const char* create_player_stats_table = 
        "CREATE TABLE IF NOT EXISTS player_stats ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "username VARCHAR(50) NOT NULL, "
        "play_date DATE NOT NULL, "
        "play_count INT NOT NULL)";
    
    if (mysql_query(conn, create_scores_table)) 
    {
        fprintf(stderr, "테이블 생성 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("scores 테이블이 성공적으로 생성되었습니다.\n");
    }
    
    if (mysql_query(conn, create_player_stats_table)) 
    {
        fprintf(stderr, "테이블 생성 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("player_stats 테이블이 성공적으로 생성되었습니다.\n");
    }
}

void save_score(MYSQL* conn, const char* username, int score) 
{
    char query[MAX_QUERY_SIZE];
    
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    snprintf(query, MAX_QUERY_SIZE, 
             "INSERT INTO scores (username, score, date) VALUES ('%s', %d, '%s')",
             username, score, date_str);
    
    if (mysql_query(conn, query)) 
    {
        fprintf(stderr, "점수 저장 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("%s의 점수 %d가 성공적으로 저장되었습니다.\n", username, score);
    }
}

void update_player_stats(MYSQL* conn, const char* username) 
{
    char query[MAX_QUERY_SIZE];
    MYSQL_RES* result;
    
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    char date_str[11];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", timeinfo);
    
    snprintf(query, MAX_QUERY_SIZE, 
             "SELECT play_count FROM player_stats WHERE username='%s' AND play_date='%s'",
             username, date_str);
    
    if (mysql_query(conn, query)) 
    {
        fprintf(stderr, "쿼리 실패: %s\n", mysql_error(conn));
        return;
    }
    
    result = mysql_store_result(conn);
    
    if (result) 
    {
        if (mysql_num_rows(result) > 0) 
        {
            MYSQL_ROW row = mysql_fetch_row(result);
            int play_count = atoi(row[0]) + 1;
            
            snprintf(query, MAX_QUERY_SIZE, 
                     "UPDATE player_stats SET play_count=%d WHERE username='%s' AND play_date='%s'",
                     play_count, username, date_str);
            
            mysql_free_result(result);
            
            if (mysql_query(conn, query)) 
            {
                fprintf(stderr, "통계 업데이트 실패: %s\n", mysql_error(conn));
            }
            else
            {
                printf("%s의 플레이 횟수가 %d로 업데이트되었습니다.\n", username, play_count);
            }
        } 
        else 
        {
            mysql_free_result(result);
            
            snprintf(query, MAX_QUERY_SIZE, 
                     "INSERT INTO player_stats (username, play_date, play_count) VALUES ('%s', '%s', 1)",
                     username, date_str);
            
            if (mysql_query(conn, query)) 
            {
                fprintf(stderr, "통계 추가 실패: %s\n", mysql_error(conn));
            }
            else
            {
                printf("%s의 첫 플레이가 기록되었습니다.\n", username);
            }
        }
    }
}

int is_strike(Player* player, int frame) 
{
    return player->scores[frame][0] == 10;
}

int is_spare(Player* player, int frame) 
{
    return player->scores[frame][0] + player->scores[frame][1] == 10 && player->scores[frame][0] != 10;
}

void calculate_frame_score(Player* player, int frame) 
{
    int first_roll = player->scores[frame][0];
    int second_roll = player->scores[frame][1];
    int third_roll = player->scores[frame][2];
    
    // 스트라이크인 경우
    if (is_strike(player, frame)) 
    {
        player->frame_scores[frame] = 10;
        
        // 다음 2번의 점수를 가져옴
        if (frame < MAX_FRAMES - 1) {
            player->frame_scores[frame] += player->scores[frame + 1][0];
            if (player->scores[frame + 1][0] == 10) {
                // 다음 프레임도 스트라이크인 경우, 그 다음 프레임의 첫 번째 점수를 가져옴
                if (frame < MAX_FRAMES - 2) {
                    player->frame_scores[frame] += player->scores[frame + 2][0];
                }
            } else {
                player->frame_scores[frame] += player->scores[frame + 1][1];
            }
        }
    }
    // 스페어인 경우
    else if (is_spare(player, frame)) 
    {
        player->frame_scores[frame] = 10 + player->scores[frame + 1][0];
    }
    // 일반적인 경우
    else 
    {
        player->frame_scores[frame] = first_roll + second_roll;
    }
    
    // 10프레임 처리
    if (frame == MAX_FRAMES - 1) 
    {
        if (is_strike(player, frame)) 
        {
            player->frame_scores[frame] += third_roll;
        } 
        else if (is_spare(player, frame)) 
        {
            player->frame_scores[frame] += third_roll;
        }
    }
}

void play_frame(Player* player, int frame_index)
{
    int pins_left = 10;
    
    printf("%s의 차례, 프레임 %d:\n", player->name, frame_index + 1);
    
    int first_roll = 0;
    printf("%s가 첫 번째 투구를 합니다. 몇 개의 핀을 쓰러뜨렸나요? ", player->name);
    scanf("%d", &first_roll);
    player->scores[frame_index][0] = first_roll;
    pins_left -= first_roll;
    
    printf("%s가 %d개의 핀을 쓰러뜨렸습니다.\n", player->name, first_roll);
    
    if (first_roll < 10) 
    {
        int second_roll = 0;
        printf("%s가 두 번째 투구를 합니다. 몇 개의 핀을 쓰러뜨렸나요? ", player->name);
        scanf("%d", &second_roll);
        player->scores[frame_index][1] = second_roll;
        printf("%s가 %d개의 핀을 쓰러뜨렸습니다.\n", player->name, second_roll);
        
        // 스페어 확인
        if (first_roll + second_roll == 10) 
        {
            printf("스페어!\n");
        }
    } 
    else 
    {
        player->scores[frame_index][1] = 0;
        printf("스트라이크!\n");
        
        // 10프레임 처리를 위해 세 번째 투구 기회 부여
        if (frame_index == MAX_FRAMES - 1) 
        {
            int third_roll = 0;
            printf("%s가 세 번째 투구를 합니다. 몇 개의 핀을 쓰러뜨렸나요? ", player->name);
            scanf("%d", &third_roll);
            player->scores[frame_index][2] = third_roll;
            printf("%s가 %d개의 핀을 쓰러뜨렸습니다.\n", player->name, third_roll);
        }
    }
    
    calculate_frame_score(player, frame_index);
    player->total_score += player->frame_scores[frame_index];
}
void initialize_game(Player players[]) 
{
    srand(time(NULL));
    
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        printf("Player %d, 이름을 입력하세요: ", i + 1);
        scanf("%s", players[i].name);
        players[i].total_score = 0;
        
        for (int j = 0; j < MAX_FRAMES; j++) 
        {
            players[i].scores[j][0] = -1;  // -1은 아직 던지지 않았음을 의미
            players[i].scores[j][1] = -1;
            players[i].scores[j][2] = -1;
            players[i].frame_scores[j] = 0;
        }
    }
}
int roll_ball(int pins) 
{
    return rand() % (pins + 1);
}

void play_game(Player players[], MYSQL* conn) 
{
    for (int frame = 0; frame < MAX_FRAMES; frame++) 
    {
        printf("\n===== 프레임 %d =====\n", frame + 1);
        
        for (int player_index = 0; player_index < MAX_PLAYERS; player_index++) 
        {
            play_frame(&players[player_index], frame);
            printf("%s's current score: %d\n", players[player_index].name, players[player_index].total_score);
        }
    }
    
    printf("\n===== FINAL SCORES =====\n");
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        printf("%s: %d points\n", players[i].name, players[i].total_score);
    }
    
    int winner_index = 0;
    for (int i = 1; i < MAX_PLAYERS; i++) 
    {
        if (players[i].total_score > players[winner_index].total_score) 
        {
            winner_index = i;
        }
    }
    
    printf("\n승자는 %s 그리고 점수는 %d 입니다!\n", 
           players[winner_index].name, players[winner_index].total_score);
    
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        save_score(conn, players[i].name, players[i].total_score);
        update_player_stats(conn, players[i].name);
    }
}