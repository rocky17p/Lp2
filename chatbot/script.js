function openChat() {
    document.getElementById("chatWindow").style.display = "block";
}

function closeChat() {
    document.getElementById("chatWindow").style.display = "none";
}

function sendMessage() {

    let input = document.getElementById("userInput").value.toLowerCase();
    let chat = document.getElementById("chatBody");

    if(input == "") return;

    chat.innerHTML += "<p><b>You:</b> " + input + "</p>";

    let reply;

    if(input.includes("doctor"))
        reply = "We have Cardiologist, Orthopedic and General Physician.";

    else if(input.includes("appointment") || input.includes("book"))
        reply = "Book appointment at reception or call 1234567890.";

    else if(input.includes("emergency"))
        reply = "Emergency service available 24/7. Call 108.";

    else if(input.includes("time") || input.includes("timing"))
        reply = "Hospital timing is 9 AM to 8 PM.";

    else if(input.includes("location") || input.includes("address"))
        reply = "City Hospital is near Main Square, Pune.";

    else if(input.includes("fee") || input.includes("cost"))
        reply = "Consultation fee starts from Rs.300.";

    else if(input.includes("exit"))
        reply = "Thank you! Stay healthy.";

    else
        reply = "Sorry, I did not understand.";

    chat.innerHTML += "<p><b>Bot:</b> " + reply + "</p>";

    document.getElementById("userInput").value = "";
}
