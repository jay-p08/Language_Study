class StockError( Exception ) :
    def __str__( self ):
        return f"SE 에러"

class PriceError( Exception ) :
    def __str__( self ) :
        return f"PE 에러"
    
class Product :
    def __init__( self, name, price, quantity ) :
        self.name = name
        self.price = price
        self.quantity = quantity
    
    def set_price( self, price ) :
        if price < 0 :
            raise PriceError
        self.price = price
    
    def add_stock( self, quantity ) :
        if quantity <= 0 :
            raise StockError
        self.quantity += quantity

    def remove_stock( self, qunatity ) :
        if qunatity > self.quantity :
            raise StockError
        self.quantity -= qunatity

    def total_value( self ) :
        return self.price * self.quantity
    
    def __str__( self ) :
        return f"상품명 : { self.name }, 가격 : { self.price }, 재고 : { self.quantity }"
    
if __name__ == "__main__" :
    product = Product( "마우스", 1000, 5 )
    try :
        print( product.total_value() )
        print( product )
    except StockError as e :
        print( e )
    except PriceError as e :
        print( e )
