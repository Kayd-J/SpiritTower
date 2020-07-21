using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Net.NetworkInformation;
using UnityEngine;
using Debug = UnityEngine.Debug;


public class PlayableMap : MonoBehaviour
{
    //Ingame Info
    private const float TileSize = 1.0f;
    private const float TileOfset = 0.5f;
    private int mapPlayerPosX = -1;
    private int mapPlayerPosY = -1;
    private int InvertYPlayer = 19;
    [SerializeField] Rigidbody player;
    //Comunication Info
    public Player jugador = Movement.informacion;
    private Wrapper information;


    void Awake() {  

        //while (UDPSend.messageSv==null) {
            //print("esperando respuesta");
        //}

        //information = JsonHelper.FromJson(UDPSend.messageSv);
        
    }

    void Start(){}
    void conecction() {
        //Envio mensajes______________

        //juntar a todos los enemigos del nivel en una sola array

        Enemies[] bruh = new Enemies[2];
        bruh[0] = new Enemies();
        bruh[1] = new Enemies();

        string playerToJason = JsonHelper.ToJson(jugador, bruh, true);
        print(playerToJason);
        UDPSend.sendString(playerToJason);

        //Recibo mensajes______________

        //if (UDPSend.messageSv !=null){ information = JsonHelper.FromJson(UDPSend.messageSv); }



        //Player actualPlayer = informacion.Player;

        //Enemies[] deserializados = informacion.Enemies;

        //Debug.Log(actualPlayer.Health);
        //Debug.Log(actualPlayer.Score);
        //Debug.Log(actualPlayer.Shield);

        //for (int i = 0; i < deserializados.Length; i++)
        //{
        //    Debug.Log(deserializados[i].ID);
        //}
    }

    // Update is called once per frame
    void Update()
    {
        PlayerPos();
        //DrawBoard();

    }

    void FixedUpdate() {
        jugador.posX = mapPlayerPosX;
        jugador.posY = InvertYPlayer - mapPlayerPosY;
        conecction();

    }
    // Visualizacion de la matriz
    private void DrawBoard() {
        Vector3 widthLine = Vector3.right * 20;
        Vector3 heigthLine = Vector3.forward * 20;

        for (int i = 0; i <=20; i++) {
            Vector3 start = Vector3.forward * i;
            Debug.DrawLine(start, start + widthLine);
            for (int g = 0; g <= 20; g++)
            {
                start = Vector3.right * g;
                Debug.DrawLine(start, start + heigthLine);
            }
        }

        if (mapPlayerPosX >=1 && mapPlayerPosY >=1)
        {
            Debug.DrawLine(
                Vector3.forward * mapPlayerPosY + Vector3.right * mapPlayerPosX,
                Vector3.forward * (mapPlayerPosY + 1) + Vector3.right * (mapPlayerPosX + 1));
        }
    }

    private void PlayerPos() {
        if (player.transform.position.x <19 && player.transform.position.z < 19){
            mapPlayerPosX = (int)player.transform.position.x;
            mapPlayerPosY = (int)player.transform.position.z;
        }
       else {
            mapPlayerPosX = -1;
            mapPlayerPosY = -1;
        }
    }
}
