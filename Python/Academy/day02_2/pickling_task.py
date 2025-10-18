# 피클링
# 파이썬 객체를 객체째로 파일에 저장하는 기술
# 변수, 함수, 클래스, 기타 자료구조 무엇이든 파일로 저장할 수 있다
# 피클링된 객체를 되돌리면 원본상태 그대로 다시 사용할 수 있다.
import pickle

def write_to_pickle() :
    data = {
        "name" : "홍길동",
        "age" : 30,
    }
    with open( "data.pkl", "wb" ) as f :
        pickle.dump( data, f )

def read_from_pickle( file_path ) :
    with open( file_path, "rb" ) as f :
        loaded_data = pickle.load( f )
    return loaded_data

if __name__ == "__main__" :
    # write_to_pickle()
    data = read_from_pickle( "data.pkl" )
    print( data )