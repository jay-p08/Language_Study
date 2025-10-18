// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/12.1.0/firebase-app.js";
import { getFirestore, doc, setDoc } from "https://www.gstatic.com/firebasejs/12.1.0/firebase-firestore.js";

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
await setDoc(doc(db, "cities", "서울"), {
    name: "서울",
    country: "대한민국"
});