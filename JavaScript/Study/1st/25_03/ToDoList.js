localStorage.setItem( 'username', '너의 이름은?' );

const user = localStorage.getItem( 'username' );
console.log( user );

let input = document.getElementById( "userInput" );
input.addEventListener( "keydown", function ( event ) {
    console.log( event.key );
    if( event.key === "Enter" ) {
        AddToList();
    }
});

function AddToList() {
    var input = document.getElementById( "userInput" ).value;

    if( input.trim() !== "" ) {
        let li = document.createElement( "li" );
        let span = document.createElement( "span" );
        let deleteButton = document.createElement( "button" );

        // li.setAttribute( "ondblclick", "RemoveItem( this )" )
        span.innerText = input;
        deleteButton.innerText = '삭제';

        li.addEventListener( "click", function() {
            // li.classList.toggle( "done" )
            if ( li.classList.contains( "done" ) ) {
                li.classList.remove( "done" );
            } else {
                li.classList.add( "done" );
            }
        });

        span.addEventListener( "dblclick", function() {
            const input = prompt( "수정 데이터를 입력하세요." );
            if( input.trim() !== "" ) {
                span.innerText = input;
            }
        });

        deleteButton.addEventListener( "click", function() {
            li.remove();
        });

        li.appendChild( span );
        li.appendChild( deleteButton );
        document.getElementById( "ItemList" ).appendChild( li );
        document.getElementById( "userInput" ).value = "";
    }
}

function RemoveItem( Element ) {
    Element.remove();
}