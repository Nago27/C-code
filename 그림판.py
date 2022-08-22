import turtle #터틀 그래픽 모듈 포함

def draw(x, y): #마우스가 클릭될 위치
    t.goto(x, y)

t = turtle.Turtle()
t.shape("turtle")
t.pensize(10)

s = turtle.Screen() #그림이 그려지는 화면 생성
s.onscreenclick(draw) #마우스 클릭릭 이벤트 처리 함수 등록

s.onkey(t.penup, "Up") #위쪽 화살표키 처리 함수 등록
s.onkey(t.pendown, "Down") #아래쪽 화살표 처리 함수 등록
s.listen() #키보드 이벤트 기다림
