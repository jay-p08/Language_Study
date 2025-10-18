// 부분 집합 구하기 n을 입력 받으면 n까지의 부분집합을 구한다.
// 이진트리를 이용하여 만들어라.
// 프리오더를 이용하셈.
// 입력 3.
// 출력 : 1, 2, 3, 12, 13, 23, 123, 공집합

function preOrder( n, arr = [], idx = 1 ) {
    if ( idx > n ) {
        console.log( arr );
        return;
    } // if
    preOrder( n, [ ...arr, idx ], idx + 1 );
    preOrder( n, arr, idx + 1 );
} // preOrder()

console.log(preOrder(4));