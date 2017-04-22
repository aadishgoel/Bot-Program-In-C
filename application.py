from os import startfile
import time
matrix=[[0,0,0],[0,0,0],[0,0,0]]

def pmat(file=None):
    for line in matrix:
        print(*line,file=file)

def screen():
    for line in matrix:
        for item in line:
            if item==1:
                print(' X',end=' |')
            elif item==2:
                print(' O',end=' |')
            else:
                print('   ',end='|')        
        print()
    print()
    
def run():
    with open('input.txt','w') as fw:
        pmat(file=fw)
        print(botid,file=fw)
    startfile('bot_tictactoe.exe')
    time.sleep(.5)
    with open('output.txt') as fr:
        data=fr.read()
        x,y=map(int,data.split())
        matrix[x][y]=botid           
        
def draw():
    if not any([True for i in range(3) for j in range(3) if matrix[i][j]==0]):
        return True
    return False

def check(id):
    if matrix[0][0]==id and matrix[0][1]==id and matrix[0][2]==id:
        return id
    if matrix[1][0]==id and matrix[1][1]==id and matrix[1][2]==id:
        return id
    if matrix[2][0]==id and matrix[2][1]==id and matrix[2][2]==id:
        return id
    if matrix[0][0]==id and matrix[1][1]==id and matrix[2][2]==id:
        return id
    if matrix[0][0]==id and matrix[1][0]==id and matrix[2][0]==id:
        return id
    if matrix[0][1]==id and matrix[1][1]==id and matrix[2][1]==id:
        return id
    if matrix[0][2]==id and matrix[1][2]==id and matrix[2][2]==id:
        return id
    if matrix[0][2]==id and matrix[1][1]==id and matrix[2][0]==id:
        return id
    return None




print('''               ********* TIC TAC TOE *********
                         With A BOT 
''')

playerid=None
while True:
    raw=input('\t\t\tChoose a player from X or O: ')
    print()
    if raw=='O' or raw=='o' or raw=='0' or raw=='2':
        playerid=2
        botid=1
        run()
        break
    elif raw=='X' or raw=='x' or raw=='1':
        playerid=1
        botid=2
        break
    else:
        print('Invalid Choice')



while True:
    screen()

    while True:
        raw=input('Enter your move : ')
        print()
        if not raw.isdigit():
            print('Invalid Move')
            continue
        raw=int(raw)-1
        if 0<=raw<=9 and not matrix[raw//3][raw%3] :
            matrix[raw//3][raw%3]=playerid
            break
        else:
            print('Invalid Move')

    if check(playerid):
        screen()
        print("\t\t\t** YOU WIN ** : Wanna Play Again\n\n")
        break
    elif draw():
        print('\t\t\t** Draw ** : Try Something New\n\n')
        break
    
    run()
    if check(botid):
        screen()
        print('\t\t\t** GAME OVER ** : Better Luck Next Time\n\n')
        break
    elif draw():
        print('\t\t\t** Draw ** : Try Something New\n\n')
        break
        
    

