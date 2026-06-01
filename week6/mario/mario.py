from cs50 import get_int

def piramide (height):
    for x in range(height):
        for y in range(height - x - 1):
            print(f" ", end="")
        for y in range(x+1):
            print(f"#",end="")
        print(f"  ",end="")
        for y in range(x+1):
            print(f"#",end="")
        print(f"\n",end="")

h = 0
while h<1 or h>8:
    h = get_int("Height: ")
piramide(h)
