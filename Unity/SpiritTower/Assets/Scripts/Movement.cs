using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class Movement : MonoBehaviour
{
    float JumpVel= 1f;
    public Rigidbody rigidbody;
    float axisX;
    float axisY;
    Vector3 axis;
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
