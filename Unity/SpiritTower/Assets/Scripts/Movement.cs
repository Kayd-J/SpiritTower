using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public float JumpVel;
    public Rigidbody rigidbody;
    float axisX;
    float axisY;
    Vector3 axis;

    public static Player informacion =new Player();

    //Player information

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        axisX = Input.GetAxis("Horizontal");
        axisY = Input.GetAxis("Vertical");
        axis = new Vector3(axisX,0,axisY);

        if (Input.GetButtonDown("Jump")) {
            rigidbody.velocity = new Vector3(axisX, JumpVel, axisY);

        }
        
    }

    void FixedUpdate() {
        rigidbody.MovePosition(rigidbody.position + axis);
    }
}
