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
    private const float TileSize = 1.0f;
    private const float TileOfset = 0.5f;
    private int mapPlayerPosX = -1;
    private int mapPlayerPosY = -1;

    private int InvertYPlayer = 19;

    [SerializeField] Rigidbody player;

    private string[,] GameMatrix;


    void Awake() { 

        //Aqui es donde debo meter la matrix
    
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        PlayerPos();
        DrawBoard();
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

        if (mapPlayerPosX >=0 && mapPlayerPosY >=0)
        {
            Debug.DrawLine(
                Vector3.forward * mapPlayerPosY + Vector3.right * mapPlayerPosX,
                Vector3.forward * (mapPlayerPosY + 1) + Vector3.right * (mapPlayerPosX + 1));
        }
    }

    private void PlayerPos() {
        if (player.transform.position.x <20 && player.transform.position.z < 20){
            mapPlayerPosX = (int)player.transform.position.x;
            mapPlayerPosY = (int)player.transform.position.z;
        }
       else {
            mapPlayerPosX = -1;
            mapPlayerPosY = -1;
        }
    }
}
