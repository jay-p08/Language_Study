def func_01() :
    print("매개변수x, 반환x")

def func_ox(val) :
    print(val)

def func_xo() :
    return "홍길동"

def func_oo(fname, lname) :
    result = f"{fname} {lname}"
    return result

if __name__ == "__main__" :
    var = func_oo("박", "재영")
    print(var)