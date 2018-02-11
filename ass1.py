def PrintGrid(grid):
    print("\n")
    for i in range(3):
        for k in range(3):
            for j in range(3):
                if (j == 1):
                    if (grid[i][k] == -1):
                         print(" ", end="")
                    else:
                         print(grid[i][k], end="")
                else:
                     print(" ", end = "")
            if k != 2:
                print("*", end = "")
        print("\n")
    print("\n")
def win(grid):
    for i in range(3):
        sum = 0;
        fullline = True
        for j in range(3):
            if (grid[i][j] == -1):
                fullline = False
            else:
                sum += grid[i][j]
        if (fullline and sum == 15):
            return True
    for i in range(3):
        sum = 0;
        fullline = True
        for j in range(3):
            if (grid[j][i] == -1):
                fullline = False
            else:
                sum += grid[j][i]
        if (fullline and sum == 15):
            return True
    if (grid[0][0] + grid[1][1] + grid[2][2] == 15 and grid[0][0] != -1 and grid[1][1] != -1 and grid[2][2] != -1):
        return True
    if (grid[0][2] + grid[1][1]+ grid[2][0] == 15 and grid[0][2] != -1 and grid[1][1] != -1 and grid[2][0] != -1):
        return True
    return False
def CoorValidation(x, y, usedcoor):
    coordinate = x *10 + y
    if (x < 1 or  y < 1 or y > 3 or x > 3 or coordinate in usedcoor):
        return False
    return True
def OddValidation(num, p1):
    if (num%2 == 1 and num > 0 and num < 10 and num in p1):
        return True
    return False
def EvenValidation(num, p2):
    if (num%2 == 0 and num >= 0 and num < 9 and num in p2):
        return True
    return False

col1 = [-1, -1, -1]
col2 = [-1, -1, -1]
col3 = [-1, -1, -1]
grid = [col1, col2, col3]
p1 = []
p2 = []
usedcoor = []
for i in range (1, 10, 2):
    p1.append(i)
for i in range (0, 9, 2):
    p2.append(i)
turn = 1
moves = 0
PrintGrid(grid)
while (win(grid) == False and moves < 9):
    if (turn == 1):
        while (True):
            print('Enter Number[', end= "")
            for i in p1:
                if (i != p1[-1]):
                    print(i, end =",")
                else:
                    print(i, end = "]: ")
            num = int(input())
            if (OddValidation(num, p1) == True):
                break
        p1.remove(num)
    elif (turn == -1):
        while (True):
            print('Enter Number [', end = "")
            for i in p2:
                if (i != p2[-1]):
                    print(i, end = ",")
                else:
                    print(i, end = "]: ")
            num = int(input())
            if (EvenValidation(num, p2) == True):
                break
        p2.remove(num)
    while (True):
        x = int(input('Enter Row number: '))
        y = int(input('Enter Column number: '))
        coordinate = x*10+y
        if (CoorValidation(x,y, usedcoor)):
            break
    usedcoor.append(coordinate)
    grid[x-1][y-1] = num
    PrintGrid(grid)
    turn *= -1
    moves += 1


if (win(grid) == False):
    print("Tie")
else:
    if (turn == 1):
        print("Player 2 Wins!")
    else:
        print("Player 1 Wins!")

