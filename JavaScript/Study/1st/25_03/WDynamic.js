let input = prompt( "생성할 셀의 개수를 입력하세요" ).trim();
let numCells = parseInt( input );

if ( isNaN( numCells ) || numCells <= 0 ) {
    alert( "올바른 숫자를 입력하세요" );
}

let table = document.createElement( "table" );
table.style.borderCollapse = "5px";
table.style.margin = "20px auto";
table.style.border = "1px solid black";

let cols = Math.ceil( Math.sqrt( numCells ) );
let rows = Math.ceil( numCells / cols );

let count = 0;
for ( let i = 0; i < rows; i++ ) {
    let tr = document.createElement( "tr" );
    for ( let j = 0; j < cols; j++ ) {
        let td = document.createElement( "td" );
        td.style.border = "1px solid black";
        td.style.padding = "20px";
        td.style.textAlign = "center";
        td.style.width = "20px";
        td.style.height = "20px";
        if ( count < numCells ) {
            td.textContent = count + 1;
        }
        tr.appendChild( td );
        count++;
    }
    table.appendChild( tr );
}

document.body.appendChild( table );