import functools as ft
import random as r

N = 5
gamePath = [0]*N
playerPosition = 0
playerHealth = 10
playerChoice = 0
playerScore = 0

gamePath = []
for i in range(5):
     gamePath.append(r.randrange(2))

gameElements = ["a friend", "an enemy", "a button"]


while True:
     print("--------------")
     print("Game list:", gamePath)
     print("There are", len(list(filter(lambda x: True if x == 0 else False, gamePath))), "friends and", len(list(filter(lambda x: True if x == 1 else False, gamePath))), "enemies")
     print("Your health is", playerHealth)
     print("Your score is", playerScore)
     print("--------------")

     print("You see", gameElements[gamePath[playerPosition]])
     print("1 - Interact\n2 - Ignore")
     
     playerChoice = int(input("What will you do? "))

     while playerChoice != 1 and playerChoice != 2:
          playerChoice = int(input("What will you do? "))

     if playerChoice == 1:
          if gamePath[playerPosition] == 0:
               playerScore -= 1
               playerHealth += int(r.randrange(3)+1)
          elif gamePath[playerPosition] == 1:
               playerScore += 1
               playerHealth -= int(r.randrange(3)+1)
          elif gamePath[playerPosition] == 2:
               if r.choice([True, False]):
                    print("All friends became enemies!")
                    gamePath = list(map(lambda x: 1 if x == 0 else x , gamePath))
               else:
                    print("All enemies became friends!")
                    gamePath = list(map(lambda x: 0 if x == 1 else x, gamePath))
          
     if playerHealth <= 0:
          print("You died!")
          break
     elif playerPosition == N-1:
          print("You won!")
          break
     else:
          playerPosition += 1