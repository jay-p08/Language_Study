if __name__ == "__main__":
    input = int(input("입력 >> "))
    if input % 2 == 0 :
        input -= 1
    num = input // 2
        
    for i in range(num ):
        print(" " * i + "*" * (input - 2 * i))
        
    for i in range(num + 1):
        print(" " * (num - i) + "*" * (2 * i + 1))