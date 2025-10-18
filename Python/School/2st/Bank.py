class InsufficientBalanceError( Exception ) :
    def __str__( self ) :
        return f"IBE 에러"
    
class WrongAccountNumberError( Exception ) :
    def __str__( self ) :
        return f"WANE 에러"
    
def newAccountNumber( AccountNumber, Money ) :
    bank[AccountNumber] = Money

def notAccountNumber( AccountNumber ) :
        if AccountNumber in bank :
            pass
        else :
            raise WrongAccountNumberError

def deposit( AccountNumber, Money ) :
        notAccountNumber( AN )
        bank[AccountNumber] += Money

def withdraw( AccountNumber, Money ) :
    notAccountNumber( AccountNumber )
    if bank[AccountNumber] - Money < 0 :
        raise InsufficientBalanceError
    else : 
        bank[AccountNumber] -= Money

if __name__ == "__main__" :
    bank = {

    }
    while( True ) :
        AN = input( "계좌번호를 입력하세요 >>> " )
        try :
            menu = int( input( "메뉴를 골라주세요( 1. 입금, 2. 출금, 0. 종료 ) >>> " ) )
            if menu == 1 :
                Money = int( input( "얼마를 입급하시겠습니까? >>> " ) )
                deposit( AN, Money )
                print( bank[AN] )
            elif menu == 2 :
                Money = int( input( "얼마를 출금하시겠습니까? >>> " ) )
                withdraw( AN, Money )
                print( bank[AN] )
            elif menu == 0 :
                break
            else :
                print( "알맞는 메뉴를 골라주세요" )            
                
        except WrongAccountNumberError as e :
            print( e )
            newAccountNumber( AN, Money )
        
        except InsufficientBalanceError as e :
            print( e )