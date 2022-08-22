import sys
import turtle
import random
import math

q = turtle.textinput("", "난이도를 선택해주세요(easy, hard,종료시 엔터): ")
if q == "":
    sys.exit()

player = turtle.Turtle()
player.color("blue")
player.shape("turtle")
player.penup()
player.speed(10)
screen = player.getscreen()

asteroids = []
if q == "easy":
    for i in range(15):
     a1 = turtle.Turtle()
     a1.color("red")
     a1.shape("circle")
     a1.penup()
     a1.speed(0)
     a1.goto(random.randint(-200, 200), random.randint(-200, 200))
     asteroids.append(a1)
elif q == "hard":
    for i in range(20):
     a1 = turtle.Turtle()
     a1.color("red")
     a1.shape("circle")
     a1.penup()
     a1.speed(-10)
     a1.goto(random.randint(-150, 150), random.randint(-150, 150))
     asteroids.append(a1)
else:
   print("다시 입력해주세요")
 
    


def turnleft():
    player.left(30)

def turnright():
    player.right(30)

screen.onkeypress(turnleft, "Left")
screen.onkeypress(turnright, "Right")
screen.listen()

def play():
    player.forward(4)
    for a in asteroids:
        a.right(random.randint(-180, 180))
        a.forward(4)
    screen.ontimer(play, 10)

screen.ontimer(play, 10)
