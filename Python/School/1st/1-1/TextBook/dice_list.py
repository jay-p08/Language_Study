import random

if __name__ == "__main__" :
    def dice_list( dice, count ) :
        a = []
        for i in range( count ) :
            a.append(random.randrange(1, dice))
        return a
    
    print( dice_list(6, 5) )