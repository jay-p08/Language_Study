const testScope = () => {
    var a = 10;
    let b = 20;
    const c = 30;

    if( true ) {
        var a = 50;
        let b = 60;
        const c = 70;
        console.log( a, b, c );
    }

    console.log( a, b, c );
}

testScope();