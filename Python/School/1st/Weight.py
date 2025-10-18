if __name__ == "__main__" :
    isDecrease = True
    nowWeight, goalsWeight = map( int, input( "현재 몸무게, 목표 몸무게 >>> " ).split() )
    print( "현재 몸무게 : ", nowWeight )
    print( "목표 몸무게 : ", goalsWeight )
    while isDecrease :
        print( i, end = "")
        decreaseWeight = int(input( "주차 감량 몸무게 : " ))
        nowWeight -= decreaseWeight
        i+=1
        if nowWeight <= goalsWeight :
            print( nowWeight, "달성! 축하합니다!" )
            isDecrease = False

