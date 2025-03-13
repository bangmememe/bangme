#include <stdio.h>
#include <string.h>
#include <mysql.h>
// sudo apt install libmysql++*
// dpkg -L libmysqlclient-dev | grep mysql.h
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// libmysqlclient.so libmysqlclient.a

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;
enum menu
{
    SELECT,
    INSERT,
    DROP,
    ALTER,
    QUERY
};

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);

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
    conn = mysql_init(NULL); // db 연결 요청 준비
    if(mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
        printf("MYSQL 연결 성공\n");
    else
    {
        printf("MYSQL 연결 실패\n");
        return 1;
    }
    while (true)
    {
        // printf("1 , 2 번 고르세요!");
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case SELECT:
            fetch_books(conn);
            break;
        case INSERT:
            add_books(conn);
            break;
        case DROP:
            add_books(conn);
            break;
        case ALTER:
            add_books(conn);
            break;
        case QUERY:
            add_books(conn);
            break;
        }
    }

    mysql_close(conn);

    return 0;
}
void print_menu(void)
{
    system("clear");
    printf("=== 도서 관리 시스템 ===\n");
    printf("0. 도서조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 변경\n");
    printf("4. 쿼리문 입력\n");
}

void add_books(MYSQL *conn)
{
    printf("--- 도서 추가 ---\n");
    Book newbook;
    char query[255];
    // 정보 입력 scanf
    printf("도서 ID: ");
    scanf("%d", &newbook.bookid);
    printf("도서 명: ");
    scanf("%s", newbook.bookname);
    printf("출판사 : ");
    scanf("%s", newbook.publisher);
    printf("가격: ");
    scanf("%d", &newbook.price);
    // query 문 작성 strcpy... "insert ....."
    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    // query 요청 mysql_query();
    if (mysql_query(conn, query))
    {
        printf("데이터 입력 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("입력 성공\n");
    }

    return;
}

void delete_books(MYSQL *conn)
{
    // index 번호 받기 scanf
    // 지우는 쿼리
}
void update_books(MYSQL *conn)
{
    // 모든 번호 받기 scanf
    // 변경하는 쿼리
}
void query_books(MYSQL *conn)
{

}
void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from Book");

    // 쿼리 요청
    if (mysql_query(conn, query))
    {
        printf("쿼리 실패");
        return;
    }
    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패!\n");
        return;
    }
    Book *pBook;
    pBook = (Book *)malloc(sizeof(Book));
    int i = 0;
    // 데이터 베이스의 정보를 구조체에 저장 - ORM
    while(row = mysql_fetch_row(res))
    {
        (pBook + i)->bookid = atoi(row[0]);
        strcpy((pBook + i)->bookname, row[1]);
        strcpy((pBook + i)->publisher, row[2]);
        (pBook + i)->price = atoi(row[3]);
        ++i;
        pBook = realloc(pBook, 1 + i);
    };
    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%s \t%d \n",
            (pBook + j)->bookid,
            (pBook + j)->bookname,
            (pBook +j)->publisher,
            (pBook + j)->price);
    }
    free(pBook);
    // TOOD : 여기 엔터만 쳐도 넘어가게 변경
    int temp;
    scanf("%d", &temp);
}