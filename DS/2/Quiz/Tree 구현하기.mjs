function preOrder( arr, idx = 1 ) {
    if( idx >= 8 ) return;
    console.log( arr[idx] )
    preOrder( arr, 2 * idx )
    preOrder( arr, 2 * idx + 1 )
}
function inOrder( arr, idx = 1 )
{
    if( idx >= 8 ) return;
    inOrder( arr, 2 * idx )
    console.log( arr[idx] )
    inOrder( arr, 2 * idx + 1 )
}
function postOrder( arr, idx = 1 )
{
    if( idx >= 8 ) return;
    inOrder( arr, 2 * idx )
    inOrder( arr, 2 * idx + 1 )
    console.log( arr[idx] )
}

let arr = [ 0, 1, 2, 3, 4, 5, 6, 7 ]
console.log( preOrder( arr ) );
console.log( inOrder( arr ) );
console.log( postOrder( arr ) );