#There is a little dog in the University. The little cat saw the dog in the University.

#loop through each word, and add them to a new list IF they are not stop words or punctuation marks
def removeStopWords(words):
     cleanWords = []

     for i in words:
          if i.upper() not in stopWords and i not in punctuationMarks:
               cleanWords.append(i)

     return cleanWords

#loop through each word and add them to a dictionary. if they are already in the dict., increment their value by 1
def wordsToDictionary(words):
     newDict = {}

     for i in words:
          if i in newDict:
               newDict[i] += 1
          else:
               newDict[i] = 1

     return newDict

#loop through all words, and add them to a new list, IF they aren't previously added (a new list with no duplicates)
def removeDuplicateWords(words):
     newList = []

     for i in words:
          if i not in newList:
               newList.append(i)

     return newList

#loop through words in numbers, with steps of 3 (see the range() function), and add a new slice of the words list to the phraseList
def makePhrases(words):
     phraseList = []

     for i in range(0, len(words), 3):
          phraseList.append(words[i:i+3]) #go through words 3 by 3, and add all three to phraseList
               
     return phraseList
     
          
          
stopWords = ["A", "AN", "THE"]
punctuationMarks = [" ", ".", ",", ":", ";", "!", "?"]

sentence = input("Enter a sentence: ")
wordsList = []
tempWord = ""

print("Your sentence: ", sentence, "\n")

for i in sentence: #run through each character in sentence
     if i not in punctuationMarks: #if its not a punctuation mark, add to a temporary word
          tempWord += i
     else: #if it is a punctuation mark, add the temp word to words list
          if tempWord != "":
               wordsList.append(tempWord)
          
          if i != " ":
               wordsList.append(i)

          tempWord = ""


print("First list: ", wordsList, "\n")
wordsList = removeStopWords(wordsList)
print("After removal: ", wordsList, "\n")

wordsDict = wordsToDictionary(wordsList)
print("Dictionary: ", wordsDict, "\n")

wordsList = removeDuplicateWords(wordsList)
print("No duplicates: ", wordsList, "\n")

phraseList = makePhrases(wordsList)
print("Phrases: ", phraseList, "\n")
