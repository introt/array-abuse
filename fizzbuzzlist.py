#!/usr/bin/python3

a = ["fizzbuzz", False, False, "fizz", False, "buzz", "fizz", False, False, "fizz", "buzz", False, "fizz", False, False]

def fizzbuzz(n):
    result = a[n % 15]
    return result if result else n

if __name__ == '__main__':
    i = 1
    while i <= 100:
        print(fizzbuzz(i))
        i += 1
        
