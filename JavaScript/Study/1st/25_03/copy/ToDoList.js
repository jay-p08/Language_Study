let todoArrayObj = JSON.parse(localStorage.getItem("todoArray"));
let todoArray = todoArrayObj ? todoArrayObj : [];

loadAll();

function loadAll() {
    document.getElementById("itemList").innerHTML = "";
    todoArray.forEach((element, idx) => {
        console.log("2", element.text);
        let input = element.text;

        if (!validInput(input)) return;
        let li = document.createElement("li");
        let span = document.createElement("span");
        span.innerText = input;
        li.dataset.index = idx;

        li.addEventListener("click", function () {
            if (li.classList.contains("done")) {
                li.classList.remove("done");
            } else {
                li.classList.add("done");
            }
        });

        span.addEventListener("dblclick", function () {
            const input = prompt("수정 데이터를 입력하세요.");
            if (!validInput(input)) return;
            span.innerText = input;
        });

        let deleteBtn = document.createElement("button");
        deleteBtn.innerText = '삭제';

        deleteBtn.addEventListener("click", function () {
            todoArray.splice(li.dataset.index, 1);
            localStorage.setItem("todoArray", JSON.stringify(todoArray));
            loadAll();

        });

        li.appendChild(span);
        li.appendChild(deleteBtn);
        document.getElementById("itemList").appendChild(li);

    });
} // loadAll

let input = document.getElementById("userInput");
input.addEventListener("keydown", function (event) {
    if (event.key === "Enter") {
        addToList();
    }
}); // Enter

function validInput(data) {
    if (data.trim() == "") {
        alert("입력 >>> ")
        return false;
    }
    return true;
} // validInput

function addToList() {
    let input = document.getElementById("userInput").value;
    if (!validInput(input)) return;
    document.getElementById("userInput").value = "";

    let todoObj = { text: input, done: false };
    todoArray.push(todoObj);
    localStorage.setItem("todoArray", JSON.stringify(todoArray));

    loadAll();
} // addToList