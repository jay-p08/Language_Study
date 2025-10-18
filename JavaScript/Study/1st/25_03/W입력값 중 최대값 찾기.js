var cnt = 0
var value = []

let input = document.getElementById( "numInput" );
input.addEventListener( "keydown", function ( event ) {
    console.log( event.key );
    if( event.key === "Enter" ) {
        addNumber();
    }
});

function addNumber() {
    var input = document.getElementById( "numInput" ).value;
    value.push(input);

    if( input.trim() !== "" ) {
        let p = document.createElement( "p" );
        document.getElementById( "maxResult" ).appendChild( p );
        document.getElementById( "numInput" ).value = "";
    }
}

function findMax() {
    let p = document.createElement( "p" );
    document.getElementById( "maxResult" ).appendChild( p );
    document.getElementById( "numInput" ).value = "";
    
    value.sort();
    let max =  value[value.length-1];
    p.innerText = "최댓값 :" + max;
}