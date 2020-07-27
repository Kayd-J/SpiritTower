using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public Rigidbody rigidbody;
    float axisX;
    float axisY;
    [SerializeField] float speed;
    Vector3 axis;
    //Player information
    public static Player informacion =new Player();
    // Update is called once per frame
    void Update(){

        //movement
        axisX = Input.GetAxisRaw("Horizontal")*speed;
        axisY = Input.GetAxisRaw("Vertical")*speed;
        axis = new Vector3(axisX,0,axisY);

        if (Input.GetMouseButtonDown(0))
        {
            OpenItem();
        }
        if (Input.GetMouseButtonDown(1))
        {
            print("ataco");
        }

    }

    void FixedUpdate() {
        if (axis.magnitude>= 0.1f)
        {
            rigidbody.velocity=axis;
        }
        transform.LookAt(rigidbody.position + axis);
        getDirection();

    }

    void getDirection() {

        float y = rigidbody.rotation.y;
        float w = rigidbody.rotation.w;

        if ((y == 0 && w == 1) || ((0f<y && y <= 0.4f) && w >= 0.7f) || ( (y<-0.3 && y>-0.7) && w <1))
        {
            informacion.Direction = "N";
        }
        if ((y == 1 && w == 0) || (y >= 0.9f && w <= 0.4f))
        {
            informacion.Direction = "S";
        }
        if ((y >= 0.7f && w >= 0.7f))
        {
            informacion.Direction = "E";
        }
        if ((y <= -0.7f && w >= 0.7f))
        {
            informacion.Direction = "O";
        }
    }

    void OpenItem() {
        int itemPosX=-1;
        int itemPosY=-1;
        switch (informacion.Direction) {
            case "N":
                itemPosX = (int)rigidbody.transform.position.x;
                itemPosY = 19 - ((int)rigidbody.transform.position.z + 1);
                break;
            case "E":
                itemPosX = (int)rigidbody.transform.position.x+1;
                itemPosY = 19-(int)rigidbody.transform.position.z;
                break;
            case "S":
                itemPosX = (int)rigidbody.transform.position.x;
                itemPosY = 19-((int)rigidbody.transform.position.z - 1);
                break;
            case "O":
                itemPosX = (int)rigidbody.transform.position.x - 1;
                itemPosY = 19-(int)rigidbody.transform.position.z;
                break;
            default:
                break;

        }
        if (itemPosX != -1) {
            for (int i = 0; i < Spawner.objetosInstanciados.Count; i++)
            {
                print(itemPosX);
                print(itemPosY);

                if (Spawner.objetosInstanciados[i].information.posX == itemPosX && Spawner.objetosInstanciados[i].information.posY == itemPosY) {
                    Spawner.objetosInstanciados[i].information.DEATH = true;
                    //____/change the animatorthingy\______
                    //Spawner.onjetosInstanciados[i].entity
                }
            }
        }
        
    }
}


