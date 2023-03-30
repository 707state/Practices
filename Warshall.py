n=int(input('矩阵阶数：'))
Matrix=[]
for i in range(n):
    line=input("第%d行:"%(i+1)).split()
    Matrix.append(line)
def bitAdd(a:int,b:int):
    if a|b==0:
        return 0
    else:
        return 1
for col in range(n):
    for row in range(n):
        if int(Matrix[col][row])==1:
            for i in range(n):
                Matrix[row][i]=bitAdd(int(Matrix[row][i]),int(Matrix[col][i]))

for row in range(n):
    for col in range(n):
        print(Matrix[row][col],end=" ")
    print()