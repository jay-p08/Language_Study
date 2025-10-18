// function factorlal( number ) {
//     let sum = 1;
//     for( let i = 1 ; i <= number ; i++ ) {
//         sum *= i;
//     }
//     return sum
// }

// console.log( factorlal( 5 ) );

const factorlal = ( number ) => number === 1 ? 1 : number * factorlal( number-1 );

console.log( factorlal( 5 ) );