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

    private void DrawBoard() {
        Vector3 widthLine = Vector3.right * 10;
        Vector3 heigthLine = Vector3.forward * 10;

        for (int i = 0; i <= 10; i++) {
            Vector3 start = Vector3.forward * i;
            Debug.DrawLine(start, start + widthLine);
            for (int g = 0; g <= 10; g++)
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
        if (!Camera.main)
            return;
        RaycastHit hit;
        //Este if debe dar la posicion del jugador en la matriz para poder ser procesada
        if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out hit, 25.0f, LayerMask.GetMask("MapaNivel")))
        {
            mapPlayerPosX = (int)hit.point.x;
            mapPlayerPosY = (int)hit.point.z;
            //Debug.Log(selectionx);
        }
        else {
            mapPlayerPosX = -1;
            mapPlayerPosY = -1;
        }
    }
}
