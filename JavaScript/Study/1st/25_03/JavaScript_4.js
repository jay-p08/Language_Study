document.addEventListener( "mousemove", function( event ) {
    document.getElementById("coor").innerText = `X : ${ event.clientX }, Y : ${ event.clientY }`;
} );

function RemoveItem( Element ) {
    Element.remove();
}