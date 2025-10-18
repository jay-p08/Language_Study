if __name__ == "__main__" : 
    store = {
        "콜라" : 1500,
        "사이다" : 1300,
        "과자" : 2000,
        "초콜릿" : 1000,
    }

    for i in store :
        print( "(", i, ",", store.get( i ), ")" )