from datetime import date as DT

if __name__ == "__main__" :
    today = DT.today()
    D_day = DT( 2025, 12, 25 )
    print( D_day - today )