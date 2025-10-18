function myFunction( number ) {
    let t
    if( number >= 1 ) return number;
    console.log( t );
    myFunction( number - 1 );
}

myFunction(5)