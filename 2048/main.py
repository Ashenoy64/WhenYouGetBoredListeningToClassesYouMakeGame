from random import randint
import os
class Game2042:
    def __init__(self):
        self.board=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
        self.dir='a'
        self.input=['w','a','s','d','exit']
        self.createBoard()
        self.play()


    def Playerinput(self):
        while(True):
            self.dir=input()
            if(self.dir in self.input):
                break

    def createBoard(self):
        count=0
        while(count!=2):
            x=randint(0,3)
            y=randint(0,3)
            if(self.board[x][y]==0):
                count+=1
                self.board[x][y]=2
                
        

    def compress(self):
        if self.dir=='w':
            for k in range(0,4):
                start=0
                for i in range(0,4):
                    if(self.board[start][k]!=0):
                        start+=1
                    else :
                        break
                for j in range(start+1,4):
                    if(self.board[j][k]!=0):
                        self.board[start][k]=self.board[j][k]
                        self.board[j][k]=0
                        start+=1
        elif self.dir=='a':
            for k in self.board:
                if 0 not in k:
                    continue
                start=k.index(0)
                
                for i in range(start+1,4):
                    if(k[i]!=0):
                        k[start]=k[i]
                        k[i]=0
                        start+=1
        elif self.dir=='d':
            for k in range(0,4):
                start=3
                for i in range(0,4):
                    if(self.board[k][start]!=0):
                        start-=1
                    else :
                        break
                for j in range(start-1,-1,-1):
                    if(self.board[k][j]!=0):
                        self.board[k][start]=self.board[k][j]
                        self.board[k][j]=0
                        start-=1
        elif self.dir=='s':
            for k in range(0,4):
                start=3
                for i in range(0,4):
                    if(self.board[start][k]!=0):
                        start-=1
                    else :
                        break
                for j in range(start-1,-1,-1):
                    if(self.board[j][k]!=0):
                        self.board[start][k]=self.board[j][k]
                        self.board[j][k]=0
                        start-=1

        elif self.dir=='exit':
            exit()
        


    def printBoard(self):
        print()
        for i in self.board:
            for j in i:
                print(j,"   ",end="")
            print()
            print()


    def check(self):
        for i in self.board:
            if 0 in i:
                return True
        
        return False
    def merge(self):
        if(self.dir=='w'):
            for i in range(0,4):
                for j in range(1,4):
                    if(self.board[j][i]==self.board[j-1][i]):
                        self.board[j-1][i]*=2
                        self.board[j][i]=0
        elif(self.dir=='s'):
            for i in range(0,4):
                for j in range(2,-1,-1):
                    if(self.board[j][i]==self.board[j+1][i]):
                        self.board[j+1][i]*=2
                        self.board[j][i]=0
        elif(self.dir=='a'):
            for i in range(0,4):
                for j in range(1,4):
                    if(self.board[i][j]==self.board[i][j-1]):
                        self.board[i][j-1]*=2
                        self.board[i][j]=0
        elif(self.dir=='d'):
            for i in range(0,4):
                for j in range(2,-1,-1):
                    if(self.board[i][j]==self.board[i][j+1]):
                        self.board[i][j+1]*=2
                        self.board[i][j]=0
            

    def generate(self):
        while(True):
            x=randint(0,3)
            y=randint(0,3)
            if(self.board[x][y]==0):
                self.board[x][y]=2
                break

    def play(self):
        while(self.check()):
            os.system('cls')
            self.printBoard()
            self.Playerinput()
            self.compress()
            self.merge()
            self.compress()
            self.generate()

        m=0
        for l in self.board:
            m=max(m,max(l))

        print("Player Score is ",m)

    

if __name__=="__main__":
    obj=Game2042()
