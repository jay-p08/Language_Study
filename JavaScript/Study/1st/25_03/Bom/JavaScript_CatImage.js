getCatImage();
function getCatImage() {
    fetch( "https://api.thecatapi.com/v1/images/search/limit=10" )
    .then( response => response.json() )
    .then(data => {
        console.log(data);
        document.getElementById('cat-img').src = data[0].url;
    });
}