import pygame;

def winGame(gridValues):    
    for i in range(0, 9, 3):
        isFullLine = True
        total = 0
        for j in range(3):
            if (gridValues[i+j] == -1):
                isFullLine = False
            else:
                total = total + gridValues[i+j]
        if (isFullLine and total == 15):
            return True    
    for i in range(3):
        isFullLine = True
        total = 0
        for j in range(0, 9, 3):
            if (gridValues[i+j] == -1):
                isFullLine = False
            else:
                total = total + gridValues[i+j]
        if (isFullLine and total == 15):
            return True
    if (gridValues[0] + gridValues[4] + gridValues[8] == 15 and gridValues [0] != -1 and gridValues[4] != -1 and gridValues[8] != -1):
        return True
    if (gridValues[2] + gridValues[4] + gridValues[6] == 15 and gridValues [2] != -1 and gridValues[4] != -1 and gridValues[6] != -1):
        return True
    return False

PRIMARY = (0, 153, 255)
PRIMARYChoice = (255, 0, 255)
SECONDARY = (51, 204, 51)
numCOLOR = (102, 41, 0)
GREY = (180, 180, 180)
WHITE = (255,255,255)
pygame.init();
screen = pygame.display.set_mode([500, 650])
pygame.display.set_caption("Tic Tac Toe")
running = True
grid = [0, 0, 0, 0, 0, 0, 0, 0, 0]
player1 = [1, 3, 5, 7, 9]
player2 = [0, 2, 4 ,6 ,8]
choices = [0, 0, 0, 0,0]
used = []
gridValues = [-1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1]
value = -1
turn = 1
winningScreen = True
while running:
    screen.fill(WHITE);
    font = pygame.font.SysFont("monospace", 30)
    font2 = pygame.font.SysFont("Arial", 35)
    font3 = pygame.font.SysFont("Arial", 80)
    label = font.render("Tic Tac Toe", 1, PRIMARY);
    screen.blit(label, [140,0]);
    grid[0] = pygame.draw.rect(screen, PRIMARY, [20, 50, 140, 140])
    grid[1] = pygame.draw.rect(screen, PRIMARY, [180, 50, 140, 140])
    grid[2] = pygame.draw.rect(screen, PRIMARY, [340, 50, 140, 140])
    grid[3] = pygame.draw.rect(screen, PRIMARY, [20, 210, 140, 140])
    grid[4] = pygame.draw.rect(screen, PRIMARY, [180, 210, 140, 140])
    grid[5] = pygame.draw.rect(screen, PRIMARY, [340, 210, 140, 140])
    grid[6] = pygame.draw.rect(screen, PRIMARY, [20, 370, 140, 140])
    grid[7] = pygame.draw.rect(screen, PRIMARY, [180, 370, 140, 140])
    grid[8] = pygame.draw.rect(screen, PRIMARY, [340, 370, 140, 140])
    for i in range(9):
        if (gridValues[i] != -1):
                label = font3.render(str(gridValues[i]), 1, numCOLOR);
                screen.blit(label, [grid[i].x + 48,grid[i].y + 25]);
            
    
    for i in range(5):
        if (turn == 1):
            lst = player1
        else:
            lst = player2
        if (lst[i] in used):
            choices[i] = [pygame.draw.rect(screen, GREY, [20+i*(20+76),550, 76, 76]), lst[i]]
        else:
            if(lst[i] == value):
                choices[i] = [pygame.draw.rect(screen, SECONDARY, [20+i*(20+76),550, 76, 76]), lst[i]]
            else:
                choices[i] = [pygame.draw.rect(screen, PRIMARYChoice, [20+i*(20+76),550, 76, 76]), lst[i]]
                
        label = font2.render(str(lst[i]), 1, numCOLOR);
        screen.blit(label, [20+i*(20+76) + 30,550 + 18]);
            
            
    
    for event in pygame.event.get():
        if(event.type == pygame.QUIT):
            running = False
            winningScreen = False
        if(event.type == pygame.MOUSEBUTTONUP):
           pos = pygame.mouse.get_pos();
           for i in range(len(choices)):
               if (choices[i][0].collidepoint(pos)):
                   value = choices[i][1]
           for i in range(len(grid)):
               if (grid[i].collidepoint(pos)):
                   if (value != -1 and gridValues[i] == -1):
                     gridValues[i] = value
                     used.append(value)
                     value = -1
                     turn =  turn * -1
    if (winGame(gridValues) or not -1 in gridValues):
        running = False
        
    pygame.display.update();


while winningScreen:
    screen.fill(WHITE)
    if (winGame(gridValues)):
        if (turn == 1):
            label = font.render("Player 2 Won!" , 1, PRIMARY)
        else:
            label = font.render("Player 1 Won!", 1, PRIMARY)
    else:
        label = font.render("TIE >,>", 1, PRIMARY)
    screen.blit(label, [125,240])
    for event in pygame.event.get():
        if(event.type == pygame.QUIT):
            winningScreen = False
    pygame.display.update();


pygame.quit()
quit()
