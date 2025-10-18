function checkWindowSize() {

    if (window.innerWidth < 600) {
        document.body.style.backgroundColor = "#FFD6D6"; // 연한 빨강
    } else if (window.innerWidth < 800) {
        document.body.style.backgroundColor = "#FFF6D1"; // 연한 노랑
    } else if (window.innerWidth >= 800) {
        document.body.style.backgroundColor = "#D1F6FF"; // 연한 파랑
    }
}

window.addEventListener("resize", checkWindowSize);