#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mysql.h>
#include "balling.h"

MYSQL *connect_to_database() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) 
    {
        fprintf(stderr, "MySQL 초기화 실패\n");
        return NULL;
    }

    if (mysql_real_connect(conn, "localhost", "bangme", "djwls123", "balling_db", 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "데이터베이스 연결 실패: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    return conn;
}

void create_tables(MYSQL *conn) 
{
    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS balling_db") != 0) 
    {
        fprintf(stderr, "데이터베이스 생성 실패: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_query(conn, "USE balling_db") != 0) 
    {
        fprintf(stderr, "데이터베이스 선택 실패: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS score_records ("
                         "id INT AUTO_INCREMENT PRIMARY KEY, "
                         "username VARCHAR(50) NOT NULL, "
                         "play_date DATE NOT NULL, "
                         "score INT NOT NULL)") != 0) 
    {
        fprintf(stderr, "score_records 테이블 생성 실패: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS user_monthly_stats ("
                         "id INT AUTO_INCREMENT PRIMARY KEY, "
                         "username VARCHAR(50) NOT NULL, "
                         "year INT NOT NULL, "
                         "month INT NOT NULL, "
                         "play_count INT NOT NULL DEFAULT 0, "
                         "UNIQUE KEY unique_user_month (username, year, month))") != 0) 
    {
        fprintf(stderr, "user_monthly_stats 테이블 생성 실패: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS game_results ("
                         "id INT AUTO_INCREMENT PRIMARY KEY, "
                         "game_date DATETIME NOT NULL, "
                         "player1_name VARCHAR(50) NOT NULL, "
                         "player1_score INT NOT NULL, "
                         "player2_name VARCHAR(50) NOT NULL, "
                         "player2_score INT NOT NULL, "
                         "winner VARCHAR(50) NOT NULL)") != 0) 
    {
        fprintf(stderr, "game_results 테이블 생성 실패: %s\n", mysql_error(conn));
        return;
    }
}

void initialize_game(Player players[]) 
{
    printf("볼링 게임을 시작합니다!\n");
    
    // 플레이어 이름 입력
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        printf("플레이어 %d의 이름을 입력하세요: ", i + 1);
        scanf("%s", players[i].name);
        
        // 점수 초기화
        for (int j = 0; j < MAX_FRAMES; j++) 
        {
            for (int k = 0; k < 3; k++) 
            {
                players[i].scores[j][k] = -1;
            }
            players[i].frameScores[j] = 0;
        }
        players[i].totalScore = 0;
    }
    
    // 난수 발생기 초기화
    srand(time(NULL));
    
    printf("게임이 초기화되었습니다.\n");
}

// 볼링 핀을 쓰러뜨리는 함수
int roll_ball(int pinsLeft) 
{
    return rand() % (pinsLeft + 1);
}
void play_game(Player players[]) 
{
    printf("\n게임을 시작합니다!\n");
    
    for (int frame = 0; frame < MAX_FRAMES; frame++) 
    {
        printf("\n==== 프레임 %d ====\n", frame + 1);
        
        for (int player = 0; player < MAX_PLAYERS; player++) 
        {
            printf("\n%s의 차례입니다.\n", players[player].name);
            
            int pinsLeft = 10;
            
            // 첫 번째 투구
            printf("첫 번째 투구를 위해 Enter 키를 누르세요...");
            getchar();
            int firstRoll = roll_ball(pinsLeft);
            players[player].scores[frame][0] = firstRoll;
            pinsLeft -= firstRoll;
            
            if (firstRoll == 10) 
            {
                printf("스트라이크! 10개의 핀을 모두 쓰러뜨렸습니다!\n");
                if (frame < 9) 
                {  
                    continue;
                }
            } 
            else 
            {
                printf("%d개의 핀을 쓰러뜨렸습니다. 남은 핀: %d\n", firstRoll, pinsLeft);
            }
            
            // 두 번째 투구
            printf("두 번째 투구를 위해 Enter 키를 누르세요...");
            getchar();
            int secondRoll = roll_ball(pinsLeft);
            players[player].scores[frame][1] = secondRoll;
            pinsLeft -= secondRoll;
            
            if (firstRoll + secondRoll == 10) 
            {
                printf("스페어! 남은 핀을 모두 쓰러뜨렸습니다!\n");
            } 
            else 
            {
                printf("%d개의 핀을 쓰러뜨렸습니다. 총 %d개의 핀을 쓰러뜨렸습니다.\n", 
                       secondRoll, firstRoll + secondRoll);
            }
            
            // 10프레임에서 스트라이크나 스페어를 친 경우 보너스 투구
            if (frame == 9 && (firstRoll == 10 || firstRoll + secondRoll == 10)) 
            {
                printf("보너스 투구를 위해 Enter 키를 누르세요...");
                getchar();
                int bonusRoll = roll_ball(10);
                players[player].scores[frame][2] = bonusRoll;
                printf("보너스 투구: %d개의 핀을 쓰러뜨렸습니다!\n", bonusRoll);
            }
        }
        
        // 각 프레임 후 점수 계산 및 표시
        for (int player = 0; player < MAX_PLAYERS; player++)
        {
            calculate_score(&players[player]);
        }
        display_scorecard(players);
    }
    
    // 최종 점수 표시
    printf("\n==== 최종 점수 ====\n");
    for (int player = 0; player < MAX_PLAYERS; player++) 
    {
        printf("%s의 최종 점수: %d\n", players[player].name, players[player].totalScore);
    }
    
    // 승자 결정
    if (players[0].totalScore > players[1].totalScore) 
    {
        printf("\n%s가 승리했습니다!\n", players[0].name);
    } 
    else if (players[0].totalScore < players[1].totalScore) 
    {
        printf("\n%s가 승리했습니다!\n", players[1].name);
    } 
    else 
    {
        printf("\n무승부입니다!\n");
    }
}

void calculate_score(Player *player) 
{
    int totalScore = 0;
    
    for (int frame = 0; frame < MAX_FRAMES; frame++) 
    {
        int frameScore = 0;
        int firstRoll = player->scores[frame][0];
        int secondRoll = player->scores[frame][1];
        
        if (firstRoll == 10) 
        {
            frameScore = 10;
            
            if (frame < 9) 
            {  
                if (player->scores[frame + 1][0] == 10) 
                {  
                    frameScore += 10;
                    
                    if (frame < 8) 
                    {  
                        frameScore += player->scores[frame + 2][0];  
                    } else {  // 9프레임
                        frameScore += player->scores[frame + 1][1];  
                    }
                }
                else
                {  // 다음 프레임은 스트라이크가 아님
                    frameScore += player->scores[frame + 1][0] + player->scores[frame + 1][1];
                }
            }
            else 
            {
                frameScore += player->scores[frame][1] + player->scores[frame][2];
            }
        } 
        else if (firstRoll + secondRoll == 10) 
        { 
            frameScore = 10;
            
          
            if (frame < 9) 
            {  
                frameScore += player->scores[frame + 1][0];
            } else 
            { 
                frameScore += player->scores[frame][2];
            }
        } 
        else 
        {  
            frameScore = firstRoll + secondRoll;
        }
        
        totalScore += frameScore;
        player->frameScores[frame] = totalScore;
    }
    
    player->totalScore = totalScore;
}
void display_scorecard(Player players[]) 
{
    printf("\n==== 현재 점수 ====\n");
    
    for (int player = 0; player < MAX_PLAYERS; player++) 
    {
        printf("%s의 점수:\n", players[player].name);
        
        printf("프레임: ");
        for (int frame = 0; frame < MAX_FRAMES; frame++) 
        {
            printf("%3d ", frame + 1);
        }
        printf("\n");
        
        printf("투구:   ");
        for (int frame = 0; frame < MAX_FRAMES; frame++) 
        {
            int firstRoll = players[player].scores[frame][0];
            int secondRoll = players[player].scores[frame][1];
            
            if (firstRoll == 10) 
            {
                printf("  X ");
            } else if (firstRoll + secondRoll == 10) 
            {
                printf("%d / ", firstRoll);
            }
            else 
            {
                if (firstRoll == -1) 
                {
                    printf("  - ");  
                }
                 else if (secondRoll == -1) 
                {
                    printf("%d - ", firstRoll);  
                } else {
                    printf("%d %d ", firstRoll, secondRoll);
                }
            }
        }
        printf("\n");

        printf("점수:   ");
        for (int frame = 0; frame < MAX_FRAMES; frame++) 
        {
            if (players[player].frameScores[frame] > 0) 
            {
                printf("%3d ", players[player].frameScores[frame]);
            } 
            else 
            {
                printf("  - ");
            }
        }
        printf("\n\n");
    }
}

void save_score(MYSQL *conn, const char *username, int score) 
{
    char query[256];
    sprintf(query, "INSERT INTO score_records (username, play_date, score) VALUES ('%s', CURDATE(), %d)", username, score);

    if (mysql_query(conn, query) != 0) 
    {
        fprintf(stderr, "점수 저장 실패: %s\n", mysql_error(conn));
        return;
    }

    mysql_commit(conn);
    printf("%s의 점수 %d가 저장되었습니다.\n", username, score);
}

void update_user_monthly_stats(MYSQL *conn, const char *username, int year, int month) 
{
    char query[256];
    sprintf(query, "INSERT INTO user_monthly_stats (username, year, month, play_count) VALUES ('%s', %d, %d, 1) "
                   "ON DUPLICATE KEY UPDATE play_count = play_count + 1", username, year, month);

    if (mysql_query(conn, query) != 0) 
    {
        fprintf(stderr, "월간 통계 업데이트 실패: %s\n", mysql_error(conn));
        return;
    }

    mysql_commit(conn);
    printf("%s의 %d년 %d월 월간 통계가 업데이트되었습니다.\n", username, year, month);
}

void save_game_result(MYSQL *conn, Player players[]) 
{
    char query[512];
    char winner[MAX_NAME_LENGTH];
    
    if (players[0].totalScore > players[1].totalScore) 
    {
        strcpy(winner, players[0].name);
    } else if (players[0].totalScore < players[1].totalScore) 
    {
        strcpy(winner, players[1].name);
    } 
    else 
    {
        strcpy(winner, "무승부");
    }
    
    sprintf(query, "INSERT INTO game_results (game_date, player1_name, player1_score, player2_name, player2_score, winner) "
                   "VALUES (NOW(), '%s', %d, '%s', %d, '%s')", 
                   players[0].name, players[0].totalScore, 
                   players[1].name, players[1].totalScore, 
                   winner);

    if (mysql_query(conn, query) != 0) 
    {
        fprintf(stderr, "게임 결과 저장 실패: %s\n", mysql_error(conn));
        return;
    }

    mysql_commit(conn);
    printf("게임 결과가 데이터베이스에 저장되었습니다.\n");
    
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        save_score(conn, players[i].name, players[i].totalScore);
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        update_user_monthly_stats(conn, players[i].name, year, month);
    }
}