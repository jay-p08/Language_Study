# 이터레이터
# 반복 가능한 객체, 즉 이터러블 객체에 대해서
# 그 요소를 순차적으로 하나씩 반환할 수 있는
# 객체를 의미한다.
# 한번에 하나의 요소에 접근하며
# 메모리 효율적이다.

if __name__ == "__main__" :
    nums = [x for x in range(3)]
    iter_nums = iter(nums)
    # print(next(iter_nums))
    # print(next(iter_nums)*2)
    # print(next(iter_nums)*3)
    # print(next(iter_nums))
    # 기존 값의 길이를 활용하여 반복
    # iterator 객체는 len()함수에 넣을 수 없다.
    # for i in range(len(nums)) :
    #     print(next(iter_nums))

    # enumerate()
    # 전달된 이터러블 객체의 각 요소에 인덱스를 부여해서 
    # (index, element)와 같은 방식으로 set 자료형 의 값을
    # 반환하는 함수다.
    nums = [x*3 for x in range(10)]
    # for i, x in enumerate(nums) :
    #     print(f"{i:2d}. {x:2d}")

    for enum in enumerate(nums) :
        print(type(enum))