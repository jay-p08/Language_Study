function checkWindowSize() {
    document.getElementById("sad").innerText = window.innerWidth;

    if (window.innerWidth < 800) {
        console.log("가로길이가 500이 안되는 군요");
    } else {
        console.log("가로길이가 500이 넘는군요");
    }
}

window.addEventListener("resize", checkWindowSize);

let timeid = setInterval(() => {
    console.log("1초");
}, 1000);
clearInterval( timeid )