
function VisitCount() {
    var Count = 1;
    var p = document.createElement("p");

    localStorage.setItem('visitCount', JSON.stringify(Count))
    document.getElementById("visitCount").appendChild(p);
    p.innerText = localStorage.getItem(Count += 1)
}