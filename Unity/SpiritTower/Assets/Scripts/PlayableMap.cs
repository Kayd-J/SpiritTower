using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Net.NetworkInformation;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Globalization;
using System;


public class PlayableMap : MonoBehaviour
{
    //Ingame Info
    private const float TileSize = 1.0f;
    private const float TileOfset = 0.5f;
    private int mapPlayerPosX = -1;
    private int mapPlayerPosY = -1;
    private int InvertYPlayer = 19;

    public int lvlcounter;

    public int finalX = 18;
    public int finalY = 5;
    [SerializeField] Rigidbody player;
    [SerializeField] GameObject spawner;
    public Slider slider;
    public Text ScoreText;

        
    public static Vector3 firstPos=new Vector3(1.5f, 0.0f, 1.5f);

    //Comunication Info
    public Player jugador = Movement.informacion;
    private Wrapper information;

    //Spawner spawner = new Spawner();

    void conection() {
        //Envio mensajes______________
        //juntar a todos los enemigos del nivel en una sola array

        Enemies[] bruh = new Enemies[2];
        bruh[0] = new Enemies();
        bruh[1] = new Enemies();

        string playerToJason = JsonHelper.ToJson(jugador, bruh, true);
        //print(playerToJason);
        UDPSend.sendString(playerToJason);

        Movement.informacion.Sword = false;


        if (mapPlayerPosX == finalX && 19-mapPlayerPosY == finalY) {
            SceneManager.LoadScene(++lvlcounter);
        }
        

        //Recibo mensajes______________

        //UDPSend.messageSV = "{\"Player\": {\"Health\": 1, \"Score\": 100, \"Shield\": false, \"Sword\": true, \"posX\": false, \"posY\": true }, \"Enemies\": [{\"ID\": \"B\",\"COLOR\": \"g\", \"DEATH\": false, \"posX\": 3, \"posY\": 2 } ], \"Objects\": [ { \"ID\": \"K\", \"DEATH\": false, \"posX\": 2, \"posY\": 3 }, {\"ID\": \"J\", \"DEATH\": false, \"posX\": 2, \"posY\": 2 } ] }"; 

        if (UDPSend.messageSV != null)
        {
            information = JsonHelper.FromJson(UDPSend.messageSV);
            //Player actualPlayer = information.Player;
            //if (slider.value == 0 ||  ( 0> information.Player.Score))
            //{
            //    player.transform.position = firstPos;
            //}
            slider.value = information.Player.Health;
            ScoreText.text = information.Player.Score.ToString();
            Enemies[] deserializados = information.Enemies;
            Objects[] objetosdeserializados = information.Objects;

            spawner.GetComponent<Spawner>().CheckOrMove(deserializados, objetosdeserializados);
        }
    }

    // Update is called once per frame
    void Update()
    {
        //DrawBoard();
    }

    void FixedUpdate() {
        PlayerPos();
        jugador.posX = mapPlayerPosX;
        jugador.posY = InvertYPlayer - mapPlayerPosY;
        conection();
       
    }

    // Visualizacion de la matriz
    /*private void DrawBoard() {
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
    }*/

    private void PlayerPos() {
        if (player.transform.position.x <19 && player.transform.position.z < 19){
            mapPlayerPosX = (int)player.transform.position.x;
            mapPlayerPosY = (int)player.transform.position.z;
        }
        else
        {
            mapPlayerPosX = -1;
            mapPlayerPosY = -1;
        }
    }
    
}
