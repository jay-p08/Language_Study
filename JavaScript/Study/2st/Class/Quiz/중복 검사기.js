const checker = createChecker();

function createChecker() {
    const seen = new Set();
    return function (word) {
        if (seen.has(word)) {
            return "중복";
        } else {
            seen.add(word);
            return "통과";
        }
    };
}

console.log(checker("apple"));   // "통과"
console.log(checker("banana"));  // "통과"
console.log(checker("apple"));   // "중복"
console.log(checker("orange"));  // "통과"
console.log(checker("banana"));  // "중복"