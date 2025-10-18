if __name__ == "__main__" :
    str = "abcdef"
    cnt = len(str)-1
    while True :
        if cnt == -1 :
            break
        print( str[cnt], end=" " )
        cnt -= 1