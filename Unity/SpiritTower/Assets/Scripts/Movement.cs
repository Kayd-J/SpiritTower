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
    bool wallHit=false;
    //Player information
    public static Player informacion =new Player();
    // Update is called once per frame
    void Update(){
        axisX = Input.GetAxisRaw("Horizontal")*speed;
        axisY = Input.GetAxisRaw("Vertical")*speed;
        axis = new Vector3(axisX,0,axisY);
    }

    void FixedUpdate() {
        if (axis.magnitude>= 0.1f)
        {
            rigidbody.velocity=axis;
        }
        transform.LookAt(rigidbody.position + axis);
    }

}
