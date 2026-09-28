# bank account with a menu
bal = 0.0


def show(v):
    if v == int(v):
        return str(int(v))
    else:
        return format(v, ".2f")


while True:
    choice = int(input())
    if choice == 1:
        amt = float(input())
        bal = bal + amt
        print("Deposited " + show(amt) + ", Balance = " + show(bal))
    elif choice == 2:
        amt = float(input())
        bal = bal - amt
        print("Withdrew " + show(amt) + ", Balance = " + show(bal))
    elif choice == 3:
        print("Balance = " + show(bal))
    elif choice == 4:
        print("Goodbye")
        break
