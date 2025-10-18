if __name__ == "__main__" :
    try :
        print( 10 / 0 )
    except ZeroDivisionError as e :
        print( e )