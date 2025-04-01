#include "bookSql.h"

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "bangme";
    char *pass = "djwls123";
    char *db = "mydb";
    int port = 3306;
    int choice;

    // 연결
    conn = mysql_init(NULL); // DB 연결 요청 준비
    if (conn == NULL) {
        printf("mysql_init 실패: %s\n", mysql_error(conn));
        return 1;
    }    
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
        printf("MySQL 연결 성공\n");
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }

    while (true)
    {
        // printf("1 , 2 번 고르세요!");
        print_menu();
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case SELECT:
            fetch_books(conn);
            break;
        case INSERT:
            add_books(conn);
            break;
        case DROP:
            delete_books(conn);
            break;
        case ALTER:
            update_books(conn);
            break;
        case QUERY:
            query_books(conn);
            break;
        case EXIT:
            close_connection(conn);
            return 0;
        default:
            printf("잘못된 선택입니다.\n");
            waitEnter();
            break;
        }
    }
    // MYSQL *conn = malloc(sizeof(MYSQL));
    // if (mysql_init(conn) == NULL) 
    //    {
    //        printf("mysql_init 실패: %s\n", mysql_error(conn));
    //        free(conn);
    //        return 1;
    //   }


    // mysql_close(conn);

    return 0;
}