punctuationMarks = [" ", ".", ",", ":", ";", "!", "?", "[", "]"]
arrayCode = input("Enter a Delphi array: ")


#using code from the first question, in order to split the code into "words"
wordsList = []
tempWord = ""

print("Your code: ", arrayCode, "\n")

for i in arrayCode: #run through each character in sentence
     if i not in punctuationMarks: #if its not a punctuation mark, add to a temporary word
          tempWord += i
     else: #if it is a punctuation mark, add the temp word to words list
          if tempWord != "":
               wordsList.append(tempWord)
          
          if i != " ":
               wordsList.append(i)

          tempWord = ""

#create information for the variable
numOfDimensions = 0
tempDimension = []
dimensions = []
arrayType = ""

for i in range(len(wordsList)): #loop through each "word" in the entered code
     if wordsList[i] == "[": #if the current word is "[", it means the following words until "]" are dimension information
          for j in range(i, len(wordsList)):
               if wordsList[j] == ",":
                    dimensions.append(tempDimension)
                    tempDimension = []
                    numOfDimensions += 1
               elif wordsList[j] == "]":
                    dimensions.append(tempDimension)
                    numOfDimensions += 1
                    break
               elif wordsList[j].isdigit():
                    tempDimension.append(wordsList[j])
     elif wordsList[i] == "of": #if the current word is "of", it means the next word is the type of array
          arrayType = wordsList[i+1]

#create and fill descriptor with information
descriptor = []

if numOfDimensions > 1:
     descriptor.append("Multidimensional array")
else:
     descriptor.append("Array")

for i in range(numOfDimensions):
     descriptor.append(arrayType)

descriptor.append(str(numOfDimensions))

for i in dimensions:
     descriptor.append(i)

descriptor.append("1000")

print("Descriptor: ", descriptor)