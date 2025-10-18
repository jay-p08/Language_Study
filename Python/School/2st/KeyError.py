if __name__ == "__main__" :
    dictionary = {
        "name" : "홍길동",
        "age" : 30,
    }

    try :
        print( dictionary[ "없다고" ] )
    except KeyError as e :
        print( "KeyError를 처리합니다" )
        print( e )