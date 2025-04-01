#include <stdio.h>
#include <stdlib.h>
#include "balling.h"

int main() {
    MYSQL *conn = connect_to_database();
    if (conn == NULL) {
        fprintf(stderr, "데이터베이스 연결 실패\n");
        return 1;
    }

    create_tables(conn);

    Player players[MAX_PLAYERS];
    initialize_game(players);
    play_game(players);
    save_game_result(conn, players);

    mysql_close(conn);

    return 0;
}