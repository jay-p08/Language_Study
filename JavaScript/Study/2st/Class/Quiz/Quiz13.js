class NumberOE {
    constructor() {
		this.odd = [];
		this.even = [];
	}

    set save( arr ) 
    {
        for ( let num of arr ) {
            if ( num % 2 == 0 ) 
            {
                this.even.push( num );
            } // if
            else
            {
                this.odd.push( num );
            } // else
        } // for
    } // save()

    get showOdd() 
    {
        return this.odd;
    } // showOdd

    get showEven() 
    {
        return this.even;
    } // showEven()

    get showAll() 
    {
        return [...this.odd, ...this.even]; 
    } // showAll()
}

// 사용 예시
const oe = new NumberOE();

oe.save = [1, 2, 3, 12, 13, 15];

console.log("홀수:", oe.showOdd);   // [1, 3, 13, 15]
console.log("짝수:", oe.showEven); // [2, 12]
console.log("전체:", oe.showAll);  // [1, 3, 13, 15, 2, 12]