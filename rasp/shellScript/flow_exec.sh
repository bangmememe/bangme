#!/bin/bash

# 반복문
# for 변수 in 리스트; do
#    # 반복할 코드
# done

for name in "park" "fuck" "shit"; do
    echo "이름: $name"
done

echo " 0부터 100까지 숫자 프린트 ---- "
for int in {0..100}; do
    echo -n "$int "
done

# while () 문장1; 문장2; --> while [ condition ]; do 문장1; 문장2; done
# until 루프 --> until [ conditon ]; do 문장1; 문장2; done
# break continue...동일

# 함수!! -> argument 없음 -> $1, $2 소괄호 없음 리턴 없음 -> $?
function hello {
    local testInt=45
    globalInt="글로벌"
    echo "ㅎㅇ $1님"
    return 3
}

hello "fuck"
echo "반환된 값은 $? 입니다."
echo "$testInt $globalInt"

# 변수의 선언 -> 모든 선인이 전역변수 입니다.