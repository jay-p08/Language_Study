function fnFindMax( numbers )
{
    return Math.max( ...numbers )
}

var numbers = [2,3,4,5,6,1,3,2,5,5,4,6,7];

console.log( fnFindMax( numbers ) ) // fnFindMax 호출하기, numbers 매개변수로 넣어주기