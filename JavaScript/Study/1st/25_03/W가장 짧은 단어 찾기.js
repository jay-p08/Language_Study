let input = document.getElementById( "wordAdd" );
var value = []

input.addEventListener( "keydown", function ( event ) {
    console.log( event.key );
    if( event.key === "Enter" ) {
        addWord();
    }
});

function addWord() {
    var input = document.getElementById( "wordAdd" ).value;
    value.push( input );

    document.getElementById( "wordAdd" ).value = "";
}

function shortestWord() {
    let p = document.createElement("p");

    if (value.length === 0) {
        p.innerText = "단어가 없습니다.";
    } else {
        let shortest = value.reduce((a, b) => a.length <= b.length ? a : b);
        p.innerText = "가장 짧은 단어 : " + shortest;
    }

    document.getElementById("shortResult").appendChild(p);
    document.getElementById("wordAdd").value = "";
}
