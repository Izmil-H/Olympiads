import sys;
input = sys.stdin.readline;

for _ in range(int(input())):
    items = {}
    for store in range(int(input())):
        for i in range(int(input())):
            name, price, quantity = input().strip().split()
            if name not in items:
                items[name] = []
            items[name].append((int(price), int(quantity)))
    cost = 0
    for i in range(int(input())):
        name, amount = input().strip().split()
        items[name].sort(key=lambda x: x[0])
        amount = int(amount)
        for e in items[name]:
            if amount >= e[1]:
                cost += e[0] * e[1]
                amount -= e[1]
            else:
                cost += e[0] * amount
                break
    print(cost)