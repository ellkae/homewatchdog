    

function parse_vars(data) {
        var parsed = data.split( "\n" );

        data_value[0]           = parsed[0];
        data_value[1]           = parsed[1];
        data_value[2]           = parsed[2];

        hour.innerHTML  =   "<h1>"+data_value[0]+"</h1>";
        minute.innerHTML        = "<h1>"+data_value[1]+"</h1>";
        second.innerHTML        = "<h1>"+data_value[2]+"</h1>";

}

function loop() {
        if (!data_received)
                makeRequest("rtcdata.cgi");

        setTimeout("loop()", 1000);
}

window.onload=loop;

