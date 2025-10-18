class StockError( Exception ) :
    def __str__( self ):
        return f"SE 에러"

class PriceError( Exception ) :
    def __str__( self ) :
        return f"PE 에러"
    
class ProductNotFoundError( Exception ) :
    def __str__( self ) :
        return f"PNFE 에러"
    
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
    
class Inventory :
    def __init__( self, product : Product ) :
        self.Box = {

        }
        self.product = product

    def add_product( self, product : Product ) :
        if product.name in self.Box :
            self.Box[product.name].add_stock( product.quantity )
        else :
            self.Box[product.name] = product

    def remove_product( self, name : str, amount : int ) :
        if name in self.Box :
            self.Box[name].remove_stock( amount )
            if self.product[name] <= 0 :
                del self.Box[name]
        else :
            raise ProductNotFoundError
            

    def set_price( self, name : str, new_price : int ) :
        if name in self.Box :
            self.Box[name].set_price( new_price )
        else :
            raise ProductNotFoundError

    def get( self, name : str ) :
        if name in self.Box :
            return self.Box[name]
        else :
            raise ProductNotFoundError
    
    def total_inventory_value( self ) :
        sum = 0
        for i in self.Box.values() :
            sum += i.price * i.quantity
        return sum
    
    def __str__( self ) :
        if self.Box :
            pass
        else :
            pass
    
if __name__ == "__main__" :
    product = Product( "마우스", 1000, 5 )
    product2 = Product( "키보드", 1000, 5 )
    inventory = Inventory( product )
    try :
        inventory.add_product( product )
        # inventory.set_price( "마우스", 10000 ) 성공
        inventory.add_product( product )
        print( inventory.get( "마우스" ) )
        # inventory.add_product( product2 ) 성공
        # print( inventory.total_inventory_value() ) 성공
    except StockError as e :
        print( e )
    except PriceError as e :
        print( e )
    except ProductNotFoundError as e:
        print( e )
