# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -g

# MySQL 설정
MYSQL_CFLAGS = $(shell mysql_config --cflags)
MYSQL_LIBS = $(shell mysql_config --libs)

# 타겟 설정
TARGET = bowling_game

# 소스 파일
SRCS = main.c balling.c
OBJS = $(SRCS:.c=.o)

# 기본 타겟
all: $(TARGET)

# 최종 실행 파일 생성
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(MYSQL_LIBS)

# 개별 소스 파일 컴파일
%.o: %.c balling.h
	$(CC) $(CFLAGS) $(MYSQL_CFLAGS) -c $< -o $@

# 정리
clean:
	rm -f $(OBJS) $(TARGET)

# 실행
run: $(TARGET)
	./$(TARGET)

# PHONY 타겟 설정
.PHONY: all clean run
