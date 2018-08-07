#Tracy Joseph
#Assignment 6C: Memory Leaks and Stack Overflow

def increment(i):
    print("i = " + str(i))
    increment(i+1)

print(increment(1))
