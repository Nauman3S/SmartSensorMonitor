
String macAddress = "";
String Alive = "YES";
String Counter = "0";
String Calibration = "0";
String Tank1 = "0";
String Tank2 = "0";
String getCounter()
{
    return Counter;
}

String getCalibration()
{
    return Calibration;
}

String getTank1()
{
    return Tank1;
}

String getTank2()
{
    return Tank2;
}

String getSensorData(String dataVal)
{
    if (dataVal.indexOf("counter") >= 0)
    {
        String v = ss.StringSeparator(dataVal, ':', 1);
        Counter = v;
    }
    else if (dataVal.indexOf("calibration") >= 0)
    {
        String v = ss.StringSeparator(dataVal, '=', 1);
        Calibration = v;
    }
    else if (dataVal.indexOf("tank 1") >= 0)
    {
        String v = ss.StringSeparator(dataVal, ':', 1);
        Tank1 = v;
    }
    else if (dataVal.indexOf("tank 2") >= 0)
    {
        String v = ss.StringSeparator(dataVal, ':', 1);
        Tank2 = v;
    }
}