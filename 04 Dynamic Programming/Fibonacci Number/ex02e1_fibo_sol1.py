allFibonacci = [0,1]
def fibonacci(N):
    if(N < len(allFibonacci)):
        return allFibonacci[N]
    
    result = fibonacci(N-2) + fibonacci(N-1)
    allFibonacci.append(result)
    return result

N = int(input())
print(fibonacci(N))