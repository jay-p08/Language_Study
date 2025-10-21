import figlet from "figlet";

async function doStuff() {

  const text = await figlet.text("Hello World!!");

  console.log(text);

  const text2 = await figlet.text("hello~?");

  console.log(text2);

}

doStuff();