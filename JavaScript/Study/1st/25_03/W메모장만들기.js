function SaveNote() {
    localStorage.setItem('note', document.getElementById( "note" ).value);
}

document.getElementById( "note" ).value = localStorage.getItem('note');