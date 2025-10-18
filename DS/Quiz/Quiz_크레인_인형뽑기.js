function solution(board, moves) {
    let stack = [];
    let doll = 0;
    let result = 0;

    moves.forEach(order => {
        for (let i = 0; i < board.length; i++) {
            if (board[i][order-1] !== 0) {
                doll = board[i][order-1];
                board[i][order-1] = 0;
                
            } // if
            if (stack[stack.length - 1] == doll) {
                stack.pop();
                result += 2;
            } // if
            else {
                stack.push(doll);
            } // else
            break;
        }
        
    }); // forEach

    return result;
} // solution

function test(board, order) {
    
}

let board = [
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 3],
    [0, 2, 5, 0, 1],
    [4, 2, 4, 4, 2],
    [3, 5, 1, 3, 1],
]
let moves = [1, 5, 3, 5, 1, 2, 1, 4];

console.log(solution(board, moves));