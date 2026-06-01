from cs50 import get_string

text = get_string("Write a text: ")
l = 0
w = 1
s = 0

def index(l, w, s):
    index = (int(round(0.0588 * l/w * 100 - 0.296 * s/w * 100 - 15.8)))
    return index

for char in text:
    # Se for letra
    if char.isalpha():
        l = l+1
    elif char == ' ':
        w = w+1
    elif char == '!' or char == '.' or char == '?':
        s = s+1

grade = index(l,w,s)

if grade < 0:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print("Grade",grade)


