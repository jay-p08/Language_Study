import { Queue } from "./../Queue.mjs"

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

function BFS( vertex )
{
    let queue = new Queue();
    let visited_Vertices = {};
    visited_Vertices[ vertex.value ] = true;
    queue.enqueue( vertex );
    while( queue.isEmpty() === false )
    {
        let currentVertex = queue.dequeue().data;
        console.log( `정점 >>> ${ currentVertex.value }` );
        for( let adjacent of currentVertex.adjacent_Vertices )
        {
            if( visited_Vertices[ adjacent.value ] )
            {
                continue;
            } // if
            else
            {
                visited_Vertices[ adjacent.value ] = true;
                queue.enqueue( adjacent );
            } // else
        } // for
    } // while
} // BFS()

let Ben = new Vertex( "Ben" );
let Ivy = new Vertex( "Ivy" );
let Joy = new Vertex( "Joy" );
let Jake = new Vertex( "Jake" );
let Anna = new Vertex( "Anna" );
let David = new Vertex( "David" );
let Elin = new Vertex( "Elin" );
let Owen = new Vertex( "Owen" );

Ben.addAdjacentVertex( Ivy );
Ben.addAdjacentVertex( Jake );
Ben.addAdjacentVertex( Anna );
Ben.addAdjacentVertex( David );

Ivy.addAdjacentVertex( Ben );
Ivy.addAdjacentVertex( Joy );

Joy.addAdjacentVertex( Ivy );
Joy.addAdjacentVertex( Jake );

Jake.addAdjacentVertex( Ben );
Jake.addAdjacentVertex( Joy );

Anna.addAdjacentVertex( Ben );

David.addAdjacentVertex( Ben );
David.addAdjacentVertex( Elin );

Elin.addAdjacentVertex( David );
Elin.addAdjacentVertex( Owen );

Owen.addAdjacentVertex( Elin );

BFS( Elin )