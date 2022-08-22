#2022203036 소프트웨어학부 임동건

from turtle import *
color("white")
bgcolor("black")
speed(0)
pensize(15)

def stick(d):  #양쪽 막대기 그리기
   left(45)
   fd(d)
   fd(-d)
   right(90)
   fd(d)
   fd(-d)
   left(45)
               
def snowflake (): #눈 결정 그리기
   for i in range(6):
      fd(200)
      pendown()
      fd(-40)
      stick(30)
      fd(-40)
      stick(45)
      fd(-40)
      stick(55)
      fd(-80)
      #중앙에 육각형 그리기
      right(120)
      fd(50)
      left(60)

def snow(x,y,r): #주변 눈 그리기
   penup()
   goto(x,y)
   pendown()
   circle(r)

#메인            
penup()
goto(0,50)
left(90)

snowflake()

snow(-130, 250, 7)
snow(260, -120 , 5)
snow(-150, -170, 3)
snow(190, 200, 2)
color("gray")
snow(-230, -10, 3)
snow(255, 100, 4)
snow(170, -200, 5)
done()




