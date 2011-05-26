/* 
 * Copyright (c) 2008 Freescale Semiconductor;
 * All Rights Reserved
 *
 * request.js
 *
 * */

function makeRequest(url) {
        var http_request = false;

        url = url + "?sid=" + Math.random();

        data_received = 1;
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

        http_request.onreadystatechange = function() { alertContents(http_request); };
        http_request.open('GET', url, true);
        http_request.send(null);
}

function alertContents(http_request) {
        if (http_request.readyState == 4) {
                if (http_request.status == 200) {
                        parse_vars(http_request.responseText);
                        data_received = 0;
                }
                else {
                        data_received = 0;
//                      alert('There was a problem with the request.');
//                      alert( http_request.status );
//
                }
        }
}

