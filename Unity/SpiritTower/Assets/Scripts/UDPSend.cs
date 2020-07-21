﻿using UnityEngine;
using System.Collections;
using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

public class UDPSend : MonoBehaviour
{
    private static int localPort;
    [SerializeField] Rigidbody player;

    // prefs
    private static string IP = "127.0.0.1";  // define in init
    public static int port = 54000;  // define in init

    // "connection" things
    static IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
    static UdpClient client = new UdpClient();
    // receiving Thread
    static Thread receiveThread = new Thread(new ThreadStart(ReceiveData));

    // gui
    string strMessage = "";

    // infos
    public string lastReceivedUDPPacket = "";
    public string allReceivedUDPPackets = ""; // clean up this from time to time!

    // sendData
    public static void sendString(string message)
    {
        try
        {
            // Daten mit der UTF8-Kodierung in das Binärformat kodieren.
            byte[] data = Encoding.UTF8.GetBytes(message);
            // Den message zum Remote-Client senden.
            client.Send(data, data.Length, remoteEndPoint);
            //receiveThread = new Thread(new ThreadStart(ReceiveData));
            receiveThread.IsBackground = true;
            receiveThread.Start();

        }
        catch (Exception err)
        {
            print(err.ToString());
        }
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
                string text = Encoding.UTF8.GetString(dato);
                // lo que recibe del servidor
                //print(">> " + text);
            }
            catch (Exception err)
            {
                print(err.ToString());
            }
        }
    }

}