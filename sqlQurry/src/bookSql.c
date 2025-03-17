#include "bookSql.h"
            
void print_menu(void)
{
    system("clear");
    printf("=== 도서 관리 시스템 ===\n");
    printf("0. 도서조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 변경\n");
    printf("4. 쿼리문 입력\n");
    printf("5. 종료\n");
    printf("메뉴를 선택하세요: ");
}

void add_books(MYSQL *conn)
{
    printf("--- 도서 추가 ---\n");
    Book newbook;
    char query[255];
    // 정보 입력 scanf
    printf("도서 ID: ");
    scanf("%d%*c", &newbook.bookid);
    printf("도서 명: ");
    scanf("%s%*c", newbook.bookname);
    printf("출판사: ");
    scanf("%s%*c", newbook.publisher);
    printf("가격: ");
    scanf("%d%*c", &newbook.price);
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
    waitEnter();
    return;
}

void delete_books(MYSQL *conn)
{
    int bookid;
    printf("삭제할 도서명: ");
    scanf("%d%*c", &bookid);
    char query[255];
    sprintf(query, "delete from Book where bookid = %d", bookid);

    if(mysql_query(conn, query))
    {
        printf("쿼리 실패 : %s\n", mysql_error(conn));
    }
    else
    {
        my_ulonglong affected_row =  mysql_affected_rows(conn);
        printf("삭제 성공 : %lu 개\n", affected_row);
    }
    waitEnter();
}
void update_books(MYSQL *conn)
{
    printf("--- 도서 변경 ---\n");
    Book newbook;
    char query[255];
    // 정보 입력 scanf
    printf("변경할 도서 ID: ");
    scanf("%d%*c", &newbook.bookid);
    printf("도서 명: ");
    scanf("%s%*c", newbook.bookname);
    printf("출판사: ");
    scanf("%s%*c", newbook.publisher);
    printf("가격: ");
    scanf("%d%*c", &newbook.price);

    sprintf(query, "update Book set bookname = '%s', publisher = '%s', price = %d where bookid = %d", newbook.bookname, newbook.publisher, newbook.price, newbook.bookid);
    // query 요청 mysql_query();
    if (mysql_query(conn, query))
    {
        printf("데이터 변경 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("변경 성공\n");
    }
    waitEnter();
}
void query_books(MYSQL *conn)
{
    MYSQL_RES *res;
    char **row; // MYSQL_ROW row;
    char query[255];
    printf("실행할 쿼리를 넣어 주세요: ");
    fgets(query, sizeof(query), stdin);
    query[strspn(query, "\n")] = 0;
    
    if(mysql_query(conn, query))
    {
        printf("쿼리 실패 %s\n", mysql_error(conn));
        return ;
    }
    res = mysql_store_result(conn);
    if(res)
    {
        while(row = mysql_fetch_row(res))
        {
            for(int i = 0; i < mysql_num_fields(res); ++i)
            {
                printf("%s\t", row[i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("요청한 데이터가 없습니다.\n");
    }
    waitEnter();
}
void fetch_books(MYSQL *conn)
{
    if (conn == NULL) {
        printf("데이터베이스 연결이 없습니다.\n");
        waitEnter();
        return;
    }

    printf("도서 조회를 시작합니다...\n");
    
    // 쿼리 실행
    if (mysql_query(conn, "SELECT * FROM Book")) {
        printf("쿼리 실행 오류: %s\n", mysql_error(conn));
        waitEnter();
        return;
    }
    
    // 결과 가져오기
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("결과 저장 오류: %s\n", mysql_error(conn));
        waitEnter();
        return;
    }
    
    // 결과 행 수 확인
    my_ulonglong num_rows = mysql_num_rows(result);
    printf("조회된 도서 수: %llu\n", num_rows);
    
    if (num_rows == 0) {
        printf("도서가 없습니다.\n");
        mysql_free_result(result);
        waitEnter();
        return;
    }
    
    // 필드(열) 정보 가져오기
    int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    
    // 열 이름 출력
    for (int i = 0; i < num_fields; i++) {
        printf("%-15s", fields[i].name);
    }
    printf("\n");
    
    // 구분선 출력
    for (int i = 0; i < num_fields; i++) {
        printf("---------------");
    }
    printf("\n");
    
    // 데이터 행 출력
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%-15s", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    
    // 결과 해제
    mysql_free_result(result);
    waitEnter();
}
void waitEnter(void)
{
    printf("엔터를 쳐 주세요....\n");
    char temp;
    while (getchar() != '\n')
        scanf("%c%*c", &temp);
}
void close_connection(MYSQL *conn)
{
    if (conn != NULL) {
        printf("종료\n");
        mysql_close(conn); // MySQL 라이브러리의 mysql_close 호출
        // free(conn); // 제거: mysql_close가 메모리를 해제함
    }
}