// 이진트리 ( DFS )
// 선생님이 주신 N개의 문제를 푼다.
// 각 문제는 그것을 풀었을 때 얻는 점수와 시간이 주어진다.
// M안에 N개의 문제를 중 최대
// 최대 시간인 20분 안에 가장 점수를 크게 받을 수 있는 점수는?
// 출력 41

function solution( m, ps, pt ) {
    let answer = Number.MIN_SAFE_INTEGER;

    function DFS( idx, sum, time ) {
        if( time > m ) return;
        if( idx == ps.length )
        {
            if( sum > answer ) answer = sum;
            return;
        } // if
        DFS( idx + 1, sum + ps[ idx ], time + pt[ idx ] );
        DFS( idx + 1, sum, time );
    } // DFS()
    DFS( 0, 0, 0 );

    return answer;
} // solution()

let ps = [ 10, 25, 15, 6, 7 ]
let pt = [ 5, 12, 8, 3, 4 ]

console.log( solution( 20, ps, pt ) );