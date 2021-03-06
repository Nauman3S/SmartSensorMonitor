void cmotsValues();
void handleRoot();
void sendRedirect(String uri);
void handleGPIO();

void handleRoot()
{
    String page = PSTR(
        "<html>"
        "</head>"
        "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
        "<style type=\"text/css\">"
        "table, th, td {"
        "  border: 1px solid black;"
        "}"
        "table.center {"
        "margin-left: auto; "
        "margin-right: auto;"
        "}"
        "body {"
        "-webkit-appearance:none;"
        "-moz-appearance:none;"
        "font-family:'Arial',sans-serif;"
        "text-align:center;"
        "}"
        ".menu > a:link {"
        "position: absolute;"
        "display: inline-block;"
        "right: 12px;"
        "padding: 0 6px;"
        "text-decoration: none;"
        "}"
        ".button {"
        "display:inline-block;"
        "border-radius:7px;"
        "background:#73ad21;"
        "margin:0 10px 0 10px;"
        "padding:10px 20px 10px 20px;"
        "text-decoration:none;"
        "color:#000000;"
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<div class=\"menu\">" AUTOCONNECT_LINK(BAR_24) "</div>"
                                                        "Smart Sensor Monitor Device<br>");

    page += String(F("<h1>Smart Sensor Monitor Device</h1>"));

    page += String(F("<h2>MAC Address: "));
    page += ss.getMacAddress();
    page += String(F("</h2>"));

    page += String(F("<h4>Counter: "));
    page += getCounter();
    page += String(F("</h4>"));

    page += String(F("<h4>Calibration: "));
    page += getCalibration();
    page += String(F("</h4>"));

    page += String(F("<h4>Tank 1: "));
    page += getTank1();
    page += String(F("</h4>"));

    page += String(F("<h4>Tank 2: "));
    page += getTank2();
    page += String(F("</h4>"));

    page += String(F("<p><br><a class=\"button\" href=\"/\">Refresh</a></p>"));
    page += String(F("</body></html>"));

    server.send(200, "text/html", page);
}

void redirectToHome()
{
    server.sendHeader("Location", "/", true);
    server.send(302, "text/plain", "");
    // server.client().stop();
}
void dataTable()
{
    redirectToHome();
}

void sendRedirect(String uri)
{
    server.sendHeader("Location", uri, true);
    server.send(302, "text/plain", "");
    server.client().stop();
}
void handleCON()
{
    String argV = String(server.arg("v"));
    if (argV == "wifi")
    {
        connectionMode = "WiFi";
    }
    else if (argV == "gprs")
    {
        connectionMode = "GPRS";
    }

    redirectToHome();
}
void handleDEV()
{
    String argV = String(server.arg("v"));
    Serial.println(argV);
    selectedDeviceIndex = argV.toInt();
    redirectToHome();
}
