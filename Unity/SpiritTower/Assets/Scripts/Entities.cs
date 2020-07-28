using System;
using UnityEngine;
[Serializable]
public class Player
{
    public int Health=5;
    public int Score=0;
    public string Direction = "N";
    public int posX=2;
    public int posY=3;
    public bool Shield=false;
    public bool Sword=false;
}

[Serializable]
public class Enemies
{
    public string ID = "A";
    public string COLOR;
    public bool DEATH = false ;
    public int posX;
    public int posY ;
}

[Serializable]
public class Objects
{
    public string ID = "A";
    public bool DEATH = false;
    public int posX;
    public int posY;
}

[Serializable]
public class Boss
{
    public int Health = 100;
    public int Score = 10;
    public int posX = 2;
    public int posY = 3;
    public bool Shield = false;
    public bool Sword = true;
}


public class MapEnemy
{
    public GameObject entity;
    public Enemies information;
}

public class Objecto
{
    public GameObject entity;
    public Objects information;

}