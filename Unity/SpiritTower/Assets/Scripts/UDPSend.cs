using UnityEngine;
using System.Collections;
using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

public class UDPSend : MonoBehaviour
{
    private static int localPort;
    // prefs
    private static string IP = "127.0.0.1";  // define in init
    public static int port = 54000;  // define in init
    // "connection" things
    static IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
    static UdpClient client = new UdpClient();
    // receiving Thread
    static Thread receiveThread = new Thread(new ThreadStart(ReceiveData));
    // gui
    public static string messageSV;
    // sendData
    public static void sendString(string message)
    {
        try
        {
            // Daten mit der UTF8-Kodierung in das Binärformat kodieren.
            byte[] data = Encoding.UTF8.GetBytes(message);
            // Den message zum Remote-Client senden.
            client.Send(data, data.Length, remoteEndPoint);
            receiveThread.IsBackground = true;
            receiveThread.Start();
        }
        catch (Exception err){}
    }
    // receive data thread
    private static void ReceiveData()
    {
        while (true)
        {
            try
            {
                IPEndPoint anyIP = new IPEndPoint(IPAddress.Any, 54001);
                byte[] dato = client.Receive(ref anyIP);
                messageSV = Encoding.UTF8.GetString(dato);
                print(">> " + messageSV);
            }
            catch (Exception err){}
        }
    }

}