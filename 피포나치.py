pibos = [1,1]
def Fibo(num):
    count=0
    for i in range(2, num):
        pibo = pibos[i-1] + pibos[i-2]
        if i <= num:
           pibos.append(pibo)
        else:
            break
    for j in range(num):
      print(str(pibos[j]).rjust(6),end=' ',)
      count += 1
      if count == 5:
        print("")
        count = 0
print("### 피보나치 수열 구하기 ###")
num = int(input("몇 번째 수열까지 출력할까요: "))
Fibo(num)
    
