let input = document.getElementById( "wordInput" );
input.addEventListener( "keydown", function ( event ) {
    console.log( event.key );
    if( event.key === "Enter" ) {
        reverseText();
    }
});

function reverseText() {
    var input = document.getElementById( "wordInput" ).value;

    if( input.trim() !== "" ) {
        let p = document.createElement( "p" );
        document.getElementById( "reversed" ).appendChild( p );
        document.getElementById( "wordInput" ).value = "";

        p.innerText = input.split("").reverse().join("");
    }
}