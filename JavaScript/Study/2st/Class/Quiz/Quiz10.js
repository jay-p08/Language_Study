function sumAll( first, ...rest ) {
  return  [first, ...rest].reduce( ( acc, cur ) => acc + cur, 0 );
}
console.log(sumAll(2, 3, 4)); // 9
console.log(sumAll(5, 2));    // 7