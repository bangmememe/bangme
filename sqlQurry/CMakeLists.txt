cmake_minimum_required(VERSION 3.00)
project(bookSql)

#set(SOURCES
#    src/bookSql.c
#    src/main.c
#)

#add_executable(bookSql ${SOURCES})
#target_include_directories(bookSql PRIVATE include)
#target_include_directories(bookSql PRIVATE src)

#target_include_directories(bookSql PRIVATE /usr/include/mysql)
#target_link_directories(bookSql PRIVATE /usr/lib/mysql)
#target_link_libraries(bookSql PRIVATE mysqlclient)

# MySQL 라이브러리 찾기
find_library(MYSQL_LIBRARY NAMES mysqlclient libmysqlclient
             HINTS /usr/lib /usr/lib/mysql /usr/lib/x86_64-linux-gnu)
find_path(MYSQL_INCLUDE_DIR mysql.h
          HINTS /usr/include/mysql /usr/local/include/mysql)

if(NOT MYSQL_LIBRARY OR NOT MYSQL_INCLUDE_DIR)
    message(FATAL_ERROR "MySQL 라이브러리 또는 헤더 파일을 찾을 수 없습니다. libmysqlclient-dev를 설치하세요.")
endif()

# 소스 파일과 헤더 파일 경로 설정
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 소스 파일 목록
set(SOURCES
    ${SOURCE_DIR}/main.c
    ${SOURCE_DIR}/bookSql.c
)

# 실행 파일 생성
add_executable(bookSql ${SOURCES})

# 인클루드 디렉토리 추가
target_include_directories(bookSql PRIVATE ${INCLUDE_DIR} ${MYSQL_INCLUDE_DIR})

# MySQL 라이브러리 링크
target_link_libraries(bookSql PRIVATE ${MYSQL_LIBRARY})