var currentHours=1;
var currentMinutes=0;
var currentSeconds=0;

var data_value      = new Array(3);
var time_received   = 0;

function clock(){

    if (currentSeconds < 59){
        currentSeconds=currentSeconds+1;
    }
    else{
        currentSeconds=0;

        if (currentMinutes < 59){
            currentMinutes=currentMinutes+1;
        }
        else{
            currentMinutes=0;

            // 12 hour clock, for now until i figure out what rtc module uses
            if (currentHours < 12){
                currentHours=currentHours+1;
            }
            else{
                currentHours=1;
            }
        }
    }

    // Update clock
    hour.innerHTML      = currentHours;
    minute.innerHTML    = currentMinutes;
    second.innerHTML    = currentSeconds;

    setTimeout("clock()", 1000);
}


function syncRequest(url) {
    var http_request = false;

    url = url + "?sid=" + Math.random();

    time_received = 1;
    if (window.XMLHttpRequest) { // Mozilla, Safari,...
        http_request = new XMLHttpRequest();
        if (http_request.overrideMimeType) {
            http_request.overrideMimeType('text/xml');
        }
    }
    else if (window.ActiveXObject) { // IE
        try {
            http_request = new ActiveXObject("Msxml2.XMLHTTP");
        }
        catch (e) {
            try {
                http_request = new ActiveXObject("Microsoft.XMLHTTP");
            }
            catch (e) {}
        }
    }

    if (!http_request) {
        alert('Giving up :( Cannot create an XMLHTTP instance');
        return false;
    }

    http_request.onreadystatechange = function() { syncClockContents(http_request); };
    http_request.open('GET', url, true);
    http_request.send(null);
}

function syncClockContents(http_request) {
    if (http_request.readyState == 4) {
        if (http_request.status == 200) {
            syncClock(http_request.responseText);
            time_received = 0;
        }
        else {
            time_received = 0;
//          alert('There was a problem with the request.');
//          alert( http_request.status );
//
        }
    }
}


function syncClock(data) {
    var parsed = data.split( "\n" );

    data_value[0]   = parsed[0];
    data_value[1]   = parsed[1];
    data_value[2]   = parsed[2];

    currentHours    = data_value[0];
    currentMinutes  = data_value[1];
    currentSeconds  = data_value[2];

}


window.onload=syncRequest("rtcdata.cgi");
window.onload=clock;
