// function ArraySum( NumArry ) {
//     let sum = 0;
//     for( let i = 0 ; i < array.length ; i++ ) {
//         sum += NumArry[i];
//     }
//     return sum;
// }

let array = [1, 2, 3, 4, 5];
// console.log( ArraySum(array) )

const ArraySum = ( NumArray ) => NumArray.length == 1 ? NumArray[0] : ArraySum( NumArray.slice( 0, -1 ) ) + NumArray[ NumArray.length - 1 ];

console.log( ArraySum( array ) );