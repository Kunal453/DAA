itstep = 0
recstep = 0

def ItStepFibonacci(n):
    v = [0, 1]

    for i in range(2, n + 1):
        global itstep
        itstep += 1
        v.append(v[i - 1] + v[i - 2])

    return v[-1]

def RecStepFibonacci(x):
    global recstep
    if x == 1 or x == 0:
        return x
    else:
        recstep += 1
        return RecStepFibonacci(x - 1) + RecStepFibonacci(x - 2)

if __name__ == "__main__":
    n = int(input("Enter a number: "))
    print("Fibonacci value (recursive):", RecStepFibonacci(n))
    print("Fibonacci value using Iteration:", ItStepFibonacci(n))
    print("Number of steps taken by recursion:", recstep)
    print("Iterative steps:", itstep)

