def is_add(a, b, is_add : bool) :
    if is_add :
        return a + b
    else :
        return a - b

if __name__ == "__main__" :
    result1 = is_add(10, 10, 1)
    result2 = is_add(10, 10, 0)
    print(result1, result2)