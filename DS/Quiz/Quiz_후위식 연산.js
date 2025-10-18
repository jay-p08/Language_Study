function solution(str) {
    let stack = [];

    for (let x of str) {
        if (x > 0)
            stack.push(x);
        switch (x) {
            case "+":
                stack.push(Number(stack.pop()) + Number(stack.pop()));
                console.log(stack);
                break;
            case "*":
                stack.push(Number(stack.pop()) * Number(stack.pop()));
                break;
            case "-":
                stack.push(Number(stack.pop()) - Number(stack.pop()));
                break;
            default:
                break;
        }
    } // for
    return stack.join();
} // solution

let str = "352+*9-";
console.log(solution(str));