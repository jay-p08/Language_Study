// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/12.1.0/firebase-app.js";
import { getFirestore, doc, setDoc, collection, addDoc, getDocs, updateDoc, deleteDoc } from "https://www.gstatic.com/firebasejs/12.1.0/firebase-firestore.js";

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyDo9LK7SXRHVzp_wm5axWi4S-cCXh6wUi8",
    authDomain: "np32-1e324.firebaseapp.com",
    projectId: "np32-1e324",
    storageBucket: "np32-1e324.firebasestorage.app",
    messagingSenderId: "253413086097",
    appId: "1:253413086097:web:104d6d3baa26bb9b614030",
    measurementId: "G-1Y3WS304NM"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Initialize Cloud Firestore and get a reference to the service
const db = getFirestore(app);


// Add a new document in collection "cities"
// await setDoc(doc(db, "cities", "서울"), {
//     name: "서울",
//     country: "대한민국"
// });
const addForm = document.getElementById( "addForm" );
const itemInput = document.getElementById( "itemInput" );
const itemList = document.getElementById( "itemList" );
const itemColRef = collection( db, "items" );
const ReadItems = document.getElementById( "rItems" );

addForm.addEventListener( "submit", async( e ) => {
    e.preventDefault();
    console.log( "추가버튼 누름" );
    console.log( itemInput.value );
    if( itemInput.value.trim() ) {
        await addDoc( itemColRef, { text : itemInput.value } );
        itemInput.value = "";
        renderItems();
    } else {
        alert( "값을 넣고 추가하도록" );
    }
});

async function renderItems() {
    itemList.innerHTML = "";
    const rItems = await getDocs( itemColRef );
    rItems.forEach( element => {
        console.log( "값 ", element.data().text );
        const li = document.createElement( "li" );
        li.textContent = element.data().text;
        itemList.appendChild( li );
        const deleteBtn = document.createElement( "button" );
        deleteBtn.innerText = "삭제";
        li.appendChild( deleteBtn );
        const updateBtn = document.createElement( "button" );
        updateBtn.innerText = "수정";
        li.appendChild( updateBtn );
        
        deleteBtn.onclick = async() => {
            const docRef = doc( db, "items", element.id );
            await deleteDoc( docRef );
            renderItems();
        }
        updateBtn.onclick = async() => {
            const updateText = prompt( "수정할 내용을 입력하세요", element.data().text );
            if( updateText && updateText.trim() ) {
                const docRef = doc( db, "items", element.id );
                await updateDoc( docRef, { text : updateText } );
                renderItems();
            } else {
                alert( "수정할 내용을 입력하세요" );
            }
        }
    });
}
renderItems();

