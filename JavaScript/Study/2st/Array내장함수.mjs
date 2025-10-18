// var fruits1 = [ "Banana", "Orange", "Apple" ];

// toString()
// console.log( fruits1.toString() );
// // join()
// console.log( fruits1.join() );

// var txt1 = "Banana<br>";
// txt1 += "Orange<br>";
// txt1 += "Apple<br>";

// console.log( txt1 );
// document.getElementById( "div1" ).innerHTML = txt1;

// var arr1 = [];
// arr1.push( "Banana" );
// arr1.push( "Orange" );
// arr1.push( "Apple" );

// console.log( arr1 );
// document.getElementById( "div1" ).innerHTML = arr1.join( "<br>" );

// pop() 배열의 가장 마지막 항목을 제거하여 리턴
// var fruits2 = [ "Banana", "Orange", "Apple" ];
// var arr2 = fruits2.pop();

// console.log( arr2 );
// console.log( fruits2 );

// push() 배열의 가장 마지막에 항목을 추가
// fruits2.push( "kiwi" );

// console.log( fruits2 );

// stack 구현 : push(), pop() 이용

// shift() 배열의 첫번째 항목을 제거하여 리턴
// var fruits3 = [ "Banana", "Orange", "Apple" ];
// var str = fruits3.shift();

// console.log( str );
// console.log( fruits3 );

// Queue shift(), push()

// unshift() 배열의 첫번째에 새로운 항목을 추가
// var fruits4 = [ "Banana", "Orange", "Apple" ];

// fruits4.unshift( "Lemon" );
// console.log( fruits4 );

// fruits4[0] = "Grape";
// console.log( fruits4 );
// fruits4[fruits4.length] = "Peach";
// console.log( fruits4 );

// stack : push, pop
// queue : shift, push
// deque : push, pop, shift, unshift

// splice( a, b, c ) : 특정 위치의 배열의 아이템을 삭제 또는 추가
// ★★★★★
// a : 시작위치
// b : 삭제할 항목수
// var fruits5 = [ "Banana", "Orange", "Apple" ];
// fruits5.splice( 1, 2 );
// fruits5.splice( 1, 0, "Lemon", "kiwi" );
// fruits5.splice( 1, 1, "Lemon", "kiwi" );

// var su1 = [1, 2];
// var su2 = ["일" ,"이", "삼"];
// var su = su1.concat( su2 );

// var fruits6 = [ "Banana", "Orange", "Apple" ];
// var fruits7 = fruits6.slice( 1 );
// var fruits7 = fruits6.slice( 1, 2 );
// var fruits7 = fruits6.slice( 1, 3 );

// sort : 정렬( 오름차순, 내림차순 )
// var fruits8 = [ "Banana", "Orange", "Apple" ];
// var points = [40, 100, 70, 21, 99];

// console.log( points.sort() );
// console.log( points.sort( ( a, b ) => a - b ) );
// console.log(points.sort((a, b) => b - a));
// console.log(points.reverse());

// var persons = [
//     { name: "유재석", point: 78, city : "서울" }, 
//     { name: "김종국", point: 92, city : "부산" }, 
//     { name: "양세찬", point: 76, city : "대구" }, 
//     { name: "하  하", point: 81, city : "제주" }, 
// ];
// persons.sort( ( x, y ) => y.point - x.point );

// persons.sort( ( a, b ) => (a.point > b.point) ? a.point - b.point : (a.point > b.point) ? b.point  - a.point : 0 )
// persons.forEach(element => {
//     if( element.city == "제주" ) path.push( element );
// });

// var path = persons.filter( ( obj ) => obj.city == "제주" );

// reduce( a, c ) ★★★
// a : acumulator == "누산기"
// c : currentValut == "현재값"

// var arr3 = [ 1, 2, 3, 4 ];
// var sum = 0;
// arr3.forEach(element => {
//     sum += element;
// });
// sum = arr3.reduce( ( a, c ) => a - c );

// map() ★★★★★ : filter()와 다른 형태로 기존의 배열을 새로운 형태로 가공해서 새로운 배열을 생성
var userlist = [
    { firstname : "재석", lastName : "유", gmail : "yu@gmail.com" },
    { firstname : "종국", lastName : "김", gmail : "kim@gmail.com" },
    { firstname : "세찬", lastName : "양", gmail : "yang@gmail.com" },
    { firstname : "석진", lastName : "지", gmail : "ji@gmail.com" }
];
var userlist2 =  userlist.map( ( user ) => user.lastName + user.firstname );
console.log( userlist2 );