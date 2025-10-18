// 이진트리 ( DFS )
// 바둑이들을 데리고 시장에 가려고 한다. 트럭은 C킬로그램 이상을 태울 수 없으며, 최대 무게를 넘지 않는 선에서 가장 많은 바둑이들을 데리고 가야 한다.
// 바둑이들의 몸무게 합은?
// 출력 : 242

function solution( c, arr ) {
    let answer = Number.MIN_SAFE_INTEGER;

    function DFS( idx, sum ) {
        if( sum > c ) return;
        if( idx == arr.length )
        {
            if( sum > answer ) answer = sum;
            return;
        } // if
        DFS( idx + 1, sum + arr[idx] );
        DFS( idx + 1, sum );
    } // DFS()
    DFS( 0, 0 );

    return answer;
} // solution()

let arr = [ 81, 58, 42, 33, 61 ];
console.log( solution( 10000000000, arr ) );