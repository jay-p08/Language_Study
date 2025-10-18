ChangeBg = ( color ) => document.querySelector( "#result" ).style.backgroundColor = color;

function hideElement() {
    document.getElementById("box").style.display = "none"
}
function noHideElement() {
    document.getElementById("box").style.display = ""
}
function changeRandomColor() {
    let colors = ["red", "blue", "green", "yellow", "purple", "pink"];
    let randomcolors = colors[Math.floor(Math.random()*colors.length)];

    document.body.style.backgroundColor = randomcolors;
}