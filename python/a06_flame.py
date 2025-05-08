import sys

frame = sys._getframe()
abc = int()
abc2 = list()

print("현재 프레임 : ", frame)
print("코드 객체 : ", frame.f_code)
print("로컬 변수 : ", frame.f_locals)
print(frame.__dict__.items())
print(frame.__dict__[__name__])
# __flie__
# __package__
# __doc__
# __spec__
# ...
print("main_frame co name : ", frame.f_code.co_name)


def main():
    a = 123
    b = [3,4,5]
    main_frame = sys._getframe()
    print("main_frame co name : ", main_frame.f_code.co_name)
    print("local 변수 : ", main_frame.f_locals)
    print("전역 변수 : ", main_frame.f_globals)
    
if __name__ == "__main__":
    main()