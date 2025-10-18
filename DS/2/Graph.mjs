class Vertex
{
    constructor( value )
    {
        this.value = value;
        this.adjacent_Vertices = [];
    } // constructor()

    addAdjacentVertex( vertex )
    {
        this.adjacent_Vertices.push( vertex );
    } // addAdjacentVertex()
    removeAdjacentVertex( vertex )
    {
        for( let i = 0 ; i < this.adjacent_Vertices.length ; i++ )
        {
            if( this.adjacent_Vertices[i] == vertex )
            {
                this.adjacent_Vertices.splice( i, 1 );
                break;
            } // if
        } // for
    } // removeAdjacentVertex()
} // Vertex

let ben = new Vertex( "Ben" );
let jake = new Vertex( "jake" );
let joy = new Vertex( "joy" );
let ivy = new Vertex( "ive" );
let Elin = new Vertex( "Elin" );
let anna = new Vertex( "anna" );
let david = new Vertex( "david" );

ben.addAdjacentVertex( jake );
jake.addAdjacentVertex( ben );
ivy.addAdjacentVertex( ben );
ivy.addAdjacentVertex( joy );
joy.addAdjacentVertex( ben );
joy.addAdjacentVertex( ivy );
anna.addAdjacentVertex( ben );
anna.addAdjacentVertex( david );
anna.addAdjacentVertex( Elin );
Elin.addAdjacentVertex( anna );
Elin.addAdjacentVertex( ivy );
david.addAdjacentVertex( anna );

console.log( anna.adjacent_Vertices );

anna.removeAdjacentVertex( david );

console.log( anna.adjacent_Vertices );