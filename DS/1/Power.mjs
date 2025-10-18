const Power = ( x, n ) => n == 0 ? 1 : x * Power( x, n-1 );

console.log( Power( 2, 5 ) );