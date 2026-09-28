# simple bank account, one transaction
import sys
data = sys.stdin.read().split()
bal = float(data[0])
op = data[1]
amt = float(data[2])

if op == "D" or op == "d":
    bal = bal + amt
if op == "W" or op == "w":
    bal = bal - amt

if bal == int(bal):
    print("Balance = " + str(int(bal)))
else:
    print("Balance = " + format(bal, ".2f"))
