#!/bin/bash

# 이 스크립트는 헬로우 월드를 출력합니다.
name="Fuck"
export age=27

echo "Hello, world!, $name"
echo "date : " `date` # 이 라인은 date 유틸리티를 실행 합니다.

text=" hello, world! "
echo ${text:0:5}
echo ${text:7}

text="I like game"
echo ${text/game/dogs}

text="I like game, I realry love game"
echo ${text//game/dogs}
echo ${#text}

# 중요 ! unset env 환경 변수 초기화
# unset 환경변수

# read
echo "이름을 입력하시오: "
read name
read -s -p "비밀번호를 입력하세요: " password 
echo "입력한 이름: $name"
echo "패스워드: $password " 
export name$name
./envTest

# 화면출력 echo , printf
echo -n " 이어지는 "
echo " 문장 "
echo -e " 엔터가 들어가는\n 문장 "
printf "이름: %s, 나이: %d\n" "fuck" 27

# 중요 !! argument 받기 $1 $2 인자 갯수 : $# 모든 인자 : $@ $*
echo "첫 번째 인자: $1"
echo "두 번째 인자: $2"
echo "인자들의 갯수: $#"
echo "모든 인자: $@"

# 제어문 if then fi(endif)
read -p "나이를 넣으시오: " age
if [ $age -lt 18 ]; then
    echo "성인이 아닙니다."
elif [ $age -gt 70 ]; then
    echo "노인입니다."
elif [ $age -gt 20 ] && [ $age -lt 30 ]; then
    echo "20대 입니다."
else
    echo "성인입니다."
fi

# 연산자 - 숫자
# 같다 == : eq
# 같지않다. != : ne
# 크다. > : gt
# 작다. > : lt
# 크거나 같다. >= : ge
# 작거나 같다. >= : le

# 연산자 - 문자
# 같다. == : = 헷갈리지 말것
# 같지않다. != : !=
# 길이가 0 len(문자열) : z
# 길이가 0 이 아님 len(문자열) : n

read -p "입력값을 넣으세요" input
if [ -z "$input" ]; then
    echo "입력값이 없습니다"
else
    echo "$input"
fi

# 논리연산 && || !

# switch - case -> case

read -p "과일 입력: " fruit
case $fruit in
    "사과"|"딸기") echo "빨간 과일" ;;
    "바나나"|"망고") echo "노란 과일" ;;
    *) echo "알 수 없음" ;;
esac


