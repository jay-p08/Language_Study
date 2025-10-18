function HanoiTower( count, from, to, temp ) {
    if( count == 0 ) return;
    HanoiTower( count - 1, from, temp, to );
    console.log( `${ count } ${ from } ===> ${ to } `);
    HanoiTower( count - 1, temp, to, from );
}

console.log( HanoiTower( 4, 'A', 'C', 'B' ) )