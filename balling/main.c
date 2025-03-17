#include <stdio.h>
#include "balling.h"

int main() {
    MYSQL* conn = connect_to_database();
    if (conn == NULL) {
        return 1;
    }

    create_tables(conn);

    Player players[MAX_PLAYERS];
    initialize_game(players);
    play_game(players, conn);

    mysql_close(conn);
    return 0;
}