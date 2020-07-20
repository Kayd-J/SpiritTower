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
    [SerializeField] Rigidbody player;

    // prefs
    private string IP;  // define in init
    public int port;  // define in init

    // "connection" things
    IPEndPoint remoteEndPoint;
    UdpClient client;
    // receiving Thread
    Thread receiveThread;

    // gui
    string strMessage = "";

    // infos
    public string lastReceivedUDPPacket = "";
    public string allReceivedUDPPackets = ""; // clean up this from time to time!

    // start from unity3d
    public void Start()
    {
        init();
    }

    // OnGUI
    void OnGUI()
    {
        Rect rectObj = new Rect(40, 380, 200, 400);
        GUIStyle style = new GUIStyle();
        style.alignment = TextAnchor.UpperLeft;

        // ------------------------
        // send it
        // ------------------------
        strMessage = GUI.TextField(new Rect(40, 420, 140, 20), strMessage);
        if (GUI.Button(new Rect(190, 420, 40, 20), "send"))
        {
            sendString("{\"Matrix\":\"[[0, 0, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1], [0, 1, 0, 1]]\",\"Player\":{\"Health\":100,\"Score\":10,\"Shield\":false,\"Sword\":true},\"Enemies\":{\"A\":{\"Alert\":true,\"Range\":2},\"B\":{\"Alert\":false,\"Range\":4}}}");
        }
    }

    // init
    public void init()
    {
        // define
        IP = "127.0.0.1";
        port = 54000;
        // ----------------------------
        // Senden
        // ----------------------------
        remoteEndPoint = new IPEndPoint(IPAddress.Parse(IP), port);
        client = new UdpClient();
    }


    // sendData
    private void sendString(string message)
    {
        print(message);
        try
        {
            // Daten mit der UTF8-Kodierung in das Binärformat kodieren.
            byte[] data = Encoding.UTF8.GetBytes(message);

            // Den message zum Remote-Client senden.
            client.Send(data, data.Length, remoteEndPoint);

            receiveThread = new Thread(
            new ThreadStart(ReceiveData));
            receiveThread.IsBackground = true;
            receiveThread.Start();

        }
        catch (Exception err)
        {
            print(err.ToString());
        }
    }

    // receive thread
    private void ReceiveData()
    {
        while (true)
        {
            try
            {
                // Bytes empfangen.
                IPEndPoint anyIP = new IPEndPoint(IPAddress.Any, 54001);
                byte[] dato = client.Receive(ref anyIP);

                // Bytes mit der UTF8-Kodierung in das Textformat kodieren.
                string text = Encoding.UTF8.GetString(dato);

                // Den abgerufenen Text anzeigen.
                print(">> " + text);

            }
            catch (Exception err)
            {
                print(err.ToString());
            }
        }
    }

}