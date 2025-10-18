import { Queue } from "../Queue.mjs";

function solution(str1, str2) {
    let queue = str1.split("");
    str2 = str2.split("");
    str2.forEach(x => {
        if (queue.includes(x)) if (x !== queue.shift()) return "NO";
    });

    if( queue.length > 0 ) return "NO";

    return "YES";
} // solution

let str1 = "CBA";
let str2 = "QADEBC"
console.log(solution(str1, str2));