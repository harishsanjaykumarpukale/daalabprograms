text = input("Enter the text")
pattern = input("Enter the pattern")

from collections import defaultdict

badMatchTable = defaultdict(list)

l = len(pattern)

for i in range(0,l-1):
  badMatchTable[pattern[i]] = l - 1 - i  

i = l-1

while(i<len(text)):
  if(text[i] == pattern[l-1]):
    cur = i-1
    j = l-2
    while(cur>=i-l+1):
      if(text[cur] == pattern[j]):
        cur-=1
        j-=1
      else:
        try:
          i+=ibadMatchTable[text[cur]]
        except:
          i+=l
        break
    print("The pattern is found at " + str(cur+2) + " position")
    exit()
  else:
    try:
      i+=ibadMatchTable[text[cur]]
    except:
      i+=l
    
print("The pattern is not found")
