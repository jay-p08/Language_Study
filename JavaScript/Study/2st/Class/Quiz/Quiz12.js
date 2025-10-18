function countChars( str ) {
    const result = {};
    for ( let char of str ) {
        result[char] = ( result[char] || 0 ) + 1;
    }
    return result;
}

console.log(countChars('aacbbb')); // { a : 2, b : 3, c : 1 }