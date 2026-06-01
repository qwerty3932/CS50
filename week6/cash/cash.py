from cs50 import get_float
cc = 0 # customer cents
cash = 0 # customer cash
coins = 0

while True:
    cash = get_float("Cash: ")
    if cash >= 0:
            break
cc = int(round(cash * 100))
while cc > 0:
        if cc >= 25:
            cc = cc - 25
            coins = coins + 1
        elif cc >= 10:
            cc = cc - 10
            coins = coins + 1
        elif cc >= 5:
            cc = cc - 5
            coins = coins + 1
        elif cc >= 1:
            cc = cc - 1
            coins = coins + 1

print("Coins:", coins)
